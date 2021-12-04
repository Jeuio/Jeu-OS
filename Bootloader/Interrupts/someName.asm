[extern isrHandler]

isr_common_stub:
    pusha

    mov ax, ds
    push eax

    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    push esp

    call isrHandler

    pop eax

    pop eax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    popa

    add esp, 8

    iret