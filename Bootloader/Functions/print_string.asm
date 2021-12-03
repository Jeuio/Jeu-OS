[BITS 16]
;bx is the pointer of the string
print_string:
    pusha                   ;pushes all registers to the stack
    mov ah, 0x0e            ;sets parameters for tele-interrupt

        print_string_loop:
        mov al, [bx]            ;sets the character that is to be printed
        cmp al, 0x0             ;checks if the character is zero
        je .end                 ;jumps to end if so

        int 0x10                ;otherwise print the character
        inc bx                  ;'selects' the next character of the string
        jmp print_string_loop   ;goes back to the top

    .end:
        popa                ;pops all registers from the stack
        ret                 ;return to the location of the function call