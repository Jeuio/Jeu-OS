#include "../Drivers/screen.h"
#include "../Drivers/Keyboard.h"
#include "Interrupts/idt.h"
#include "Interrupts/isr.h"

extern "C" int kernel_main() {

    clearScreen();
    println("Welcome to Jeu-OS!ßüäöÜÄÖ", 30, 0);
    println("Installing interrupt service routines (ISRs)");
    isrInstall();
    println("Enabling external interrupts");
    asm volatile("sti");
    println("Initializing keyboard (IRQ 1)");
    initKeyboard();

    return 0;
}