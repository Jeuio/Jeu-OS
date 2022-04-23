; Include bootstrap before this file

; Only one active partition should be present on the ISO

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

dw 0xaa55