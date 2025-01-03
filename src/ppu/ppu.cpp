#include "ppu/ppu.h"

gb::ppu::ppu(gb::mmu* memory) : window(memory)
{
    this->memory = memory;
}

void gb::ppu::Step(uint32_t cycles)
{
    for (size_t i = 0; i < cycles; i++)
    {
        clock++;;

        if(clock == 456)
        {
            clock = 0;
            scanline++;

            if(scanline >= 144)
            {
                if(scanline == 154)
                {
                    //Vertical blank period is over, reset scanline
                    scanline = 0;
                }
                
                if(scanline == 144)
                {
                    //Entering Vertical blank, change mode
                    ChangeMode(ppuMode::VERTICAL_BLANK);

                    //std::cout << (int)memory->read(0x8000) << "\n";

                    //Enable IF VBlank flag
                    uint8_t IF = memory->read(0xFF0F);
                    IF = IF | 0x01;
                    memory->write(0xFF0F, IF);
                }
            }  
        }

        UpdateLY();

        if(mode == ppuMode::VERTICAL_BLANK && scanline < 144)
        {
            if(clock < 80)
                ChangeMode(ppuMode::OAM_SCAN);
        }

        //Mode 2, 3 and 0 changes
        if(mode == ppuMode::HORIZONTAL_BLANK && clock == 0)
        {
            //Entered OAM Scan
            ChangeMode(ppuMode::OAM_SCAN);
        }

        if(mode == ppuMode::OAM_SCAN && clock == OAM_SCAN_SPAN)
        {
            //Entered pixel drawing mode
            ChangeMode(ppuMode::DRAWING_PIXELS);
        }

        if(mode == DRAWING_PIXELS && clock == OAM_SCAN_SPAN + DRAWING_PIXELS_SPAN)
        {
            //Entered Horizontal Blank Mode
            ChangeMode(ppuMode::HORIZONTAL_BLANK);
        }

        ModeUpdate(cycles);
        window.Update(mode, clock, scanline, cycles);
    }
}

void gb::ppu::ChangeMode(ppuMode newMode)
{
    mode = newMode;
}

void::gb::ppu::ModeUpdate(int cycles)
{
    if(mode == ppuMode::DRAWING_PIXELS)
    {
        window.DrawPixels(cycles);
    }
}

void gb::ppu::UpdateLY()
{
    memory->write(0xFF44, scanline);
}