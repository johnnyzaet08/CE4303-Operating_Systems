#include "fpga.h"

#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>


#include <sys/mman.h>
#include "socal/socal.h"
#include "socal/hps.h"
#include "socal/alt_gpio.h"


// QSyS dependent address
#define FPGA_LED_PIO_BASE   0x00000080
#define FPGA_KEY_PIO_BASE   0x00000070

#define FPGA_SDRAM_BASE		0x00000000


// ///////////////////////////////////////
// memory map

#define HW_SPAN_64MB 						0x04000000
#define HW_SPAN_2MB							0x00000700
#define ALT_FPGA_BRIDGE_H2F_OFST        	0xFF200000
#define ALT_FPGA_BRIDGE_H2F128_OFST        	0xC0000000


// end
// ///////////////////////////////////////////////////

FPGA::FPGA()
{
    m_bInitSuccess = Init();
    if (!m_bInitSuccess)
        printf("Error/n");
}

FPGA::~FPGA()
{
    close(m_file_mem);
}


bool FPGA::Init()
{
    bool bSuccess = false;

    m_file_mem = open( "/dev/mem", ( O_RDWR | O_SYNC ) );
    if (m_file_mem != -1){
        void *virtual_base;
        void *virtual_base_memory;
        virtual_base = mmap( NULL, HW_SPAN_2MB, ( PROT_READ | PROT_WRITE ), MAP_SHARED, m_file_mem, ALT_FPGA_BRIDGE_H2F_OFST );
        virtual_base_memory = mmap( NULL, HW_SPAN_64MB, ( PROT_READ | PROT_WRITE ), MAP_SHARED, m_file_mem, ALT_FPGA_BRIDGE_H2F128_OFST );
        if (virtual_base == MAP_FAILED || virtual_base_memory == MAP_FAILED){
        }else{
            m_led_base= (uint8_t *)virtual_base + FPGA_LED_PIO_BASE;
            m_key_base= (uint8_t *)virtual_base + FPGA_KEY_PIO_BASE;
            
			m_sdram_base = (volatile uint16_t *)((uint8_t *)virtual_base_memory);
			            
            bSuccess = true;
        }
        close(m_file_mem);
    }


    return bSuccess;
}


bool FPGA::LedSet(int mask){
    if (!m_bInitSuccess)
        return false;

    *(uint32_t *)m_led_base = mask;
    return true;
}

bool FPGA::LedGet(uint32_t *mask){
    if (!m_bInitSuccess)
        return false;

    *mask = *(uint32_t *)m_led_base;;
    return true;
}

bool FPGA::KeyRead(uint32_t *mask){
    if (!m_bInitSuccess)
        return false;

    *mask = *(uint32_t *)m_key_base;
    return true;

}

bool FPGA::WriteMask(uint16_t value, int offset){
    if (!m_bInitSuccess)
        return false;

	m_sdram_base[offset]= value;
    return true;
}

bool FPGA::ReadMask(uint16_t  *value, int offset){
    if (!m_bInitSuccess)
        return false;

	*value = m_sdram_base[offset];
    return true;
}




