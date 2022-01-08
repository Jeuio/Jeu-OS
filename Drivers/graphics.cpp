//
// Created by jeuio on 08/12/2021.
//

#include "graphics.h"
#include "../Kernel/ports.h"

void initScreen(unsigned char mode) {


    portByteOut(PALETTE_MASK, 0xff);
    portByteOut(PALETTE_WRITE, 0);
    for (unsigned char i = 0; i < 255; ++i) {

        portByteOut(PALETTE_DATA, (((i >> 5) & 0x7) * (256 / 8)) / 4);
        portByteOut(PALETTE_DATA, (((i >> 2) & 0x7) * (256 / 8)) / 4);
        portByteOut(PALETTE_DATA, (((i >> 0) & 0x3) * (256 / 4)) / 4);
    }

    portByteOut(PALETTE_DATA, 255);
    portByteOut(PALETTE_DATA, 255);
    portByteOut(PALETTE_DATA, 255);

    //setMode(mode);    //@todo fix this
}

void setMode(unsigned char mode) {

    portByteOut(0x3c2, 0b00000001);     //Correct  mapping of 0x3d4 register
    portByteOut(0x3d4, 0x11);
    portByteOut(0x3d5, 0b10000000);     //Disable write protection

    switch (mode) {

        case 1:
            //Set the general graphics mode
            portByteIn(0x3da);
            portByteOut(MODE_CONTROL, 0x10);
            portByteOut(MODE_CONTROL, 0x41);

            //Horizontal panning
            portByteOut(MODE_CONTROL, 0x13);
            portByteOut(MODE_CONTROL, 0x00);

            //Miscellaneous Output Register
            portByteOut(0x3c3, 0x63);   //@todo might be source of problem

            //Clock Mode Register
            portByteOut(0x3c4, 0x01);
            portByteOut(0x3c5, 0x01);

            //Memory Mode Register
            portByteOut(0x3c4, 0x04);
            portByteOut(0x3c5, 0x0e);

            //Mode Register
            portByteOut(0x3ce, 0x05);
            portByteOut(0x3cf, 0x40);

            //Miscellaneous Register
            portByteOut(0x3ce, 0x06);
            portByteOut(0x3cf, 0x05);

            //Horizontal Retrace Start
            portByteOut(0x3d4, 0x04);
            portByteOut(0x3d5, 0x54);

            //Horizontal Retrace End
            portByteOut(0x3d4, 0x05);
            portByteOut(0x3d5, 0x80);

            //Maximum Scan Line
            portByteOut(0x3d4, 0x09);
            portByteOut(0x3d5, 0x41);

            //Underline Location
            portByteOut(0x3d4, 0x14);
            portByteOut(0x3d5, 0x40);
    }

    portByteOut(0x3d4, 0x11);
    portByteOut(0x3d5, 0b00000000);     //Enable write protection
    portByteOut(0x3c2, 0b00000000);     //Reset  mapping of 0x3d4 register
}

void paletteSet(unsigned short index, RGB rgb) {

    portByteOut(PALETTE_MASK, index);
    portByteOut(PALETTE_DATA, rgb.r);
    portByteOut(PALETTE_DATA, rgb.g);
    portByteOut(PALETTE_DATA, rgb.b);
}

void testGraphics() {

    unsigned char* mem = (unsigned char*)GRAPHICS_ADDRESS;
    for (unsigned int i = 0; i < 64000; ++i) {

        *(mem + i) = i / 250;
    }
}

void drawPixel(unsigned short x, unsigned short y, unsigned char color) {

    *((unsigned char*)GRAPHICS_ADDRESS + y * SCREEN_WIDTH + x) = color;
}

void drawSquare(unsigned short x, unsigned short y, unsigned short sizeX, unsigned short sizeY, unsigned char color) {

    //@todo workaround for overflow

    unsigned char* mem = (unsigned char*)GRAPHICS_ADDRESS;

    for (unsigned short i = y; i < y + sizeY; ++i) {

        for (unsigned short j = x; j < x + sizeX; ++j) {

            *(mem + i * SCREEN_WIDTH + j) = color;
        }
    }
}

void drawChessBoard() {

    unsigned char color[2];
    color[0] = 0b01000101;
    color[1] = 0b11111111;

    bool white = true;
    for (unsigned char i = 0; i < 8; ++i) {

        for (unsigned char j = 0; j < 8; ++j) {

            drawSquare(i * 25 + 60, j * 25, 25, 25, color[white]);
            white = !white;
        }
        white = !white;
    }
}