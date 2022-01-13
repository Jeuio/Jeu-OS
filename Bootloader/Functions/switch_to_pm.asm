[BITS 16]

switch_to_pm:
    cli                                 ;disables BIOS interrupt calls
    lgdt [gdt_descriptor]               ;passes the GDT descriptor

    mov eax, cr0                        ;stores the content of cr0 in eax
    or eax, 0x1                         ;sets the first bit of eax to 1 and leaves the rest unchanged. the flag at position 1 of cr0 is for switching to 32-bit mode
    mov cr0, eax                        ;sets cr0 to eax. the cpu is now - mostly - in 32-bit mode

    jmp CODE_SEG:init_pm                ;performs a far jump to make sure the pipeline is empty so the cpu is sure to be fully switched into 32-bit mode


[BITS 32]
init_pm:
    mov ax, DATA_SEG    ;sets ax to the offset of the data segment
    mov ds, ax          ;sets all segments to the offset of the data segment
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x150000   ;moves the base pointer of the stack
    mov esp, ebp

    call BEGIN_PM