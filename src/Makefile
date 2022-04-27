C_SOURCES = $(wildcard Kernel/*.cpp Kernel/Interrupts/*.cpp Drivers/*.cpp Librarys/*.cpp ChessGame/*.cpp)
HEADERS = $(wildcard Kernel/*.h Kernel/Interrupts/*.h Drivers/*.h Librarys/*.h ChessGame/*.h)
ASM = $(wildcard Kernel/*.asm Kernel/Interrupts/*.asm)

ASM_OBJ = ${ASM:.asm=.o}
OBJ = ${C_SOURCES:.cpp=.o}



Clean:
ifdef OS
	del /Q /F /S "*.tmp"
	del /Q /F /S "*.o"
	del /Q /F /S "*.bin"
endif


Jeu-OS.iso: Jeu-OS.bin
ifdef OS
	copy bootloader.bin iso\bootloader.bin
	copy kernel.bin iso\kernel.bin
	xorriso -as mkisofs -b bootloader.bin -hard-disk-boot -o JeuOS.iso iso
	$(MAKE) Clean
else

endif


Jeu-OS.bin: bootloader.bin kernel.bin
ifdef OS
	copy bootloader.bin /b + kernel.bin /b  Jeu-OS.bin
else

endif



bootloader.bin : Bootloader/bootloader.asm
ifdef OS
	nasm Bootloader/bootloader.asm -o bootstrap.bin
	nasm Bootloader/MBR.asm -o MBR.bin
	copy bootstrap.bin /b + MBR.bin /b bootloader.bin
else

endif



kernel.bin : ${ASM_OBJ} ${OBJ}
ifdef OS
	ld -T "linkerScript" -o kernel.tmp $^
	objcopy -O binary -j .text -j .data -j .rdata kernel.tmp kernel.bin
else

endif



%.o : %.cpp
ifdef OS
	g++ -g --no-leading-underscore -ffreestanding -c $< -o $@
else

endif



%.o : %.asm
ifdef OS
	nasm $< -f elf -o $@
else

endif



%.bin : %.asm
ifdef OS
	nasm $< -f win32 -o $@
else

endif