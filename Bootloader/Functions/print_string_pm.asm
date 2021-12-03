[BITS 32]
;some constants
VIDEO_MEMORY equ 0xb8000    ;location of the video memory
WHITE_ON_BLACK equ 0x40     ;color, i guess. First byte for background, second for foreground

;prints a null terminated string pointed to by ebx
print_string_pm:
    pusha
    mov edx, VIDEO_MEMORY           ;set edx to the start of the video memory

    print_string_pm_loop:
        mov al, [ebx]               ;stores the first character stored in the string ebx points to
        mov ah, WHITE_ON_BLACK      ;sets the color of the character

        cmp al, 0                   ;checks if the character is zero
        je print_string_pm_done     ;jumps to the end, if it is zero

        mov [edx], ax               ;sets the content of the video memory address to ax (i.e. our defined character)

        add ebx, 1                  ;increments the string pointer
        add edx, 2                  ;adds 2 to the video memory pointer, since we are setting 2 bytes per iteration

        jmp print_string_pm_loop    ;loops again, until a null character is detected

        print_string_pm_done:
            popa
            ret