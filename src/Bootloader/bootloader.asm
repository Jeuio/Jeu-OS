[org 0x7C00]               ;This isn't needed when trying to create an elf format file, as we do

KERNEL_OFFSET equ 0x1000    ; Memory address of the kernels beginning (0x1000)

start:
    mov [BOOT_DRIVE], dl    ;remembers address of boot drive

    ;set the pointers of the stack
    mov bp, 0x9bff          ;sets the base pointer of the stack just below the location of the bootloader in memory
    mov sp, bp              ;also needed for stack

    mov bx, MSG_REAL_MODE
    call print_string

    mov bx, MSG_LOAD_KERNEL
    call print_string

    mov bx, KERNEL_OFFSET
    mov dh, 32               ; Load sectors
    mov dl, [BOOT_DRIVE]     ; Address of boot drive
    call disk_load

    ; @annoyance this in not dynamic. use the VGA registers to switch modes in the future
    ;configure video mode comment this out when trying to display text, obviously
    mov ah, 0x00
    mov al, 0x13
    int 0x10

    ;switch to 32-bits
    call switch_to_pm

    jmp $                               ;halt the program in case something went wrong

[BITS 16]
;16-bit routines
%include "Bootloader\Functions\print_string.asm"
%include "Bootloader\Functions\disk_load.asm"
%include "Bootloader\Functions\print_hex.asm"
;%include "Bootloader\Functions\segment_test.asm"
%include "Bootloader\Functions\gdt.asm"

;32-bit routines
%include "Bootloader\Functions\print_string_pm.asm"
%include "Bootloader\Functions\switch_to_pm.asm"




[BITS 32]
BEGIN_PM:
    mov ebx, MSG_PROT_MODE
    call print_string_pm

    call KERNEL_OFFSET

    jmp $


;Global variables
BOOT_DRIVE: db 0    ; boot drive number
MSG_REAL_MODE: db "Started in 16-bit Real Mode", 0
MSG_PROT_MODE: db "Successfully landed in 32-bit Protected Mode", 0
MSG_LOAD_KERNEL: db "Loading kernel into memory", 0

times 446 - ($ - $$) db 0   ; The last 6 bytes could be used for "Unique Disk ID" (4 bytes) and "reserved" (2 bytes)