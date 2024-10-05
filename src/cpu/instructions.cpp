#include "cpu/cpu.h"

void gb::cpu::NO_OP()
{
    //do nothing!
    cycles += 4;
}

//Load the immediate 16 bit value into the HL register
void gb::cpu::LD_HL_D16()
{
    uint8_t lsb = memory->read(program_counter++);
    uint8_t msb = memory->read(program_counter++);

    uint16_t value = (msb << 8) | lsb;
    SetComboRegister(HL, value);

    cycles += 12;

    PrintRegister(gb::H);
    PrintRegister(gb::L);
}

//Load the immediate 16 bit value into the stack pointer register
void gb::cpu::LD_SP_D16()
{
    uint8_t lsb = memory->read(program_counter++);
    uint8_t msb = memory->read(program_counter++);

    uint16_t value = (msb << 8) | lsb;
    stack_pointer = value;

    cycles += 3;
}

//Load to the address specified by HL, data from A, decrement HL by 1 afterwards
void gb::cpu::LD_HL_DEC_A()
{
    uint16_t addr = GetComboRegister(HL);

    memory->write(addr, a);

    SetComboRegister(HL, addr - 1);
    cycles += 3;
}

//Perform a bitwise XOR on the A register with the A register **Note: This always results in a zero
void gb::cpu::XOR_A()
{
    a = a ^ a;
    //Since this always results in a 0, the zero flag is set, the remaining flags are set to 0
    f = f | 0b10000000;

    cycles += 4;
}

void gb::cpu::SetupInstructionTables()
{
    instructionTable[0x00] = &NO_OP;
    instructionTable[0x21] = &LD_HL_D16;
    instructionTable[0x31] = &LD_SP_D16;
    instructionTable[0x32] = &LD_HL_DEC_A;
    instructionTable[0xAF] = &XOR_A;
}