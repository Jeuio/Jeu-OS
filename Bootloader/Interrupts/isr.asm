global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31

isr0:
    push byte 0
    push byte 0
    jmp isr_common_stub

isr1:
    push byte 0
    push byte 1
    jmp isr_common_stub

isr2:
    jmp isr_common_stub

isr3:
    jmp isr_common_stub

isr4:
    jmp isr_common_stub

isr5:
    jmp isr_common_stub

isr6:
    jmp isr_common_stub

isr7:
    jmp isr_common_stub

isr8:
    jmp isr_common_stub

isr9:
    jmp isr_common_stub

isr10:
    jmp isr_common_stub

isr11:
    jmp isr_common_stub

isr12:
    push byte 12
    jmp isr_common_stub

isr13:
    jmp isr_common_stub

isr14:
    jmp isr_common_stub

isr15:
    jmp isr_common_stub

isr16:
    jmp isr_common_stub

isr17:
    jmp isr_common_stub

isr18:
    jmp isr_common_stub

isr19:
    jmp isr_common_stub

isr20:
    jmp isr_common_stub

isr21:
    jmp isr_common_stub

isr22:
    jmp isr_common_stub

isr23:
    jmp isr_common_stub

isr24:
    jmp isr_common_stub

isr25:
    jmp isr_common_stub

isr26:
    jmp isr_common_stub

isr27:
    jmp isr_common_stub

isr28:
    jmp isr_common_stub

isr29:
    jmp isr_common_stub

isr30:
    jmp isr_common_stub

isr31:
    push byte 0
    push byte 31
    jmp isr_common_stub