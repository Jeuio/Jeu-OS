[BITS 16]
segment_test:
    pusha               ;pushes all registers to the stack
    mov ax, 0xff        ;sets the value of ax to 0x00ff
    mov bx, 0x8000      ;sets the value for bx
    mov es, bx          ;sets the start of the segment to bx (0x8000)
    mov [es:0x500], ax  ;writes ax to es * 4 + 0x500 ( (0x8000 -> 0x80000) + 0x500 = 0x80500)
    mov dx, [es:0x500]  ;sets dx to the value of 0x80500
    call print_hex      ;prints out the value of dx
    popa                ;restores all the registers from the stack
    retn                ;returns the function