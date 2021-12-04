//
// Created by jeuio on 01/12/2021.
//

#include "../ports.h"   //@todo move this to header

/**
 * See this link for explanation: https://dev.to/frosnerd/writing-my-own-keyboard-driver-16kh
 */
typedef struct {
    unsigned short lowOffset;
    unsigned short selector;
    unsigned char always0;
    unsigned char flags;
    unsigned short highOffset;
} __attribute__((packed)) idt_gate_t;

typedef struct {

    unsigned int ds;
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
    unsigned int int_no, err_code;
    unsigned int eip, cx, eflags, useresp, ss;
} registers_t;


idt_gate_t idt[256];

const char *exceptionMessages[] = {
        "Division by zero",
        "Debug",
        "Reserved"
};

void setIdtGate(int n, unsigned int handler) {

    idt[n].lowOffset = (unsigned short)handler;
    idt[n].selector = 0x08; //@todo might be changed. Turorial says 'see GDT' here
    idt[n].always0 = 0;
    idt[n].flags = 0b10001110;
    idt[n].highOffset = (unsigned short)(handler >> 16);
}

void isrHandler(registers_t *r) {

    println(exceptionMessages[r->int_no], -1, -1, 0x03);
}

void isrInstall() {

    //Internal ISRs
    setIdtGate(0, unsigned int isr0);
    setIdtGate(1, unsigned int isr1);
    setIdtGate(2, unsigned int isr2);
    setIdtGate(3, unsigned int isr3);
    setIdtGate(4, unsigned int isr4);
    setIdtGate(5, unsigned int isr5);
    setIdtGate(6, unsigned int isr6);
    setIdtGate(7, unsigned int isr7);
    setIdtGate(8, unsigned int isr8);
    setIdtGate(9, unsigned int isr9);
    setIdtGate(10, unsigned int isr10);
    setIdtGate(11, unsigned int isr11);
    setIdtGate(12, unsigned int isr12);
    setIdtGate(13, unsigned int isr13);
    setIdtGate(14, unsigned int isr14);
    setIdtGate(15, unsigned int isr15);
    setIdtGate(16, unsigned int isr16);
    setIdtGate(17, unsigned int isr17);
    setIdtGate(18, unsigned int isr18);
    setIdtGate(19, unsigned int isr19);
    setIdtGate(20, unsigned int isr20);
    setIdtGate(21, unsigned int isr21);
    setIdtGate(22, unsigned int isr22);
    setIdtGate(23, unsigned int isr23);
    setIdtGate(24, unsigned int isr24);
    setIdtGate(25, unsigned int isr25);
    setIdtGate(26, unsigned int isr26);
    setIdtGate(27, unsigned int isr27);
    setIdtGate(28, unsigned int isr28);
    setIdtGate(29, unsigned int isr29);
    setIdtGate(30, unsigned int isr30);
    setIdtGate(31, unsigned int isr31);


    //PIC remapping
    portByteOut(0x20, 0x11);
    portByteOut(0xA0, 0x11);

    portByteOut(0x21, 0x20);
    portByteOut(0xA1, 0x28);

    portByteOut(0x21, 0x04);
    portByteOut(0xA1, 0x02);

    portByteOut(0x21, 0x01);
    portByteOut(0xA1, 0x01);

    portByteOut(0x21, 0x0);
    portByteOut(0xA1, 0x0);


    //IRQ ISRs
    //Primary PIC
    setIdtGate(32, (unsigned int)irq0);
    setIdtGate(39, (unsigned int)irq7);

    //Secondary PIC
    setIdtGate(40, (unsigned int)irq8);
    setIdtGate(47, (unsigned int)irq15);
}