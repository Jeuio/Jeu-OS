//
// Created by jeuio on 08/01/2022.
//

#include "PieceDisplay.h"
#include "Piecegraphics.h"
#include "Variables.h"

void ChessGame::displayPiece(const unsigned char pieceData[72], unsigned short x, unsigned short y, unsigned char color) {

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

void ChessGame::displayCursor(unsigned char cursorPos) {

    drawSquare(cursorPos % 8 * 25 + 60, cursorPos / 8 * 25, 25, 25, 0b11100000);
}

void ChessGame::highlightSelectedPiece() {

    if (ChessGame::Variables::selectedPiece < 64) {
        fillSquare(ChessGame::Variables::selectedPiece % 8 * 25 + 60, ChessGame::Variables::selectedPiece / 8 * 25, 25, 25, 0b01101100);
    }
}

void ChessGame::drawChessBoardTiles() {

    unsigned char color[2];
    color[0] = 0b10001000;
    color[1] = 0b11111111;

    bool white = true;
    for (unsigned char i = 0; i < 8; ++i) {

        for (unsigned char j = 0; j < 8; ++j) {

            fillSquare(i * 25 + 60, j * 25, 25, 25, color[white]);
            white = !white;
        }
        white = !white;
    }
}

void ChessGame::drawBoard(unsigned char *boardState) {

    for (unsigned char i = 0; i < 64; ++i) {

        unsigned char pieceData = boardState[i / 2] >> (4 - ((i % 2) * 4));

        unsigned char color = pieceData & 0b1000 ? 0b00100101 : 0b11011010;

        switch (pieceData & 0b0111) {

            case ChessGame::Variables::PAWN:
                displayPiece(ChessGame::PieceData::pawn, i % 8 * 25 + 60, i / 8 * 25 + 1, color);
                break;

            case ChessGame::Variables::ROOK:
                displayPiece(ChessGame::PieceData::rook, i % 8 * 25 + 60, i / 8 * 25 + 1, color);
                break;

            case ChessGame::Variables::KNIGHT:
                displayPiece(ChessGame::PieceData::knight, i % 8 * 25 + 60, i / 8 * 25 + 1, color);
                break;

            case ChessGame::Variables::BISHOP:
                displayPiece(ChessGame::PieceData::bishop, i % 8 * 25 + 60, i / 8 * 25 + 1, color);
                break;

            case ChessGame::Variables::QUEEN:
                displayPiece(ChessGame::PieceData::queen, i % 8 * 25 + 60, i / 8 * 25 + 1, color);
                break;

            case ChessGame::Variables::KING:
                displayPiece(ChessGame::PieceData::king, i % 8 * 25 + 60, i / 8 * 25 + 1, color);
                break;
        }
    }
}