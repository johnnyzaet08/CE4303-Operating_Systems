#include <stdio.h>
#include <stdint.h>
#include "hps.h"
#include "fpga.h"


int main(int argc, char *argv[])
{
    HPS *hps;
    FPGA *fpga;

    // hps and fpga init
    hps = new HPS;
    fpga = new FPGA;

    uint32_t ledMask = 0;

    printf("Starting now... \n");

    while(true){
        int i = 0;
        scanf("%d", &i);
        ledMask |= (0x01 << i);
        fpga->LedSet(ledMask);
    }
    
    hps->LedSet(true);
    scanf("%d", &i);


    return 0;
}
