AS = linux-arm-gnueabihf-as
LD = linux-arm-gnueabihf-ld

INCLUDE_PATH += /home/johnnyzaet/Desktop/includes/intel-socfpga-hwlib/armv7a/hwlib/include

OBJ = main.o ADLX345.o fpga.o hps.o

all: main

main: $(OBJ)
	$(LD) -o main $(OBJ)

%.o: %.s
	$(AS) $< -o $@

%.s: %.cpp
	$(CC) -I$(INCLUDE_PATH) -S $< -o $@

clean:
	rm -f *.o *.s main
