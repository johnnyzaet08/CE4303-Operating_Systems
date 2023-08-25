#include "sys/alt_irq.h"

#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"

#include "system.h"

int counter = 0;
int switchSelect = 0b00;
int start = 0;
int stop = 1;


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

static void timer_isr(void *context){
	(void) context;

	switchSelect = IORD_ALTERA_AVALON_PIO_DATA(PIO_SELECTMODE_0_BASE);
	int start_aux = IORD_ALTERA_AVALON_PIO_DATA(PIO_START_0_BASE);
	int stop_aux = IORD_ALTERA_AVALON_PIO_DATA(PIO_STOP_0_BASE);

	if(switchSelect == 0b01){
		//Configuracion 0b01 en los switches, muetran el estado Milisegundos
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MILISECONDS_0_BASE, decoder(counter / 100 % 10));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MILISECONDS_1_BASE, decoder(counter / 100 / 10));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_SECONDS_0_BASE, decoder(0));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_SECONDS_1_BASE, decoder(0));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MINUTES_0_BASE, decoder(0));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MINUTES_1_BASE, decoder(0));
	}
	else if(switchSelect == 0b10){
		//Configuracion 0b10 en los switches, muetran el estado Segundos
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MILISECONDS_0_BASE, decoder(0));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MILISECONDS_1_BASE, decoder(0));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_SECONDS_0_BASE, decoder(counter / 1000 % 10));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_SECONDS_1_BASE, decoder(counter / 1000 / 10));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MINUTES_0_BASE, decoder(0));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MINUTES_1_BASE, decoder(0));
	}
	else if(switchSelect == 0b11){
		//Configuracion 0b11 en los switches, muetran el estado Minutos
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MILISECONDS_0_BASE, decoder(counter / 100 % 10));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MILISECONDS_1_BASE, decoder(counter / 100 / 10));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_SECONDS_0_BASE, decoder(counter / 1000 % 10));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_SECONDS_1_BASE, decoder(counter / 1000 / 10));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MINUTES_0_BASE, decoder(counter / 60000 % 10));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MINUTES_1_BASE, decoder(counter / 60000 / 10));
	}
	else {
		//Configuracion 0b00 en los switches, muestran un estado inicial
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MILISECONDS_0_BASE, decoder(0));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MILISECONDS_1_BASE, decoder(1));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_SECONDS_0_BASE, decoder(2));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_SECONDS_1_BASE, decoder(3));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MINUTES_0_BASE, decoder(4));
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_MINUTES_1_BASE, decoder(5));
	};

	//Actualizar los milisegundos cada 10 y actualizar cada milisegundo
	if(start == 0b1){
		counter ++;
	}

	if(start_aux == 1 & stop == 1){
		start = 1;
		stop = 0;
	}else if(stop_aux == 1 & start == 1){
		start = 0;
		stop = 1;
	}


	// Regresar el timer para que vuelta a hacer una interrucion
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);

}

int main()
{

	alt_ic_isr_register(
		TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID,
		TIMER_0_IRQ,
		timer_isr,
		NULL,
		NULL);

	IOWR_ALTERA_AVALON_TIMER_CONTROL(
		TIMER_0_BASE,
		ALTERA_AVALON_TIMER_CONTROL_ITO_MSK
		| ALTERA_AVALON_TIMER_CONTROL_CONT_MSK
	);

  while (1);
}
