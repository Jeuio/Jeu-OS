#include "../Drivers/screen.h"
#include "../Drivers/keyboard.h"
#include "../Drivers/graphics.h"
#include "Interrupts/isr.h"

#include "../ChessGame/Game.h"



#include "../Librarys/Fonts.h"

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
    //testGraphics();

    //for (unsigned char i = 0; i < 26; ++i) {

    //    graphicsPrint(i, i, 0);
    //}

    println("Starting the chess game");

    ChessGame::start();

    return 0;
}