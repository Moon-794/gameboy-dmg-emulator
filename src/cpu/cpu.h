#ifndef GB_CPU
#define GB_CPU

#include <iostream>
#include <cstdint>
#include <functional>
#include "mmu/mmu.h"

#define FLAG_Z 0x80
#define FLAG_N 0x40  
#define FLAG_H 0x20  
#define FLAG_C 0x10

#define BIT_7 0x80
#define BIT_6 0x40
#define BIT_5 0x20
#define BIT_4 0x10
#define BIT_3 0x08
#define BIT_2 0x04
#define BIT_1 0x02
#define BIT_0 0x01


namespace gb
{
    enum RegisterCombo
    {
        AF,
        BC,
        DE,
        HL
    };
    enum Register
    {
        A,
        B,
        C,
        D,
        E,
        F,
        H,
        L
    };

    struct InstructionParams
    {
        uint8_t* reg;
        RegisterCombo reg16;

        uint16_t address;

        uint8_t immediate;
        uint16_t immediate16;

        uint8_t bit_flag;
    };

    class cpu
    {
    public:

        cpu(gb::mmu* memory);
        void Step();

    private:
        //8 Bit cpu registers, f is special and represent flag states from certain ops
        uint8_t a, b, c, d, e, f, h, l;

        void SetFlag(uint8_t flag);
        void ResetFlag(uint8_t flag);

        bool isFlagSet(uint8_t flag);

        void SetComboRegister(RegisterCombo reg, uint16_t data);
        uint16_t GetComboRegister(RegisterCombo reg);

        uint16_t program_counter = 0x0000;
        uint16_t stack_pointer = 0x0000;

        uint32_t cycles = 0;

        typedef void (gb::cpu::*InstructionTable)();
        std::function<void()> instructionTable[256];
        
        bool usingCB;
        std::function<void()> extendedInstructionTable[256];

        gb::mmu* memory;

        void SetupInstructionTables();

        //Utility
        uint16_t convert16Bit(uint8_t lsb, uint8_t msb);

        //Generics
        void LD_NN_D16(RegisterCombo reg16);
        void LD_X_D8(uint8_t* reg);
        void LD_X_Y(uint8_t* x, uint8_t y);
        void LD_X_YY(uint8_t* x, uint16_t yy);
        void INC_X(uint8_t* reg);
        void LD_HL_X(uint8_t* reg);
        void XOR_X(uint8_t* reg);

        void DEC_X(uint8_t* reg);

        void PUSH_XX(RegisterCombo reg);
        void POP_XX(RegisterCombo reg);

        void JR_CC_R8(uint8_t flag);

        //Specific implementations
        void NO_OP();

        void JR_D8();
        void LDH_A_A8();

        void LD_FFC_A();
        void LD_HL_A(); 

        void LD_SP_D16();
        void JR_NZ_D8();
        void LD_HL_D16();
        void LD_HL_DEC_A();
        void LD_HL_INC_A();
        void LD_DE_D16();
        void LDH_A8_A();
        void LD_A16_A();

        void CD();
        void RET();

        void CP_D8();

        //CB Generics
        void BIT_N_X(uint8_t n, uint8_t* reg);
        void RL_X(uint8_t* reg);

        //Debugging related
        void PrintRegister(Register reg);
        void PrintComboRegister(RegisterCombo reg);
    };
}
#endif