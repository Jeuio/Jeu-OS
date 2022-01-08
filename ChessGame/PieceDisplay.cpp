//
// Created by jeuio on 08/01/2022.
//

#include "PieceDisplay.h"

void displayPiece(const unsigned char pieceData[72], unsigned short x, unsigned short y, unsigned char color) {

    for (unsigned char i = 0; i < 24; ++i) {

        for (unsigned char j = 0; j < 3; ++j) {

            for (unsigned char k = 0; k < 8; ++k) {

                if (pieceData[i * 3 + j] & (0b10000000 >> k)) { // If the bit at the corresponding position in the bitmap is set

                    drawPixel(x + (j * 8 + k), y + i, color);
                }
            }
        }
    }
}