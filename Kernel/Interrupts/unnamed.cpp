//
// Created by jeuio on 01/12/2021.
//

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