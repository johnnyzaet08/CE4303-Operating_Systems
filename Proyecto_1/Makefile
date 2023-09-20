AS = linux-arm-gnueabihf-as
LD = linux-arm-gnueabihf-ld

OBJ = main.o ADLX345.o fpga.o hps.o

all: main

main: $(OBJ)
	$(LD) -o main $(OBJ)

%.o: %.s
	$(AS) $< -o $@

%.s: %.cpp
	$(CC) -S $< -o $@

clean:
	rm -f *.o *.s main
