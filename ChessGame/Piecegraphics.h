//
// Created by jeuio on 08/01/2022.
//

// @fixme the value of the fields are set to 0 for some reason

#pragma once

namespace PieceData {

    static const unsigned char pawn[] = {

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
    };

    static const unsigned char rook[] = {

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
    };

    static const unsigned char bishop[] = {

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
    };

    static const unsigned char knight[] = {

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
    };

    static const unsigned char queen[] = {

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
    };

    static const unsigned char king[] = {

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
    };
}