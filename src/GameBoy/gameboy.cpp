#include "gameboy.h"

Gameboy::Gameboy(std::vector<uint8_t> bootRom, std::vector<uint8_t> gameRom)
{
    mmu = new gb::mmu(bootRom, gameRom);
    cpu = new gb::cpu(mmu);
    ppu = new gb::ppu(mmu);
    joypad = new gb::Joypad(mmu);
    serial = new gb::serial();

    //Set callback function for starting serial transfers
    mmu->SetJoypad(joypad);
    mmu->SerialTransferInitiate = std::bind(&gb::serial::StartSerialTransfer, serial);

    divTimer = std::chrono::high_resolution_clock::now();
}

//Main loop
void Gameboy::Run()
{
    ProcessDIV();

    uint32_t last_cycles = cpu->GetCycles();
    cpu->Step();
    gb::ppuMode currentMode = ppu->GetPPUMode();

    ProcessSerial(last_cycles);
    
    uint64_t cpu_cycles = (cpu->GetCycles() - last_cycles);
    ppu->Step(cpu_cycles);

    //Only poll window once per frame, when the ppu switches to V-Blank
    if(ppu->GetPPUMode() == gb::ppuMode::VERTICAL_BLANK && currentMode != gb::ppuMode::VERTICAL_BLANK)
    {
        ppu->window.PollWindowEvents();
    }
}

void Gameboy::ProcessDIV()
{
    //DIV Register
    constexpr float divRate = (1.0f/16384);
    std::chrono::high_resolution_clock::time_point divMeasurer = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(divMeasurer - divTimer);

    if(time_span.count() > divRate)
    {
        divTimer = std::chrono::high_resolution_clock::now();
        mmu->mem[0xFF04]++;
    }
}

void Gameboy::ProcessSerial(uint8_t last_cycles)
{
    if(serial->serialActive)
        serial->UpdateSerial(last_cycles);

    if(serial->requestInterrupt)
    {
        //Enable IF VBlank flag
        uint8_t IF = mmu->read(0xFF0F);
        IF = IF | BIT_3;
        mmu->write(0xFF0F, IF);

        serial->requestInterrupt = false;
    }
}

//Sets the cpu to the state after finishing the bootrom, used for logging CPU debug data
void Gameboy::SetupLog()
{
    cpu->a = 0x01;
    cpu->f = 0xB0;
    cpu->b = 0x00;
    cpu->c = 0x13;
    cpu->d = 0x00;
    cpu->e = 0xD8;
    cpu->h = 0x01;
    cpu->l = 0x4D;
    cpu->stack_pointer = 0xFFFE;
    cpu->program_counter = 0x100;

    cpu->debug = true;
}

void Gameboy::Reset()
{
    
}

void Gameboy::Quit()
{
    exit(-1);
}