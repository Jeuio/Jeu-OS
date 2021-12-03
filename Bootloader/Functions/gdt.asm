[BITS 16]
;generall gdt structure in order (8 bytes in total):
;2 bytes = first part of the limit
;3 bytes = first part of the base
;4 bits  = 1st flags
;4 bits  = type flags
;4 bits  = 2nd flags
;4 bits  = second part of the limit
;1 byte  = second part of the base

;1st flags in order:
;1 bit  = present (set to 1 if present in memory. should only be 0 if virtual memory is used)
;2 bits = privilege (0 is the highest privilege)
;1 bit  = descriptor type (1 for code/data segments. 0 for traps(dunno waddad is))

;2nd flags in order:
;1 bit = granularity (if set to 1 the limit will be multiplied by 16*16*16 (shifted 3 hex digits to the left) for more segment coverage (maximum of 4GB)
;1 bit = 32-bit default (0 for 16-bit values, 1 for 32-bit values)
;1 bit = 64-bit segment (1 for 64-bit values)
;1 bit = AVL (whatever that might be)

;type flags in order:
;1 bit = code (1 if this is code. 0 if it is data)
;1 bit = code:  conforming (if this is 0 this code can not be called by segments with lower privilege)  data:   expand down (0 makes the segment expand down. explanaition required)
;1 bit = code:  readable (1 for readable. 0 for execute-only)                                           data:   writable (1 makes the data segment writable)
;1 bit = accessed (for debugging purposes. is set when the cpu accesses bytes of the segment)

gdt_start:                          ;for marking the start of the gdt

;writes 8 bytes of zeros
gdt_null:                           ;required for the processor to know that we didn't make any mistakes for reasons we do not fully understand
    dd 0x0                          ;writes 4 bytes of zeros (0x0000)
    dd 0x0                          ;writes 4 bytes of zeros again (0x0000)

;defines the gdt_code segment
gdt_code:
    ;limit: 0xffff f (000)
    ;base:  0x0
    dw 0xffff                       ;limit (bits 0-15)
    dw 0x0                          ;base (bits 0-15)
    db 0x0                          ;base (bits 16-23)
    db 10011010b                    ;1st flags (present, highest privilege, code/data)  /  type flags (code, conforming, readable, unaccessed)
    db 11001111b                    ;2nd flags ('extened segment' (4GB potential), 32-bit mode, not 64-bit mode, no AVL)  /  limit (bits 16-19)
    db 0x0                          ;base (bits 24-31)

gdt_data:
    ;limit: 0xffff f (000)
    ;base:  0x0
    dw 0xffff                       ;limit (bits 0-15)
    dw 0x0                          ;base (bits 0-15)
    db 0x0                          ;base (bits 16-23)
    db 10010010b                    ;1st flags (present, highes privilege, code/data)  /  type flags (data, extends below, writable, unaccessed)
    db 11001111b                    ;2nd flags ('extended segment' (4GB potential), 32-bit mode, not 64-bit mode, no AVL)  /  limit (bits 16-19)
    db 0x0                          ;base (bits 24-31)

gdt_end:                            ;for marking the end of the gdt

gdt_descriptor:                     ;general purpose of the gdt_descriptor is to let the cpu know where gdt's are
    dw gdt_end - gdt_start - 1      ;size of the gdt (2 byte)
    dd gdt_start                    ;start address of the gdt (1 byte)

CODE_SEG equ gdt_code - gdt_start   ;stores the offset of gtd_code to be used in offsetting segments
DATA_SEG equ gdt_data - gdt_start   ;stores the offset of gtd_data to be used in offsetting segments