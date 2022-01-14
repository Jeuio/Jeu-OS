//
// Created by jeuio on 09/01/2022.
//

#pragma once

#include "PieceDisplay.h"
#include "Variables.h"

namespace ChessGame {

    void start();

    void init();

    void update();

    void movePiece(unsigned char pieceIndex, unsigned short x, unsigned short y, unsigned short tX, unsigned short tY, unsigned char color, unsigned int steps);
}