//
// Created by jeuio on 09/01/2022.
//

#include "Variables.h"

char ChessGame::Variables::selectedPiece = 64;

char ChessGame::Variables::pressedKey = 0;

unsigned char ChessGame::Variables::cursorPos = 0;

const unsigned char ChessGame::Variables::initialBoardState[] = {

        0b10101011, 0b11001101, 0b11101100, 0b10111010,
        0b10011001, 0b10011001, 0b10011001, 0b10011001,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0b00010001, 0b00010001, 0b00010001, 0b00010001,
        0b00100011, 0b01000101, 0b01100100, 0b00110010
};

unsigned char ChessGame::Variables::boardState[] = {

        0b10101011, 0b11001101, 0b11101100, 0b10111010,
        0b10011001, 0b10011001, 0b10011001, 0b10011001,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0b00010001, 0b00010001, 0b00010001, 0b00010001,
        0b00100011, 0b01000101, 0b01100100, 0b00110010
};