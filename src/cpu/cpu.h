#ifndef GB_CPU
#define GB_CPU

#include <iostream>
#include <cstdint>
#include "mmu/mmu.h"

namespace gb
{
    enum RegisterCombo
    {
        AF,
        BC,
        DE,
        HL
    };

    class cpu
    {
    public:

        cpu(gb::mmu* memory);
        void Step();

    private:
        //8 Bit cpu registers, f is special and represent flag states from certain ops
        uint8_t a, b, c, d, e, f, h, l;

        void SetComboRegister(RegisterCombo reg, uint16_t data);
        uint16_t GetComboRegister(RegisterCombo reg);

        uint16_t program_counter = 0x0000;
        uint16_t stack_pointer = 0x0000;

        uint32_t cycles = 0;

        typedef void (gb::cpu::*InstructionTable)();
        InstructionTable instructionTable[256];

        gb::mmu* memory;

        void SetupInstructionTable();

        void NO_OP();
        void LD_SP_NN();
        void XOR_A();
    };
}
#endif