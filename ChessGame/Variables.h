//
// Created by jeuio on 09/01/2022.
//

#pragma once

namespace ChessGame {
    namespace Variables {

        extern char pressedKey;

        extern char selectedPiece;

        extern unsigned char cursorPos;

        enum pieceTypes {

            PAWN = 0, ROOK, KNIGHT, BISHOP, QUEEN, KING
        };

        extern const unsigned char initialBoardState[32];

        extern unsigned char boardState[32];
    }
}