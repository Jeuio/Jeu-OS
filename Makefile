C_SOURCES = $(wildcard Kernel/*.cpp Kernel/Interrupts/*.cpp Drivers/*.cpp Librarys/*.cpp)
HEADERS = $(wildcard Kernel/*.h Kernel/Interrupts/*.h Drivers/*.h Librarys/*.h)
KERNEL_ENTRY = $(wildcard Kernel/*.asm)

KERNEL_ENTRY_OBJ = ${KERNEL_ENTRY:.asm=.o}
OBJ = ${C_SOURCES:.cpp=.o}


all: Jeu-OS-image


Jeu-OS-image: bootloader.bin kernel.bin
	copy bootloader.bin /b + kernel.bin /b  Jeu-OS-image.bin



bootloader.bin : Bootloader/bootloader.asm
	nasm Bootloader/bootloader.asm -o bootloader.bin



kernel.bin : ${KERNEL_ENTRY_OBJ} ${OBJ}
	ld -T "linkerScript" -o kernel.tmp $^
	objcopy -O binary -j .text -j .rdata kernel.tmp kernel.bin



%.o : %.cpp
	g++ -ffreestanding -c $< -o $@



%.o : %.asm
	nasm $< -f elf -o $@



%.bin : %.asm
	nasm $< -o $@