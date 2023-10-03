#ifndef FPGA_H
#define FPGA_H

#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>


class FPGA
{
public:
    FPGA();
    ~FPGA();

    bool LedSet(int mask);
    bool LedGet(uint32_t *mask);
    bool KeyRead(uint32_t *mask);
    bool WriteMask(uint16_t mask, int offset);
    bool ReadMask(uint16_t *mask, int offset);
	


protected:
    bool m_bInitSuccess;
    int m_file_mem;
    bool m_bIsVideoEnabled;

    uint8_t *m_led_base;
    uint8_t *m_key_base;
    volatile  uint16_t *m_sdram_base;

    bool Init();

};

#endif // FPGA_H
