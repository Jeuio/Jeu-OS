[BITS 16]
; bx is the pointer to the string
print_string:
    pusha                   ; Pushes all registers to the stack
    mov ah, 0x0e            ; Sets parameters for tele-interrupt

        print_string_loop:
        mov al, [bx]            ; Sets the character that is to be printed
        cmp al, 0x0             ; Checks if the character is zero
        je .end                 ; Jumps to end if so

        int 0x10                ; Otherwise print the character
        inc bx                  ; Selects the next character of the string
        jmp print_string_loop   ; Goes back to the top

    .end:
        popa                ; Pops all registers from the stack
        ret                 ; Return to the location of the function call

; al is the character in ASCII
print_char:
    pusha
    mov ah, 0x0e
    int 0x10
    popa
    ret

new_line:
    pusha
    mov bh, 0
    mov ah, 0x03    ; For retrieving the cursor position (DH = row, DL = Column)
    int 0x10
    mov dl, 0
    add dh, 1

    mov ah, 0x02    ; Position the cursor in the next row at the start
    int 0x10
    popa
    ret