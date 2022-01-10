#include "../Drivers/screen.h"
#include "../Drivers/keyboard.h"
#include "../Drivers/graphics.h"
#include "Interrupts/idt.h"
#include "Interrupts/isr.h"

#include "../ChessGame/Game.h"

// @annotation If something doesn't work as intended: 1. Remember to make EVERY constants used throughout the project 'const' they will be put into the .data segment otherwise, which will not be put into the final bin-file.
// @annotation                                        2. Use the 'objdump -s' command to show the exact content of each segment

// @annotation i've noticed that data is redundant in the final bin file, wasting my precious memory

extern "C" int kernel_main() {

    clearScreen();

    println("Welcome to Jeu-OS!", 30, 0);
    println("Installing interrupt service routines (ISRs)");
    isrInstall();
    println("Enabling external interrupts");
    asm volatile("sti");
    println("Initializing keyboard (IRQ 1)");
    initKeyboard();

    println("Starting graphics mode");
    initScreen(COLOR_256_LINEAR);

    println("Drawing test graphics to the screen");
    testGraphics();

    println("Starting the chess game");

    ChessGame::start();

    return 0;
}