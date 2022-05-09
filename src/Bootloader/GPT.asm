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
mov ax, 0
mov ds, ax
mov es, ax
mov ss, ax
mov sp, ax

.copyLower:
mov cx, 0x100   ; There are 256 words in the MBR
mov si, 0x7C00  ; The location of the MBR in memory
mov di, 0x7A00  ; The new MBR address (right below the former location)
rep movsw       ; Start copying
jmp 0:lowStart

lowStart:
sti             ; Start interrupts again
mov bx, SELECT_MSG
call print_string
jmp $

%include "Bootloader/Functions/print_string.asm"
SELECT_MSG: db "Select your operating system:"

times 440 - ($ - $$) db 0   ; Pad until 440 bytes

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