//
// Created by jeuio on 28/11/2021.
//

#include "screen.h"
#include "../Kernel/ports.h"
#include "../Librarys/Fonts.h"
#include "graphics.h"

void print(const char *textAddress, short col, short row, unsigned char attribute_byte) {

    /*
     * Color codes: 0 = black, 1 = dark green, 2 = dark blue, 3 = red, 4 = magenta, 5 = brown, 6 = light gray, 7 = gray
     *              8 = dark gray, 9 = light green, 10 = light blue, 11 = dark red, 12 = pink, 13 = yellow, 14 = white
     */

    unsigned char *videoMemory = (unsigned char *) VIDEO_ADDRESS;    //Address of the video memory to be print to

    unsigned short offset;
    if (col >= 0 && row >= 0) { //If a position is specified, set the cursor to the position and print

        offset = row * MAX_COLS + col;
    } else {    //If no position is specified, just print at the current cursor position

        offset = getCursorPosition();
    }

    for (unsigned short i = 0; 1; ++i) {

        if (textAddress[i] == '\0') {   //If the end of the string is reached, stop printing

            setCursorPosition(offset + i);
            return;
        }

        *(videoMemory + (offset + i) * 2) = textAddress[i];           //Set the ASCII code of the char
        *(videoMemory + (offset + i) * 2 + 1) = attribute_byte;       //Set the color of the printed char

        if (offset + i >= (MAX_ROWS - 1) * MAX_COLS - 1) {
            offset -= MAX_COLS;
            scroll(1);
        }
    }
}

void println(const char *textAddress, short col, short row, unsigned char attribute_byte) {

    print(textAddress, col, row, attribute_byte);
    setCursorPosition((getCursorPosition() / MAX_COLS + 1) * MAX_COLS);
}

void graphicsPrint(unsigned char letter, unsigned char col, unsigned char row) {

    for (unsigned char i = 0; i < 10; ++i) {

        for (unsigned char j = 0; j < 8; ++j) {

            if (Fonts::Custom::characters[letter][i] >> (7 - j) & 1) {

                drawPixel(j + col * 9, i + row * 10, 0b11111111);
            } else {

                drawPixel(j + col * 9, i + row * 10, 0b00000000);
            }

        }
    }
    flush();
}

void backspace() {

    unsigned short cPos = getCursorPosition();
    if (cPos > 0) {

        unsigned char *videoAddress = (unsigned char *) VIDEO_ADDRESS;
        *(videoAddress + (cPos - 1) * 2) = 0x20;
        *(videoAddress + (cPos - 1) * 2 + 1) = VGA_WHITE_ON_BLACK;
        setCursorPosition(cPos - 1);
    }
}

void scroll(unsigned char lines) {

    unsigned char *videoAddress = (unsigned char *) VIDEO_ADDRESS;

    unsigned char i;
    for (i = 0; i < MAX_ROWS - lines; ++i) {

        for (unsigned char j = 0; j < MAX_COLS; ++j) {

            *(videoAddress + (i * MAX_COLS + j) * 2) = *(videoAddress + ((i + lines) * MAX_COLS + j) * 2);
            *(videoAddress + (i * MAX_COLS + j) * 2 + 1) = *(videoAddress + ((i + lines) * MAX_COLS + j) * 2 + 1);
        }
    }
    for (unsigned char k = i; k < MAX_ROWS; ++k) {

        for (unsigned char j = 0; j < MAX_COLS; ++j) {

            *(videoAddress + ((i * MAX_COLS) + j) * 2) = 0x20;
            *(videoAddress + ((i * MAX_COLS) + j) * 2 + 1) = 0x0f;
        }
    }

    setCursorPosition((getCursorPosition() / MAX_COLS - lines) * MAX_COLS);
}

void clearScreen() {

    unsigned char *videoMemory = (unsigned char *) VIDEO_ADDRESS;

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

    unsigned char posL = (unsigned char) position;
    unsigned char posH = (unsigned char) (position >> 8);

    portByteOut(REG_SCREEN_CTRL, 14);
    portByteOut(REG_SCREEN_DATA, posH);
    portByteOut(REG_SCREEN_CTRL, 15);
    portByteOut(REG_SCREEN_DATA, posL);
}