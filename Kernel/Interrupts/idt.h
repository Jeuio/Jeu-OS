//
// Created by jeuio on 04/12/2021.
//

#pragma once

#define IDT_ENTRIES 256

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

    unsigned short limit;
    unsigned int base;
} __attribute__((packed)) idt_register_t;

void setIdtGate(int n, unsigned int handler);

void loadIdt();