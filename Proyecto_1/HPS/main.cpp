#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <cstdint>
#include "fpga.h"

int main(int argc, char *argv[])
{
    FPGA *fpga;

    // fpga init
    fpga = new FPGA;

    uint32_t ledMask = 0;
    int direccionImagen = 4;

    printf("Starting now... \n");

    ledMask |= (0x01 << 0);
    fpga->LedSet(ledMask);
    
    uint32_t mask_btn;
    int mask_btn_aux;
    
    uint32_t mask_leds;
    int mask_leds_aux;
    
    int direccionPrintAUX = 3;
    uint16_t maskPrintAUX;
    
    while(true){
    	
    	fpga->KeyRead(&mask_btn);
    	fpga->LedGet(&mask_leds);
    	mask_btn_aux = int(mask_btn);
    	mask_leds_aux = int(mask_leds);
    	    	
    	if(mask_btn_aux == 14){
    		if(ledMask == 0x01){
    			std::ifstream file("pixels.txt");
			    if (!file.is_open()) {
			        printf("No se pudo abrir el archivo\n");
			        return 1;
			    }
			
			    uint16_t pixel;
			    char comma;
			    printf("Cargando los pixeles en la SDRAM\n");
			    
			    while (file >> pixel >> comma) {
			        fpga->WriteMask(pixel, direccionImagen);
			        direccionImagen += 1;
			    }
			    
			    file.close();
			    
			    ledMask |= (0x01 << 1);
    			fpga->LedSet(ledMask);
			}
			
			else if(ledMask == 0x111111){
				printf("Ya termino de desencriptar");
			}
		}else if(mask_btn_aux == 7){
			fpga->ReadMask(&maskPrintAUX, direccionPrintAUX);
			std::cout << "Direccion: " << direccionPrintAUX << " valor: " << maskPrintAUX << std::endl;
			direccionPrintAUX += 1;
		}else if(mask_leds_aux == 31){
			printf("Desencriptando pixeles");
		}else if(mask_leds_aux == 63){
			printf("Pixeles totalmente desencriptados, aplicando filtro");
		}
	}
    
    
    
    

    return 0;
}
