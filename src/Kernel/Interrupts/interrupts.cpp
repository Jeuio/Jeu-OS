//
// Created by jeuio on 01/12/2021.
//


#include "../ports.h"   //@todo move this to header
#include "../../Drivers/screen.h"
#include "idt.h"
#include "isr.h"

isr_t  interruptHandlers[256];

idt_gate_t idt[256];

idt_register_t idtReg;

const char *exceptionMessages[] = {
        "Division By Zero",
        "Debug",
        "Non Maskable Interrupt",
        "Breakpoint",
        "Into Detected Overflow",
        "Out of Bounds",
        "Invalid Opcode",
        "No Coprocessor",

        "Double Fault",
        "Coprocessor Segment Overrun",
        "Bad TSS",
        "Segment Not Present",
        "Stack Fault",
        "General Protection Fault",
        "Page Fault",
        "Unknown Interrupt",

        "Coprocessor Fault",
        "Alignment Check",
        "Machine Check",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",

        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved"
};

void setIdtGate(int n, unsigned int handler) {

    idt[n].lowOffset = (unsigned short)handler;
    idt[n].selector = 0x08; //@todo might be changed. Tutorial says 'see GDT' here
    idt[n].always0 = 0;
    idt[n].flags = 0x8e;
    idt[n].highOffset = (unsigned short)(handler >> 16);
}

void isrHandler(registers_t *r) {
;
    println(exceptionMessages[r->int_no], -1, -1, 0x03);
}

void irqHandler(registers_t *r) {

    if (interruptHandlers[r->int_no] != 0) {

        isr_t handler = interruptHandlers[r->int_no];
        handler(r);
    }

    if (r->int_no >= 40) {

        portByteOut(0xA0, 0x20);
    }
    portByteOut(0x20, 0x20);
}

void loadIdt() {

    idtReg.base = (unsigned int) &idt;
    idtReg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
    asm volatile("lidt (%0)" : : "r" (&idtReg));
}

void registerInterruptHandler(unsigned char n, isr_t handler) {

    interruptHandlers[n] = handler;
}

void isrInstall() {

    //Internal ISRs
    setIdtGate(0, (unsigned int)isr0);
    setIdtGate(1, (unsigned int)isr1);
    setIdtGate(2, (unsigned int)isr2);
    setIdtGate(3, (unsigned int)isr3);
    setIdtGate(4, (unsigned int)isr4);
    setIdtGate(5, (unsigned int)isr5);
    setIdtGate(6, (unsigned int)isr6);
    setIdtGate(7, (unsigned int)isr7);
    setIdtGate(8, (unsigned int)isr8);
    setIdtGate(9, (unsigned int)isr9);
    setIdtGate(10, (unsigned int)isr10);
    setIdtGate(11, (unsigned int)isr11);
    setIdtGate(12, (unsigned int)isr12);
    setIdtGate(13, (unsigned int)isr13);
    setIdtGate(14, (unsigned int)isr14);
    setIdtGate(15, (unsigned int)isr15);
    setIdtGate(16, (unsigned int)isr16);
    setIdtGate(17, (unsigned int)isr17);
    setIdtGate(18, (unsigned int)isr18);
    setIdtGate(19, (unsigned int)isr19);
    setIdtGate(20, (unsigned int)isr20);
    setIdtGate(21, (unsigned int)isr21);
    setIdtGate(22, (unsigned int)isr22);
    setIdtGate(23, (unsigned int)isr23);
    setIdtGate(24, (unsigned int)isr24);
    setIdtGate(25, (unsigned int)isr25);
    setIdtGate(26, (unsigned int)isr26);
    setIdtGate(27, (unsigned int)isr27);
    setIdtGate(28, (unsigned int)isr28);
    setIdtGate(29, (unsigned int)isr29);
    setIdtGate(30, (unsigned int)isr30);
    setIdtGate(31, (unsigned int)isr31);


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
    setIdtGate(33, (unsigned int)irq1);
    setIdtGate(34, (unsigned int)irq2);
    setIdtGate(35, (unsigned int)irq3);
    setIdtGate(36, (unsigned int)irq4);
    setIdtGate(37, (unsigned int)irq5);
    setIdtGate(38, (unsigned int)irq6);
    setIdtGate(39, (unsigned int)irq7);

    //Secondary PIC
    setIdtGate(40, (unsigned int)irq8);
    setIdtGate(41, (unsigned int)irq9);
    setIdtGate(42, (unsigned int)irq10);
    setIdtGate(43, (unsigned int)irq11);
    setIdtGate(44, (unsigned int)irq12);
    setIdtGate(45, (unsigned int)irq13);
    setIdtGate(46, (unsigned int)irq14);
    setIdtGate(47, (unsigned int)irq15);

    loadIdt();
}