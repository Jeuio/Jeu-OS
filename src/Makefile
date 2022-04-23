C_SOURCES = $(wildcard Kernel/*.cpp Kernel/Interrupts/*.cpp Drivers/*.cpp Librarys/*.cpp ChessGame/*.cpp)
HEADERS = $(wildcard Kernel/*.h Kernel/Interrupts/*.h Drivers/*.h Librarys/*.h ChessGame/*.h)
ASM = $(wildcard Kernel/*.asm Kernel/Interrupts/*.asm)

ASM_OBJ = ${ASM:.asm=.o}
OBJ = ${C_SOURCES:.cpp=.o}



Clean:
	del /Q /F /S "*.tmp"
	del /Q /F /S "*.o"
	del /Q /F /S "*.bin"



Jeu-OS.iso: Jeu-OS.bin
	copy bootloader.bin iso\bootloader.bin
	copy kernel.bin iso\kernel.bin
	xorriso -as mkisofs -b bootloader.bin -hard-disk-boot -o JeuOS.iso iso
	$(MAKE) Clean


Jeu-OS.bin: bootloader.bin kernel.bin
	copy bootloader.bin /b + kernel.bin /b  Jeu-OS.bin



bootloader.bin : Bootloader/bootloader.asm
	nasm Bootloader/bootloader.asm -o bootstrap.bin
	nasm Bootloader/MBR.asm -o MBR.bin
	copy bootstrap.bin /b + MBR.bin /b bootloader.bin



kernel.bin : ${ASM_OBJ} ${OBJ}
	ld -T "linkerScript" -o kernel.tmp $^
	objcopy -O binary -j .text -j .data -j .rdata kernel.tmp kernel.bin



%.o : %.cpp
	g++ -g --no-leading-underscore -ffreestanding -c $< -o $@



%.o : %.asm
	nasm $< -f elf -o $@



%.bin : %.asm
	nasm $< -f win32 -o $@