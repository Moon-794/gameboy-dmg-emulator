#include "cpu/cpu.h"

void gb::cpu::SetupInstructionTableEXT()
{
    extendedInstructionTable[0x10] = [this]{ gb::cpu::RL_X(&b); };
    extendedInstructionTable[0x11] = [this]{ gb::cpu::RL_X(&c); };
    extendedInstructionTable[0x12] = [this]{ gb::cpu::RL_X(&d); };
    extendedInstructionTable[0x13] = [this]{ gb::cpu::RL_X(&e); };
    extendedInstructionTable[0x14] = [this]{ gb::cpu::RL_X(&h); };
    extendedInstructionTable[0x15] = [this]{ gb::cpu::RL_X(&l); };
    extendedInstructionTable[0x17] = [this]{ gb::cpu::RL_X(&a); };

    extendedInstructionTable[0x18] = [this]{ gb::cpu::RR_X(&b); };
    extendedInstructionTable[0x19] = [this]{ gb::cpu::RR_X(&c); };
    extendedInstructionTable[0x1A] = [this]{ gb::cpu::RR_X(&d); };
    extendedInstructionTable[0x1B] = [this]{ gb::cpu::RR_X(&e); };
    extendedInstructionTable[0x1C] = [this]{ gb::cpu::RR_X(&h); };
    extendedInstructionTable[0x1D] = [this]{ gb::cpu::RR_X(&l); };
    extendedInstructionTable[0x1F] = [this]{ gb::cpu::RR_X(&a); };

    extendedInstructionTable[0x20] = [this]{ gb::cpu::SLA_X(&b); };
    extendedInstructionTable[0x21] = [this]{ gb::cpu::SLA_X(&c); };
    extendedInstructionTable[0x22] = [this]{ gb::cpu::SLA_X(&d); };
    extendedInstructionTable[0x23] = [this]{ gb::cpu::SLA_X(&e); };
    extendedInstructionTable[0x24] = [this]{ gb::cpu::SLA_X(&h); };
    extendedInstructionTable[0x25] = [this]{ gb::cpu::SLA_X(&l); };
    extendedInstructionTable[0x27] = [this]{ gb::cpu::SLA_X(&a); };

    extendedInstructionTable[0x30] = [this]{ gb::cpu::SWAP_X(&b); };
    extendedInstructionTable[0x31] = [this]{ gb::cpu::SWAP_X(&c); };
    extendedInstructionTable[0x32] = [this]{ gb::cpu::SWAP_X(&d); };
    extendedInstructionTable[0x33] = [this]{ gb::cpu::SWAP_X(&e); };
    extendedInstructionTable[0x34] = [this]{ gb::cpu::SWAP_X(&h); };
    extendedInstructionTable[0x35] = [this]{ gb::cpu::SWAP_X(&l); };
    extendedInstructionTable[0x37] = [this]{ gb::cpu::SWAP_X(&a); };
    extendedInstructionTable[0x38] = [this]{ gb::cpu::SRL_X(&b); };
    extendedInstructionTable[0x39] = [this]{ gb::cpu::SRL_X(&c); };
    extendedInstructionTable[0x3A] = [this]{ gb::cpu::SRL_X(&d); };
    extendedInstructionTable[0x3B] = [this]{ gb::cpu::SRL_X(&e); };
    extendedInstructionTable[0x3C] = [this]{ gb::cpu::SRL_X(&h); };
    extendedInstructionTable[0x3D] = [this]{ gb::cpu::SRL_X(&l); };
    extendedInstructionTable[0x3F] = [this]{ gb::cpu::SRL_X(&a); };

    extendedInstructionTable[0x40] = [this]{ gb::cpu::BIT_N_X(BIT_0, &b); };
    extendedInstructionTable[0x41] = [this]{ gb::cpu::BIT_N_X(BIT_0, &c); };
    extendedInstructionTable[0x42] = [this]{ gb::cpu::BIT_N_X(BIT_0, &d); };
    extendedInstructionTable[0x43] = [this]{ gb::cpu::BIT_N_X(BIT_0, &e); };
    extendedInstructionTable[0x44] = [this]{ gb::cpu::BIT_N_X(BIT_0, &h); };
    extendedInstructionTable[0x45] = [this]{ gb::cpu::BIT_N_X(BIT_0, &l); };
    extendedInstructionTable[0x46] = [this]{ gb::cpu::BIT_N_HL(BIT_0); };
    extendedInstructionTable[0x47] = [this]{ gb::cpu::BIT_N_X(BIT_0, &a); };
    extendedInstructionTable[0x48] = [this]{ gb::cpu::BIT_N_X(BIT_1, &b); };
    extendedInstructionTable[0x49] = [this]{ gb::cpu::BIT_N_X(BIT_1, &c); };
    extendedInstructionTable[0x4A] = [this]{ gb::cpu::BIT_N_X(BIT_1, &d); };
    extendedInstructionTable[0x4B] = [this]{ gb::cpu::BIT_N_X(BIT_1, &e); };
    extendedInstructionTable[0x4C] = [this]{ gb::cpu::BIT_N_X(BIT_1, &h); };
    extendedInstructionTable[0x4D] = [this]{ gb::cpu::BIT_N_X(BIT_1, &l); };
    extendedInstructionTable[0x4E] = [this]{ gb::cpu::BIT_N_HL(BIT_1); };
    extendedInstructionTable[0x4F] = [this]{ gb::cpu::BIT_N_X(BIT_1, &a); };

    extendedInstructionTable[0x50] = [this]{ gb::cpu::BIT_N_X(BIT_2, &b); };
    extendedInstructionTable[0x51] = [this]{ gb::cpu::BIT_N_X(BIT_2, &c); };
    extendedInstructionTable[0x52] = [this]{ gb::cpu::BIT_N_X(BIT_2, &d); };
    extendedInstructionTable[0x53] = [this]{ gb::cpu::BIT_N_X(BIT_2, &e); };
    extendedInstructionTable[0x54] = [this]{ gb::cpu::BIT_N_X(BIT_2, &h); };
    extendedInstructionTable[0x55] = [this]{ gb::cpu::BIT_N_X(BIT_2, &l); };
    extendedInstructionTable[0x56] = [this]{ gb::cpu::BIT_N_HL(BIT_2); };
    extendedInstructionTable[0x57] = [this]{ gb::cpu::BIT_N_X(BIT_2, &a); };
    extendedInstructionTable[0x58] = [this]{ gb::cpu::BIT_N_X(BIT_3, &b); };
    extendedInstructionTable[0x59] = [this]{ gb::cpu::BIT_N_X(BIT_3, &c); };
    extendedInstructionTable[0x5A] = [this]{ gb::cpu::BIT_N_X(BIT_3, &d); };
    extendedInstructionTable[0x5B] = [this]{ gb::cpu::BIT_N_X(BIT_3, &e); };
    extendedInstructionTable[0x5C] = [this]{ gb::cpu::BIT_N_X(BIT_3, &h); };
    extendedInstructionTable[0x5D] = [this]{ gb::cpu::BIT_N_X(BIT_3, &l); };
    extendedInstructionTable[0x5E] = [this]{ gb::cpu::BIT_N_HL(BIT_3); };
    extendedInstructionTable[0x5F] = [this]{ gb::cpu::BIT_N_X(BIT_3, &a); };

    extendedInstructionTable[0x60] = [this]{ gb::cpu::BIT_N_X(BIT_4, &b); };
    extendedInstructionTable[0x61] = [this]{ gb::cpu::BIT_N_X(BIT_4, &c); };
    extendedInstructionTable[0x62] = [this]{ gb::cpu::BIT_N_X(BIT_4, &d); };
    extendedInstructionTable[0x63] = [this]{ gb::cpu::BIT_N_X(BIT_4, &e); };
    extendedInstructionTable[0x64] = [this]{ gb::cpu::BIT_N_X(BIT_4, &h); };
    extendedInstructionTable[0x65] = [this]{ gb::cpu::BIT_N_X(BIT_4, &l); };
    extendedInstructionTable[0x66] = [this]{ gb::cpu::BIT_N_HL(BIT_4); };
    extendedInstructionTable[0x67] = [this]{ gb::cpu::BIT_N_X(BIT_4, &a); };
    extendedInstructionTable[0x68] = [this]{ gb::cpu::BIT_N_X(BIT_5, &b); };
    extendedInstructionTable[0x69] = [this]{ gb::cpu::BIT_N_X(BIT_5, &c); };
    extendedInstructionTable[0x6A] = [this]{ gb::cpu::BIT_N_X(BIT_5, &d); };
    extendedInstructionTable[0x6B] = [this]{ gb::cpu::BIT_N_X(BIT_5, &e); };
    extendedInstructionTable[0x6C] = [this]{ gb::cpu::BIT_N_X(BIT_5, &h); };
    extendedInstructionTable[0x6D] = [this]{ gb::cpu::BIT_N_X(BIT_5, &l); };
    extendedInstructionTable[0x6E] = [this]{ gb::cpu::BIT_N_HL(BIT_5); };
    extendedInstructionTable[0x6F] = [this]{ gb::cpu::BIT_N_X(BIT_5, &a); };

    extendedInstructionTable[0x70] = [this]{ gb::cpu::BIT_N_X(BIT_6, &b); };
    extendedInstructionTable[0x71] = [this]{ gb::cpu::BIT_N_X(BIT_6, &c); };
    extendedInstructionTable[0x72] = [this]{ gb::cpu::BIT_N_X(BIT_6, &d); };
    extendedInstructionTable[0x73] = [this]{ gb::cpu::BIT_N_X(BIT_6, &e); };
    extendedInstructionTable[0x74] = [this]{ gb::cpu::BIT_N_X(BIT_6, &h); };
    extendedInstructionTable[0x75] = [this]{ gb::cpu::BIT_N_X(BIT_6, &l); };
    extendedInstructionTable[0x76] = [this]{ gb::cpu::BIT_N_HL(BIT_6); };
    extendedInstructionTable[0x77] = [this]{ gb::cpu::BIT_N_X(BIT_6, &a); };
    extendedInstructionTable[0x78] = [this]{ gb::cpu::BIT_N_X(BIT_7, &b); };
    extendedInstructionTable[0x79] = [this]{ gb::cpu::BIT_N_X(BIT_7, &c); };
    extendedInstructionTable[0x7A] = [this]{ gb::cpu::BIT_N_X(BIT_7, &d); };
    extendedInstructionTable[0x7B] = [this]{ gb::cpu::BIT_N_X(BIT_7, &e); };
    extendedInstructionTable[0x7C] = [this]{ gb::cpu::BIT_N_X(BIT_7, &h); };
    extendedInstructionTable[0x7D] = [this]{ gb::cpu::BIT_N_X(BIT_7, &l); };
    extendedInstructionTable[0x7E] = [this]{ gb::cpu::BIT_N_HL(BIT_7); };
    extendedInstructionTable[0x7F] = [this]{ gb::cpu::BIT_N_X(BIT_7, &a); };

    extendedInstructionTable[0x80] = [this]{ gb::cpu::RES_N_X(&b, BIT_0); };
    extendedInstructionTable[0x81] = [this]{ gb::cpu::RES_N_X(&c, BIT_0); };
    extendedInstructionTable[0x82] = [this]{ gb::cpu::RES_N_X(&d, BIT_0); };
    extendedInstructionTable[0x83] = [this]{ gb::cpu::RES_N_X(&e, BIT_0); };
    extendedInstructionTable[0x84] = [this]{ gb::cpu::RES_N_X(&h, BIT_0); };
    extendedInstructionTable[0x85] = [this]{ gb::cpu::RES_N_X(&l, BIT_0); };
    extendedInstructionTable[0x86] = [this]{ gb::cpu::RES_N_HL(BIT_0); };
    extendedInstructionTable[0x87] = [this]{ gb::cpu::RES_N_X(&a, BIT_0); };
    extendedInstructionTable[0x88] = [this]{ gb::cpu::RES_N_X(&b, BIT_1); };
    extendedInstructionTable[0x89] = [this]{ gb::cpu::RES_N_X(&c, BIT_1); };
    extendedInstructionTable[0x8A] = [this]{ gb::cpu::RES_N_X(&d, BIT_1); };
    extendedInstructionTable[0x8B] = [this]{ gb::cpu::RES_N_X(&e, BIT_1); };
    extendedInstructionTable[0x8C] = [this]{ gb::cpu::RES_N_X(&h, BIT_1); };
    extendedInstructionTable[0x8D] = [this]{ gb::cpu::RES_N_X(&l, BIT_1); };
    extendedInstructionTable[0x8E] = [this]{ gb::cpu::RES_N_HL(BIT_1); };
    extendedInstructionTable[0x8F] = [this]{ gb::cpu::RES_N_X(&a, BIT_1); };

    extendedInstructionTable[0x90] = [this]{ gb::cpu::RES_N_X(&b, BIT_2); };
    extendedInstructionTable[0x91] = [this]{ gb::cpu::RES_N_X(&c, BIT_2); };
    extendedInstructionTable[0x92] = [this]{ gb::cpu::RES_N_X(&d, BIT_2); };
    extendedInstructionTable[0x93] = [this]{ gb::cpu::RES_N_X(&e, BIT_2); };
    extendedInstructionTable[0x94] = [this]{ gb::cpu::RES_N_X(&h, BIT_2); };
    extendedInstructionTable[0x95] = [this]{ gb::cpu::RES_N_X(&l, BIT_2); };
    extendedInstructionTable[0x96] = [this]{ gb::cpu::RES_N_HL(BIT_2); };
    extendedInstructionTable[0x97] = [this]{ gb::cpu::RES_N_X(&a, BIT_2); };
    extendedInstructionTable[0x98] = [this]{ gb::cpu::RES_N_X(&b, BIT_3); };
    extendedInstructionTable[0x99] = [this]{ gb::cpu::RES_N_X(&c, BIT_3); };
    extendedInstructionTable[0x9A] = [this]{ gb::cpu::RES_N_X(&d, BIT_3); };
    extendedInstructionTable[0x9B] = [this]{ gb::cpu::RES_N_X(&e, BIT_3); };
    extendedInstructionTable[0x9C] = [this]{ gb::cpu::RES_N_X(&h, BIT_3); };
    extendedInstructionTable[0x9D] = [this]{ gb::cpu::RES_N_X(&l, BIT_3); };
    extendedInstructionTable[0x9E] = [this]{ gb::cpu::RES_N_HL(BIT_3); };
    extendedInstructionTable[0x9F] = [this]{ gb::cpu::RES_N_X(&a, BIT_3); };

    extendedInstructionTable[0xA0] = [this]{ gb::cpu::RES_N_X(&b, BIT_4); };
    extendedInstructionTable[0xA1] = [this]{ gb::cpu::RES_N_X(&c, BIT_4); };
    extendedInstructionTable[0xA2] = [this]{ gb::cpu::RES_N_X(&d, BIT_4); };
    extendedInstructionTable[0xA3] = [this]{ gb::cpu::RES_N_X(&e, BIT_4); };
    extendedInstructionTable[0xA4] = [this]{ gb::cpu::RES_N_X(&h, BIT_4); };
    extendedInstructionTable[0xA5] = [this]{ gb::cpu::RES_N_X(&l, BIT_4); };
    extendedInstructionTable[0xA6] = [this]{ gb::cpu::RES_N_HL(BIT_4); };
    extendedInstructionTable[0xA7] = [this]{ gb::cpu::RES_N_X(&a, BIT_4); };
    extendedInstructionTable[0xA8] = [this]{ gb::cpu::RES_N_X(&b, BIT_5); };
    extendedInstructionTable[0xA9] = [this]{ gb::cpu::RES_N_X(&c, BIT_5); };
    extendedInstructionTable[0xAA] = [this]{ gb::cpu::RES_N_X(&d, BIT_5); };
    extendedInstructionTable[0xAB] = [this]{ gb::cpu::RES_N_X(&e, BIT_5); };
    extendedInstructionTable[0xAC] = [this]{ gb::cpu::RES_N_X(&h, BIT_5); };
    extendedInstructionTable[0xAD] = [this]{ gb::cpu::RES_N_X(&l, BIT_5); };
    extendedInstructionTable[0xAE] = [this]{ gb::cpu::RES_N_HL(BIT_5); };
    extendedInstructionTable[0xAF] = [this]{ gb::cpu::RES_N_X(&a, BIT_5); };

    extendedInstructionTable[0xB0] = [this]{ gb::cpu::RES_N_X(&b, BIT_6); };
    extendedInstructionTable[0xB1] = [this]{ gb::cpu::RES_N_X(&c, BIT_6); };
    extendedInstructionTable[0xB2] = [this]{ gb::cpu::RES_N_X(&d, BIT_6); };
    extendedInstructionTable[0xB3] = [this]{ gb::cpu::RES_N_X(&e, BIT_6); };
    extendedInstructionTable[0xB4] = [this]{ gb::cpu::RES_N_X(&h, BIT_6); };
    extendedInstructionTable[0xB5] = [this]{ gb::cpu::RES_N_X(&l, BIT_6); };
    extendedInstructionTable[0xB6] = [this]{ gb::cpu::RES_N_HL(BIT_6); };
    extendedInstructionTable[0xB7] = [this]{ gb::cpu::RES_N_X(&a, BIT_6); };
    extendedInstructionTable[0xB8] = [this]{ gb::cpu::RES_N_X(&b, BIT_7); };
    extendedInstructionTable[0xB9] = [this]{ gb::cpu::RES_N_X(&c, BIT_7); };
    extendedInstructionTable[0xBA] = [this]{ gb::cpu::RES_N_X(&d, BIT_7); };
    extendedInstructionTable[0xBB] = [this]{ gb::cpu::RES_N_X(&e, BIT_7); };
    extendedInstructionTable[0xBC] = [this]{ gb::cpu::RES_N_X(&h, BIT_7); };
    extendedInstructionTable[0xBD] = [this]{ gb::cpu::RES_N_X(&l, BIT_7); };
    extendedInstructionTable[0xBE] = [this]{ gb::cpu::RES_N_HL(BIT_7); };
    extendedInstructionTable[0xBF] = [this]{ gb::cpu::RES_N_X(&a, BIT_7); };

    extendedInstructionTable[0xC0] = [this]{ gb::cpu::SET_N_X(BIT_0, &b); };
    extendedInstructionTable[0xC1] = [this]{ gb::cpu::SET_N_X(BIT_0, &c); };
    extendedInstructionTable[0xC2] = [this]{ gb::cpu::SET_N_X(BIT_0, &d); };
    extendedInstructionTable[0xC3] = [this]{ gb::cpu::SET_N_X(BIT_0, &e); };
    extendedInstructionTable[0xC4] = [this]{ gb::cpu::SET_N_X(BIT_0, &h); };
    extendedInstructionTable[0xC5] = [this]{ gb::cpu::SET_N_X(BIT_0, &l); };
    extendedInstructionTable[0xC6] = [this]{ gb::cpu::SET_N_HL(BIT_0); };
    extendedInstructionTable[0xC7] = [this]{ gb::cpu::SET_N_X(BIT_0, &a); };
    extendedInstructionTable[0xC8] = [this]{ gb::cpu::SET_N_X(BIT_1, &b); };
    extendedInstructionTable[0xC9] = [this]{ gb::cpu::SET_N_X(BIT_1, &c); };
    extendedInstructionTable[0xCA] = [this]{ gb::cpu::SET_N_X(BIT_1, &d); };
    extendedInstructionTable[0xCB] = [this]{ gb::cpu::SET_N_X(BIT_1, &e); };
    extendedInstructionTable[0xCC] = [this]{ gb::cpu::SET_N_X(BIT_1, &h); };
    extendedInstructionTable[0xCD] = [this]{ gb::cpu::SET_N_X(BIT_1, &l); };
    extendedInstructionTable[0xCE] = [this]{ gb::cpu::SET_N_HL(BIT_1); };
    extendedInstructionTable[0xCF] = [this]{ gb::cpu::SET_N_X(BIT_1, &a); };

    extendedInstructionTable[0xD0] = [this]{ gb::cpu::SET_N_X(BIT_2, &b); };
    extendedInstructionTable[0xD1] = [this]{ gb::cpu::SET_N_X(BIT_2, &c); };
    extendedInstructionTable[0xD2] = [this]{ gb::cpu::SET_N_X(BIT_2, &d); };
    extendedInstructionTable[0xD3] = [this]{ gb::cpu::SET_N_X(BIT_2, &e); };
    extendedInstructionTable[0xD4] = [this]{ gb::cpu::SET_N_X(BIT_2, &h); };
    extendedInstructionTable[0xD5] = [this]{ gb::cpu::SET_N_X(BIT_2, &l); };
    extendedInstructionTable[0xD6] = [this]{ gb::cpu::SET_N_HL(BIT_2); };
    extendedInstructionTable[0xD7] = [this]{ gb::cpu::SET_N_X(BIT_2, &a); };
    extendedInstructionTable[0xD8] = [this]{ gb::cpu::SET_N_X(BIT_3, &b); };
    extendedInstructionTable[0xD9] = [this]{ gb::cpu::SET_N_X(BIT_3, &c); };
    extendedInstructionTable[0xDA] = [this]{ gb::cpu::SET_N_X(BIT_3, &d); };
    extendedInstructionTable[0xDB] = [this]{ gb::cpu::SET_N_X(BIT_3, &e); };
    extendedInstructionTable[0xDC] = [this]{ gb::cpu::SET_N_X(BIT_3, &h); };
    extendedInstructionTable[0xDD] = [this]{ gb::cpu::SET_N_X(BIT_3, &l); };
    extendedInstructionTable[0xDE] = [this]{ gb::cpu::SET_N_HL(BIT_3); };
    extendedInstructionTable[0xDF] = [this]{ gb::cpu::SET_N_X(BIT_3, &a); };

    extendedInstructionTable[0xE0] = [this]{ gb::cpu::SET_N_X(BIT_4, &b); };
    extendedInstructionTable[0xE1] = [this]{ gb::cpu::SET_N_X(BIT_4, &c); };
    extendedInstructionTable[0xE2] = [this]{ gb::cpu::SET_N_X(BIT_4, &d); };
    extendedInstructionTable[0xE3] = [this]{ gb::cpu::SET_N_X(BIT_4, &e); };
    extendedInstructionTable[0xE4] = [this]{ gb::cpu::SET_N_X(BIT_4, &h); };
    extendedInstructionTable[0xE5] = [this]{ gb::cpu::SET_N_X(BIT_4, &l); };
    extendedInstructionTable[0xE6] = [this]{ gb::cpu::SET_N_HL(BIT_4); };
    extendedInstructionTable[0xE7] = [this]{ gb::cpu::SET_N_X(BIT_4, &a); };
    extendedInstructionTable[0xE8] = [this]{ gb::cpu::SET_N_X(BIT_5, &b); };
    extendedInstructionTable[0xE9] = [this]{ gb::cpu::SET_N_X(BIT_5, &c); };
    extendedInstructionTable[0xEA] = [this]{ gb::cpu::SET_N_X(BIT_5, &d); };
    extendedInstructionTable[0xEB] = [this]{ gb::cpu::SET_N_X(BIT_5, &e); };
    extendedInstructionTable[0xEC] = [this]{ gb::cpu::SET_N_X(BIT_5, &h); };
    extendedInstructionTable[0xED] = [this]{ gb::cpu::SET_N_X(BIT_5, &l); };
    extendedInstructionTable[0xEE] = [this]{ gb::cpu::SET_N_HL(BIT_5); };
    extendedInstructionTable[0xEF] = [this]{ gb::cpu::SET_N_X(BIT_5, &a); };

    extendedInstructionTable[0xF0] = [this]{ gb::cpu::SET_N_X(BIT_6, &b); };
    extendedInstructionTable[0xF1] = [this]{ gb::cpu::SET_N_X(BIT_6, &c); };
    extendedInstructionTable[0xF2] = [this]{ gb::cpu::SET_N_X(BIT_6, &d); };
    extendedInstructionTable[0xF3] = [this]{ gb::cpu::SET_N_X(BIT_6, &e); };
    extendedInstructionTable[0xF4] = [this]{ gb::cpu::SET_N_X(BIT_6, &h); };
    extendedInstructionTable[0xF5] = [this]{ gb::cpu::SET_N_X(BIT_6, &l); };
    extendedInstructionTable[0xF6] = [this]{ gb::cpu::SET_N_HL(BIT_6); };
    extendedInstructionTable[0xF7] = [this]{ gb::cpu::SET_N_X(BIT_6, &a); };
    extendedInstructionTable[0xF8] = [this]{ gb::cpu::SET_N_X(BIT_7, &b); };
    extendedInstructionTable[0xF9] = [this]{ gb::cpu::SET_N_X(BIT_7, &c); };
    extendedInstructionTable[0xFA] = [this]{ gb::cpu::SET_N_X(BIT_7, &d); };
    extendedInstructionTable[0xFB] = [this]{ gb::cpu::SET_N_X(BIT_7, &e); };
    extendedInstructionTable[0xFC] = [this]{ gb::cpu::SET_N_X(BIT_7, &h); };
    extendedInstructionTable[0xFD] = [this]{ gb::cpu::SET_N_X(BIT_7, &l); };
    extendedInstructionTable[0xFE] = [this]{ gb::cpu::SET_N_HL(BIT_7); };
    extendedInstructionTable[0xFF] = [this]{ gb::cpu::SET_N_X(BIT_7, &a); };
}