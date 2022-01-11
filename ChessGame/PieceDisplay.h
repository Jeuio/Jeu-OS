//
// Created by jeuio on 08/01/2022.
//

#pragma once

#include "../Drivers/graphics.h"

namespace ChessGame {

    void displayPiece(unsigned char index, unsigned short x, unsigned short y, unsigned char color);

    void displayCursor(unsigned char cursorPos);

    void highlightSelectedPiece();

    void drawChessBoardTiles();

    void drawBoard(unsigned char boardState[32]);
}