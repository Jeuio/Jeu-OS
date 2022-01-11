;bx = memory address to write to
;dh = sectors to read (one sector should be 256 bytes = 0x100, which makes sense when you think about it)
;dl = drive to be read
disk_load:
    push dx

    mov ah, 0x02    ; Read mode
    mov al, dh      ;read dh sectors
    mov ch, 0x00    ;cylinder 0
    mov dh, 0x00    ;head 0
    mov cl, 0x02    ; which sector to start reading at (for disk: 2)

    int 0x13        ;BIOS interrupt

    jc disk_error   ;jump if carry flag set (error occurred)

    pop dx          ;Restore DX from the stack
    cmp dh, al      ;if AL (sectors read) != DH (sectors expected)
    jne disk_error  ;display error message // @todo re-enable
    ret

    disk_error:

        mov bx, DISK_ERROR_MSG  ;move the pointer of the error message to bx to use it in the print function
        call print_string

        mov ah, 0x01    ; error detection mode
        int 0x13
        mov dl, ah
        call print_hex

        jmp $

;variables
DISK_ERROR_MSG db "Disk read error: ", 0