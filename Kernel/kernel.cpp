#include "../Drivers/screen.h"
#include "../Drivers/keyboard.h"
#include "../Drivers/graphics.h"
#include "Interrupts/idt.h"
#include "Interrupts/isr.h"

#include "../ChessGame/PieceDisplay.h"
#include "../ChessGame/Piecegraphics.h"

// @annotation If something doesn't work as intended: 1. Remember to make EVERY constants used throughout the project 'const' they will be put into the .data segment otherwise, which will not be put into the final bin-file.
// @annotation                                        2. Use the 'objdump -s' command to show the exact content of each segment

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

    println("Drawing a chess board");
    drawChessBoard();

    for (unsigned short i = 0; i < 100; ++i) {

        drawPixel(i, 100, 0b10001001);
    }




    // @todo put this into its own function
    for (unsigned char i = 0; i < 8; ++i) {

        displayPiece(PieceData::pawn, 60 + i * 25, 26, 0b10101010);
    }
    for (unsigned char i = 0; i < 8; ++i) {

        displayPiece(PieceData::pawn, 60 + i * 25, 151, 0b10101010);
    }
    displayPiece(PieceData::rook, 60, 1, 0b10101010);
    displayPiece(PieceData::rook, 60, 176, 0b10101010);
    displayPiece(PieceData::rook, 235, 1, 0b10101010);
    displayPiece(PieceData::rook, 235, 176, 0b10101010);

    displayPiece(PieceData::knight, 85, 1, 0b10101010);
    displayPiece(PieceData::knight, 85, 176, 0b10101010);
    displayPiece(PieceData::knight, 210, 1, 0b10101010);
    displayPiece(PieceData::knight, 210, 176, 0b10101010);

    displayPiece(PieceData::bishop, 110, 1, 0b10101010);
    displayPiece(PieceData::bishop, 110, 176, 0b10101010);
    displayPiece(PieceData::bishop, 185, 1, 0b10101010);
    displayPiece(PieceData::bishop, 185, 176, 0b10101010);

    displayPiece(PieceData::queen, 135, 1, 0b10101010);
    displayPiece(PieceData::queen, 135, 176, 0b10101010);

    displayPiece(PieceData::king, 160, 1, 0b10101010);
    displayPiece(PieceData::king, 160, 176, 0b10101010);


    return 0;
}