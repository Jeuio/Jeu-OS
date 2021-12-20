//
// Created by jeuio on 08/12/2021.
//

#pragma once

#define GRAPHICS_ADDRESS 0xa0000
#define MODE_CONTROL 0x3c0
#define PALETTE_MASK 0x3c6
#define PALETTE_READ 0x3c7
#define PALETTE_WRITE 0x3c8
#define PALETTE_DATA 0x3c9

#define TEXT_MODE 0
#define COLOR_256_LINEAR 1

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

struct RGB {

    unsigned char r, g, b;
};

void paletteSet(unsigned short index, RGB rgb);

void setMode(unsigned char mode);

void initScreen(unsigned char mode);

void testGraphics();

void drawSquare(unsigned short x, unsigned short y, unsigned short sizeX, unsigned short sizeY, unsigned char color);

void drawChessBoard();