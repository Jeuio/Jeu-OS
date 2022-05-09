; @todo Write bootstrap
; The MBR is ONLY needed when trying to boot from a hard drive
; Only one active partition should be present on the ISO

; 440 Bytes of bootstrap code
; @todo Relocate to the memory address right below 0x7C00
; @todo Let the user select the desired operating system(, if there are multiple(?))

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

times 440 - ($ - $$) db 0

; The following 6 bytes can be used as additional space for the bootstrap
; 4 Bytes of "Unique Disk ID"
dd 0x00000000

; 2 Bytes (Default 0x0000)
dw 0x0000

; Partition 1
db 0x80         ; Set partition to active
db 0x00         ; Starting head
db 0b00000100   ; Starting sector   (6 bits, the remaining 2 bits are the upper bits of "Starting Cylinder"
db 0b00000000   ; Starting Cylinder (10 bits)
db 0x01         ; System ID
db 0x00         ; Ending Head
db 0b11111100   ; Ending Sector (6 bits, the remaining 2 bits are the upper bits of "Ending Cylinder"
db 0b00000000   ; Ending Cylinder
dd 0x01         ; Relative Sector (to start of partition -- also equals the partition's starting LBA value)
dd 0x20         ; Total Sectors in partition

; Partition 2
db 0x00
db 0x00
db 0b00000000
db 0b00000000
db 0x00
db 0x00
db 0b00000000
db 0b00000000
dd 0x00
dd 0x00

; Partition 3
db 0x00
db 0x00
db 0b00000000
db 0b00000000
db 0x00
db 0x00
db 0b00000000
db 0b00000000
dd 0x00
dd 0x00

; Partition 4
db 0x00
db 0x00
db 0b00000000
db 0b00000000
db 0x00
db 0x00
db 0b00000000
db 0b00000000
dd 0x00
dd 0x00

dw 0xAA55