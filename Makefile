C_SOURCES = $(wildcard Kernel/*.cpp Kernel/Interrupts/*.cpp Drivers/*.cpp Librarys/*.cpp ChessGame/*.cpp)
HEADERS = $(wildcard Kernel/*.h Kernel/Interrupts/*.h Drivers/*.h Librarys/*.h ChessGame/*.h)
ASM = $(wildcard Kernel/*.asm Kernel/Interrupts/*.asm)

ASM_OBJ = ${ASM:.asm=.o}
OBJ = ${C_SOURCES:.cpp=.o}


Jeu-OS.iso: Jeu-OS.bin
	Oscdimg -b"bootloader.bin" iso Jeu-OS.iso



Jeu-OS.bin: bootloader.bin kernel.bin
	copy bootloader.bin /b + kernel.bin /b  Jeu-OS.bin
	copy kernel.bin iso\kernel.bin




bootloader.bin : Bootloader/bootloader.asm
	nasm Bootloader/bootloader.asm -o bootloader.bin



kernel.bin : ${ASM_OBJ} ${OBJ}
	ld -T "linkerScript" -o kernel.tmp $^
	objcopy -O binary -j .text -j .data -j .rdata kernel.tmp kernel.bin



%.o : %.cpp
	g++ -g --no-leading-underscore -ffreestanding -c $< -o $@



%.o : %.asm
	nasm $< -f elf -o $@



%.bin : %.asm
	nasm $< -f win32 -o $@