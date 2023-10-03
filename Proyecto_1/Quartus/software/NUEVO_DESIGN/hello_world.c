#include "sys/alt_irq.h"

#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"

#include <stdint.h>
#include "Algoritmo_rsa.h"

uint32_t mask_8b = 0b00000000000000000000000011111111;
uint32_t mask_4b = 0b00000000000000000000000000001111;
uint32_t mask_2b = 0b00000000000000000000000000000011;
uint32_t mask_1b = 0b00000000000000000000000000000001;

volatile  uint16_t *m_sdram_base = (volatile uint16_t *)((uint8_t *)SDRAM_BASE);

int decoder (int num) {

	int binarySegments = 0b1111111;

	if(num == 0){
		binarySegments = 0b1000000;
	}else if(num == 1){
		binarySegments = 0b1111001;
	}else if(num == 2){
		binarySegments = 0b0100100;
	}else if(num == 3){
		binarySegments = 0b0110000;
	}else if(num == 4){
		binarySegments = 0b0011001;
	}else if(num == 5){
		binarySegments = 0b0010010;
	}else if(num == 6){
		binarySegments = 0b0000010;
	}else if(num == 7){
		binarySegments = 0b1111000;
	}else if(num == 8){
		binarySegments = 0b0000000;
	}else if(num == 9){
		binarySegments = 0b0010000;
	}else{
		binarySegments = 0b0000001;
	}

	return binarySegments;
};

int button_bit = 0b0;
int flag = 1;
int flag2 = 0;
int count = 0;
int clave_publica = 0b0000000000000000;
int clave_privada = 0b0000000000000000;

static void key_builder()
{
	// Leer el valor de los interruptores
	int switch_bits = IORD_ALTERA_AVALON_PIO_DATA(SW_BASE);
	switch_bits = switch_bits >> 6;
	button_bit = IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
	button_bit = button_bit >> 1;
	button_bit = button_bit & 0b1;

	if (button_bit){
		flag = 1;
		switch(count){
			case 0:
				IOWR_ALTERA_AVALON_PIO_DATA(SEG3_BASE, decoder(switch_bits));
				break;
			case 1:
				IOWR_ALTERA_AVALON_PIO_DATA(SEG4_BASE, decoder(switch_bits));
				break;
			case 2:
				IOWR_ALTERA_AVALON_PIO_DATA(SEG5_BASE, decoder(switch_bits));
				break;
			case 3:
				IOWR_ALTERA_AVALON_PIO_DATA(SEG6_BASE, decoder(switch_bits));
				break;
			default:
				IOWR_ALTERA_AVALON_PIO_DATA(SEG3_BASE, 0b0000);
				IOWR_ALTERA_AVALON_PIO_DATA(SEG4_BASE, 0b0000);
				IOWR_ALTERA_AVALON_PIO_DATA(SEG5_BASE, 0b0000);
				IOWR_ALTERA_AVALON_PIO_DATA(SEG6_BASE, 0b0000);

				if (flag2==0){
					IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, 0b0000111);
				}else{
					IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, 0b0001111);
				}
				flag2+=1;
				count = 0;
				break;
		}
	}

	if ((!button_bit) & flag){
		int base = 0b10000;
		int resultado = 1;
		for (int i = 0; i < count; i++) {
			resultado *= base;
		}
		if (flag2==0){
			clave_publica += switch_bits*resultado;
		}else if (flag2==1){
			clave_privada += switch_bits*resultado;
		}
		count += 1;
		flag = 0;
	}
}

static void timer_isr(void *context)
{
    (void) context;

    if ((IORD_ALTERA_AVALON_PIO_DATA(LEDS_BASE) == 0b0000000011) | (IORD_ALTERA_AVALON_PIO_DATA(LEDS_BASE) == 0b0000000111)){
    	key_builder();
    }else if(IORD_ALTERA_AVALON_PIO_DATA(LEDS_BASE) == 0b0000001111){
		int i = 0;
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, 0b0011111);
		while(i < 100){
			int data = m_sdram_base[i];
			int decipher = Decryption(data, clave_publica, clave_privada);
			m_sdram_base[i] = decipher;
		}
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, 0b0111111);
    }

    IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_BASE, 0);
}


int main()
{

	alt_ic_isr_register(
		TIMER_IRQ_INTERRUPT_CONTROLLER_ID,
		TIMER_IRQ,
		timer_isr,
		NULL,
		NULL
	);

	IOWR_ALTERA_AVALON_TIMER_CONTROL(
		TIMER_BASE,
		ALTERA_AVALON_TIMER_CONTROL_ITO_MSK
		| ALTERA_AVALON_TIMER_CONTROL_CONT_MSK
	);

  while (1);
}
