#ifndef GB_MEMORY
#define GB_MEMORY

#define VRAM_START 0x8000
#define VRAM_END 0x9FFF

#include <vector>
#include <cstdint>
#include <stdexcept>

namespace gb
{  
    class mmu
    {
    public:
        mmu(std::vector<uint8_t> bootRom, std::vector<uint8_t> gameRom);

        //returns a byte from the specified 16 bit address
        uint8_t read(uint16_t address);

        //writes a byte to the specified 16 bit address
        void write(uint16_t address, uint8_t data);

        //Print the hexidecimal value at the specified address 
        void PrintByteAsHex(uint16_t address);

    private:
        std::vector<uint8_t> mem;
        std::vector<uint8_t> bootRom;

        //If true, reads from adresses 0x0000 to 0x00FF will read from the boot rom instead of the game cartridge
        //Writing any value to 0xFF50 will effectively unmap the bootrom, and reads will be retrieved from mem
        bool isBootRomMapped = true;
    };
}


#endif