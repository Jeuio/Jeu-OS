[BITS 16]
;dx = hex value that should be printed
print_hex:
    pusha                   ;push all registers to the stack
    
    mov cx, 0x4             ;counter is set to 4

    char_loop:
        dec cx              ;counter is decremented

        mov ax, dx          ;move the hex value to ax
        and ax, 0xf000      ;map ax to the first byte
        shr ax, 12          ;shift ax 12 bits to the right (i.e. 3 bytes (0xf000 -> 0x000f)
        shl dx, 4           ;shift dx 4 bits to the left

        cmp al, 0xa         ;compares the last character of the input hex value to 0xa
        jl print            ;if the character is a number jump to the print part
        add al, 7           ;otherwise add 7 first

        print:
            mov ah, 0x0e    ;set some very very important stuff for the int 0x10 call i have literally no clue of
            add al, 0x30    ;the character to be printed on the screen in ascii
            int 0x10        ;call 0x10 to print a character to the screen
            cmp cx, 0x0     ;compares cx to 0
            jg char_loop    ;if cx is bigger than 0 loop back to the beginning

    popa                    ;restore register values
    ret                     ;return to function call