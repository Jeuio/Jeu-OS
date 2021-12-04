//
// Created by jeuio on 28/11/2021.
//

#include "screen.h"
#include "../Kernel/ports.h"

void print(const char* textAddress, short col, short row, unsigned char attribute_byte) {

    /*
     * Color codes: 0 = black, 1 = dark green, 2 = dark blue, 3 = red, 4 = magenta, 5 = brown, 6 = light gray, 7 = gray
     *              8 = dark gray, 9 = light green, 10 = light blue, 11 = dark red, 12 = pink, 13 = yellow, 14 = white
     */

    unsigned char *videoMemory = (unsigned char*) VIDEO_ADDRESS;    //Address of the video memory to be print to

    unsigned short offset;
    if (col >= 0 && row >= 0) { //If a position is specified, set the cursor to the position and print

        offset = row * MAX_COLS + col;
    } else {    //If no position is specified, just print at the current cursor position

        offset = getCursorPosition();
    }

    for (unsigned short i = 0; 1; ++i) {

        //@todo might be optimised by using a char to temporarily store data

        if (textAddress[i] == '\0') {   //If the end of the string is reached, stop printing

            setCursorPosition(offset + i);
            return;
        }
        *(videoMemory + (offset + i) * 2) = textAddress[i];           //Set the ASCII code of the char
        *(videoMemory + (offset + i) * 2 + 1) = attribute_byte;       //Set the color of the printed char
    }
}

void println(const char* textAddress, short col, short row, unsigned char attribute_byte) {

    print(textAddress, col, row, attribute_byte);
    setCursorPosition((getCursorPosition() / MAX_COLS + 1) * MAX_COLS);  //@todo remove division
}

void clearScreen() {

    unsigned char *videoMemory = (unsigned char*) VIDEO_ADDRESS;

    for (int i = 0; i < MAX_ROWS * MAX_COLS * 2; i += 2) {

        *(videoMemory + i) = 0x20;
        *(videoMemory + i + 1) = 0x0f;
    }
    setCursorPosition(0);
}

unsigned short getCursorPosition() {

    /*
     * The position of the cursor is split in two bytes, which can be accessed by first specifying
     * the control register, and reading the data afterwards. A bit shift is used to shift the bits of
     * the first read byte into the right position to allow reading the second byte into the now free
     * bits of the short.
     */
    portByteOut(REG_SCREEN_CTRL, 14);               //Specify to read from the first register
    unsigned short position = portByteIn(REG_SCREEN_DATA) << 8;   //Read from the first register and shift the bits
    portByteOut(REG_SCREEN_CTRL, 15);               //Specify to read from the second register
    position += portByteIn(REG_SCREEN_DATA);             //Read from the second register

    return position;
}

void setCursorPosition(unsigned short position) {

    unsigned char posL = (unsigned char)position;
    unsigned char posH = (unsigned char)(position >> 8);

    portByteOut(REG_SCREEN_CTRL, 14);
    portByteOut(REG_SCREEN_DATA, posH);
    portByteOut(REG_SCREEN_CTRL, 15);
    portByteOut(REG_SCREEN_DATA, posL);
}