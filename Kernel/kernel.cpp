#include "../Drivers/screen.h"
#include "../Drivers/keyboard.h"
#include "../Drivers/graphics.h"
#include "Interrupts/idt.h"
#include "Interrupts/isr.h"

extern "C" int kernel_main() {

    clearScreen();

    println("Welcome to Jeu-OS!", 30, 0);
    println("Installing interrupt service routines (ISRs)");
    isrInstall();
    println("Enabling external interrupts");
    asm volatile("sti");
    println("Initializing keyboard (IRQ 1)");
    initKeyboard();

    initScreen(COLOR_256_LINEAR);

    testGraphics();

    drawChessBoard();

    return 0;
}