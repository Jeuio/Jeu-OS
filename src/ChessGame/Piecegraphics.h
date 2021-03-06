//
// Created by jeuio on 08/01/2022.
//

#pragma once

namespace ChessGame {
    namespace PieceData {

        static const unsigned char pieceColors[] = {0b11011010, 0b00100101};

        static const unsigned char pieces[][72] = {
                {   // Pawn
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000000, 0b01111110, 0b00000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000011, 0b11111111, 0b11000000,
                        0b00000011, 0b11111111, 0b11000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000000, 0b01111110, 0b00000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000011, 0b11111111, 0b11000000,
                        0b00000111, 0b11111111, 0b11100000,
                        0b00000111, 0b11111111, 0b11100000,
                        0b00000111, 0b11111111, 0b11100000,
                        0b00001111, 0b11111111, 0b11110000,
                        0b00001111, 0b11111111, 0b11110000,
                        0b00001111, 0b11111111, 0b11110000,
                        0b00001111, 0b11111111, 0b11110000,
                        0b00001111, 0b11111111, 0b11110000
                },
                {   // Rook
                        0b00011110, 0b00111100, 0b01111000,
                        0b00011110, 0b00111100, 0b01111000,
                        0b00011110, 0b00111100, 0b01111000,
                        0b00011111, 0b11111111, 0b11111000,
                        0b00011111, 0b11111111, 0b11111000,
                        0b00001111, 0b11111111, 0b11110000,
                        0b00000111, 0b11111111, 0b11100000,
                        0b00000011, 0b11111111, 0b11000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000011, 0b11111111, 0b11000000,
                        0b00000111, 0b11111111, 0b11100000,
                        0b00001111, 0b11111111, 0b11110000,
                        0b00001111, 0b11111111, 0b11110000,
                        0b00011111, 0b11111111, 0b11111000,
                        0b00011111, 0b11111111, 0b11111000,
                        0b00011111, 0b11111111, 0b11111000
                },
                {   // Knight
                        0b00000000, 0b00000100, 0b00000000,
                        0b00000000, 0b00001100, 0b00000000,
                        0b00000000, 0b11111110, 0b00000000,
                        0b00000001, 0b11111111, 0b00000000,
                        0b00000011, 0b11111111, 0b11000000,
                        0b00000111, 0b11111111, 0b11100000,
                        0b00000111, 0b11111111, 0b11110000,
                        0b00000111, 0b11111111, 0b11111000,
                        0b00000111, 0b11111111, 0b11111100,
                        0b00000111, 0b11100000, 0b11111100,
                        0b00000111, 0b11100000, 0b00111100,
                        0b00000111, 0b11110000, 0b00000000,
                        0b00000111, 0b11111000, 0b00000000,
                        0b00000111, 0b11111100, 0b00000000,
                        0b00000111, 0b11111110, 0b00000000,
                        0b00000011, 0b11111111, 0b00000000,
                        0b00000011, 0b11111111, 0b10000000,
                        0b00000011, 0b11111111, 0b11000000,
                        0b00000011, 0b11111111, 0b11000000,
                        0b00001111, 0b11111111, 0b11110000,
                        0b00000111, 0b11111111, 0b11100000,
                        0b00001111, 0b11111111, 0b11110000,
                        0b00011111, 0b11111111, 0b11111000,
                        0b00111111, 0b11111111, 0b11111100
                },
                {   // Bishop
                        0b00000000, 0b00011000, 0b00000000,
                        0b00000000, 0b00111100, 0b00000000,
                        0b00000000, 0b00111100, 0b00000000,
                        0b00000000, 0b01111110, 0b00000000,
                        0b00000000, 0b01111110, 0b00000000,
                        0b00000000, 0b01111110, 0b00000000,
                        0b00000000, 0b01111110, 0b00000000,
                        0b00000000, 0b01111110, 0b00000000,
                        0b00000000, 0b00111100, 0b00000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000000, 0b00111100, 0b00000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000011, 0b11111111, 0b11000000,
                        0b00000011, 0b11111111, 0b11000000,
                        0b00000011, 0b11111111, 0b11000000,
                        0b00000011, 0b11111111, 0b11000000
                },
                {   // Queen
                        0b00000000, 0b00011000, 0b00000000,
                        0b00000010, 0b01011010, 0b01000000,
                        0b00000011, 0b11111111, 0b11000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000011, 0b11111111, 0b11000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000000, 0b01111110, 0b00000000,
                        0b00000000, 0b01111110, 0b00000000,
                        0b00000000, 0b01111110, 0b00000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000111, 0b11111111, 0b11100000,
                        0b00001111, 0b11111111, 0b11110000,
                        0b00001111, 0b11111111, 0b11110000,
                        0b00001111, 0b11111111, 0b11110000
                },
                {   // King
                        0b00000000, 0b00011000, 0b00000000,
                        0b00000000, 0b00111100, 0b00000000,
                        0b00000000, 0b00011000, 0b00000000,
                        0b00000000, 0b00011000, 0b00000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000011, 0b11111111, 0b11000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000000, 0b01111110, 0b00000000,
                        0b00000000, 0b01111110, 0b00000000,
                        0b00000000, 0b01111110, 0b00000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000000, 0b11111111, 0b00000000,
                        0b00000001, 0b11111111, 0b10000000,
                        0b00000111, 0b11111111, 0b11100000,
                        0b00001111, 0b11111111, 0b11110000,
                        0b00001111, 0b11111111, 0b11110000,
                        0b00001111, 0b11111111, 0b11110000
                }
        };
    }
}