; There should be an MBR (PMBR) present covering the GPT and the entire disk (up to its maximum of 8GB) (type 0xEE). The PMBR should only be parsed if the GPT is not recognized
; @annotation Refer to https://wiki.osdev.org/GPT

; General layout:
; LBA 0:        PMBR
; LBA 1:        Partition header
; LBA 2..33:    Partition Table Entries
; disk data
; LBA -33..-2   Mirror of Partition Table
; LBA -1        Mirror of Partition Header





; LBA 0: PMBR
; @todo Write bootstrap
; The MBR is ONLY needed when trying to boot from a hard drive
; Only one active partition should be present on the ISO

; 440 Bytes of bootstrap code
; @todo Relocate to the memory address right below 0x7C00
; @todo Let the user select the desired operating system(, if there are multiple(?))

[ORG 0x7A00]
[BITS 16]
cli             ; Stop interrupts

; Set all segments to zero

;set the pointers of the stack
mov bp, 0x9bff          ; Sets the base pointer of the stack
mov sp, bp              ; Set the pointer of the stack

mov ax, 0
mov ds, ax
mov es, ax
mov ss, ax
mov sp, ax

; Copy to 0x7A00
mov cx, 0x100   ; There are 256 words in the MBR
mov si, 0x7C00  ; The location of the MBR in memory
mov di, 0x7A00  ; The new MBR address (right below the former location)
rep movsw       ; Start copying
jmp lowStart

lowStart:
    sti                         ; Start interrupts again

    call print_hex

    mov BYTE [BOOT_DRIVE], dl   ; Save the boot drive index
    mov bx, PT1                 ; Set the bx pointer to the start of the first partition
    mov cl, 3                   ; There are four partitions in the table
    mov ch, 0                   ; This will be a bit set, indicating which partitions are bootable

searchLoop:
    mov al, BYTE [bx]   ; Set al to the first byte of the partition (indicator, whether the partition is used)
    cmp al, 0x80        ; Compare al to 0x80 (indicator, that the partition is bootable)
    je bootable         ; If the partition is bootable
    continueLoop:
    cmp cl, 0           ; Test, whether cl is zero (if the loop has reached the end)
    je done             ; If the loop has finished and no bootable partition was found, quit the program
    dec cl              ; Decrease cl by one
    add bx, 0x10        ; Move bx to the start of the next partition
    jmp searchLoop      ; Repeat

bootable:
    mov dh, 1
    shl dh, cl          ; Shift the one stored in dh cx places to the right (will be 0b1000 if the first partition is bootable and so on)
    or ch, dh           ; Perform an or operation with dh on ch (e.g. P1 and P3 are bootable: 0b1010)
    jmp continueLoop    ; Continue with the loop

done:
    cmp ch, 1
    jl error        ; If there are 0 bootable partitions, throw an error
    jmp select      ; Let the user select the partition to boot from

select:
    mov bx, SELECT_MSG
    call print_string   ; Display: "Select your operating system:"
    call new_line
    mov cl, 4           ; Prepare the cl register for the selectLoop

selectLoop:
    dec cl
    mov dh, ch
    shr dh, cl
    and dh, 0b0001
    cmp dh, 1
    je printDiskNumber
    continueDiskLoop:
    cmp cl, 0
    jne selectLoop
    jmp waitForInput

printDiskNumber:
    mov al, 0x33
    sub al, cl
    mov bx, PT_MSG
    call print_string
    call print_char
    call new_line
    jmp continueDiskLoop

waitForInput:
    mov ax, 0x00
    int 0x16
    cmp al, '0'
    je boot
    cmp al, '1'
    je boot
    cmp al, '2'
    je boot
    cmp al, '3'
    je boot
    jmp waitForInput

boot:
    mov cl, 0x33
    sub cl, al
    mov dh, ch
    shr dh, cl
    and dh, 1
    cmp dh, 1
    jne waitForInput
    mov bx, BOOT_MSG
    call print_string
    call print_char

    mov bx, PT1
    mov ch, cl
    mov cl, 3
    sub cl, ch
    shl cl, 4
    mov ch, 0
    add bx, cx
    mov WORD [PTOffset], bx

    ; @fixme The call itself seems to be performed without any errors being thrown, but either the LBA-value in the MBR is wrong or the buffer pointer is set wrong (the website mentions something about that)
    add bx, 8                               ; Mov bx to the part of the partition specifying the starting LBA
    mov ah, 0x42                            ; Extended read mode
    mov dl, [BOOT_DRIVE]
    mov cl, 1
    mov [DAPS_SECTORS_TO_READ], cl          ; Read only the first sector
    mov cx, WORD [bx]
    mov [DAPS_STARTING_LBA_L], cx
    add bx, 2
    mov cl, BYTE [bx]
    mov [DAPS_STARTING_LBA_H], cl
    mov bx, 0x7C00
    mov [DAPS_BUFFER], bx
    mov si, DAPS
    int 0x13                                ; Perform the read
    jc readError

    jmp bx                                  ; Jump to the read sector

    readError:
        call new_line
        mov bx, DISK_ERROR_MSG
        call print_string
        mov ah, 0x01    ; error detection mode
        int 0x13
        mov dl, ah
        call print_hex
        jmp $



; @todo Load the first sector at [bx] from the disk to 0x7C00 and jump to the start of it. Don't forget to reset all registers

error:
    mov bx, ERROR_MSG
    call print_string   ; Display: "No bootable medium found!"
    jmp $               ; Halt

%include "Bootloader/Functions/print_string.asm"
%include "Bootloader/Functions/print_hex.asm"

; Disk Address Packet Structure
DAPS:
db 0x10
db 0x0
DAPS_SECTORS_TO_READ dw 0x0000
DAPS_BUFFER dd 0x0000
DAPS_STARTING_LBA_L dd 0x0000
DAPS_STARTING_LBA_H dd 0x0000


; Fields
BOOT_DRIVE db 0
PTOffset dw 0
SELECT_MSG: db "Select partition:", 0
PT_MSG: db "PT: ", 0
BOOT_MSG: db "Booting from ", 0
DISK_ERROR_MSG: db "Disk error: ", 0
ERROR_MSG: db "No bootable medium!", 0

times 440 - ($ - $$) db 0   ; Pad until 440 bytes

; The following 6 bytes can be used as additional space for the bootstrap
; 4 Bytes of "Unique Disk ID"
dd 0x00000000

; 2 Bytes (Default 0x0000)
dw 0x0000

; Partition 1
PT1:
db 0x80         ; Set partition to active
db 0x00         ; Starting head
db 0b00000000   ; Starting sector   (6 bits, the remaining 2 bits are the upper bits of "Starting Cylinder"
db 0b00000000   ; Starting Cylinder (10 bits)
db 0x01         ; System ID
db 0x00         ; Ending Head
db 0b00000000   ; Ending Sector (6 bits, the remaining 2 bits are the upper bits of "Ending Cylinder"
db 0b00000000   ; Ending Cylinder
dd 0x22         ; Relative Sector (to start of partition -- also equals the partition's starting LBA value)
dd 0x100        ; Total Sectors in partition

; Partition 2
PT2:
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
PT3:
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
PT4:
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

times 510 - ($ - $$) db 0
dw 0xAA55





; LBA 1: Partition Table Header
db "EFI PART"           ; Signature @todo check if the magic number is in the right order

dd 0x00000000           ; GPT Revision
dd 0x00000000           ; Header size
dd 0x00000000           ; CRC32 checksum of the GPT header (0x0 to 0x5c)
dd 0x00000000           ; Reserved (0x00000000)

dq 0x0000000000000000   ; LBA containing this header
dq 0x0000000000000000   ; The LBA of the alternate GPT header
dq 0x0000000000000000   ; The first usable block that can be contained in a GPT entry
dq 0x0000000000000000   ; The last usable block that can be contained in a GPT entry

db "                "   ; GUID of the disk (16 bytes)
dq 0x0000000000000002   ; Starting LBA of the GUID Partition Entry array (We will use LBA 2)
dd 0x00000000           ; Number of Partition Entries
dd 0x00000000           ; Size (in bytes) of each entry in the Partition Entry array - must be a value of 128 * 2^n where n >= 0

dd 0x00000000           ; CRC32 of the Partition Entry array
times 0x400 - ($ - $$) db 0 ; Zero the rest of the block (a block size of 512 bytes is assumed)





; LBA 2: Partition Entries
; See EFI System Partition https://wiki.osdev.org/EFI_System_Partition
db "                "   ; Partition Type GUID (zero = unused) (16 bytes)
db "                "   ; Unique Partition GUID (16 bytes)
dq 0x0000000000000000   ; Starting LBA
dq 0x0000000000000000   ; Ending LBA
dq 0b0000000000000000000000000000000000000000000000000000000000000000   ; Attributes (Bit set) (0b1 = Required by firmware, 0b10 = Necessary for boot)
db "                                                                        "   ; Partition name (72 bytes) "Name is UNICODE16-LE encoded, meaning it can only store the UNICODE Bilingual Plane (code points 32 to 65535), and each character consumes 2 bytes. However the EFI spec defines name length as 72 bytes (36 characters), you should never hard-code this into your application. Always use (Partition Entry Size in header at 0x54) - 0x38 instead."

times 0x4400 - ($ - $$) db 0    ; Fill the remaining LBAs until LBA 33 with zeros

; @todo Somehow put a copy of the Partition header and the Partition tables at the end of the hard drive (Preferably in the PMBR)