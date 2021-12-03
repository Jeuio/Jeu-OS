;bx = memory address to write to
;dh = sectors to read (one sector should be 256 bytes = 0x100, which makes sense when you think about it)
;dl = drive number to be read(?)
disk_load:
    push dx

    mov ah, 0x02    ;BIOS read sector function
    mov al, dh      ;read dh sectors
    mov ch, 0x00    ;cylinder 0
    mov dh, 0x00    ;head 0
    mov cl, 0x02    ;start reading from second sector (i.e. after the boot sector (i.e starting from position 200000))

    int 0x13        ;BIOS interrupt

    jc disk_error   ;jump if carry flag set (error occured)

    pop dx          ;Restore DX from the stack
    cmp dh, al      ;if AL (sectors read) != DH (sectors expected)
    jne disk_error  ;display error message
    ret

    disk_error:

        mov bx, DISK_ERROR_MSG  ;move the pointer of the error message to bx to use it in the print function
        call print_string
        jmp $

;variables
DISK_ERROR_MSG db "Disk read error!", 0