//
// Created by jeuio on 09/01/2022.
//

#include "Game.h"

#include "Piecegraphics.h"
#include "../Librarys/std.h"

void ChessGame::start() {

    init();
    for (;;) {

        update();
    }
}

void ChessGame::init() {

}

void ChessGame::update() {

    if (ChessGame::Variables::pressedKey != 0) {

        unsigned char p = ChessGame::Variables::cursorPos;

        switch (ChessGame::Variables::pressedKey) {

            case 'w': {
                p = p > 7 ? p - 8 : p;
                break;
            }

            case 'a': {
                p = p % 8 > 0 ? p - 1 : p;
                break;
            }

            case 's': {
                p = p < 56 ? p + 8 : p;
                break;
            }

            case 'd': {
                p = p % 8 < 7 ? p + 1 : p;
                break;
            }

            case 0x0a: {  // If 'return' is pressed

                using namespace ChessGame::Variables;

                unsigned char offset1 = (selectedPiece % 2) * 4;
                unsigned char offset2 = (cursorPos % 2) * 4;

                if (selectedPiece == 64) {    // If no piece is selected
                    if ((boardState[cursorPos / 2] & (0b11110000 >> offset2)) != 0) {   // If there is a piece present on the selected tile
                        selectedPiece = cursorPos;  // Let selectedPiece point to the cursorPos
                    }
                } else if (selectedPiece != cursorPos) {    // If a piece is selected, and it's not the currently selected piece

                    selectedPiece = 64;   // Deselect the piece

                    unsigned char currentPieceData = boardState[selectedPiece / 2] & (0b11110000 >> offset1);
                    currentPieceData >>= 4 - offset1;
                    boardState[selectedPiece / 2] &= offset1 == 0 ? 0b00001111 : 0b11110000;

                    ChessGame::movePiece(ChessGame::PieceData::king, selectedPiece % 8 * 25 + 60, selectedPiece / 8 * 25, cursorPos % 8 * 25 + 60, cursorPos / 8 * 25, 0b11100000, 1000);   // @todo change the pieces appearance to the appropriate figure

                    boardState[cursorPos / 2] &= offset2 == 0 ? 0b00001111 : 0b11110000;
                    boardState[cursorPos / 2] |= currentPieceData << (4 - offset2);

                } else if (selectedPiece == cursorPos) {    // If the currently selected piece is re-selected
                    selectedPiece = 64;   // Deselect the piece
                }
                break;
            }

            case 0x08: { // If 'backspace' is pressed
                for (unsigned char i = 0; i < 32; ++i) {

                    ChessGame::Variables::boardState[i] = ChessGame::Variables::initialBoardState[i];
                }
                break;
            }
        }

        ChessGame::Variables::cursorPos = p;
        ChessGame::Variables::pressedKey = 0;
    }

    testGraphics();
    ChessGame::drawChessBoardTiles();
    ChessGame::highlightSelectedPiece();
    ChessGame::drawBoard(ChessGame::Variables::boardState);
    ChessGame::displayCursor(ChessGame::Variables::cursorPos);
    flush();
}

void ChessGame::movePiece(const unsigned char *data, unsigned short x, unsigned short y, unsigned short tX, unsigned short tY, unsigned char color, unsigned int steps) {

    double diffX = tX - x;
    double diffY = tY - y;

    for (unsigned short i= 0; i < steps; ++i) {

        double dX = x + diffX / (double)steps * i;
        double dY = y + diffY / (double)steps * i;

        testGraphics();
        ChessGame::drawChessBoardTiles();
        ChessGame::drawBoard(ChessGame::Variables::boardState);
        ChessGame::displayPiece(data, (unsigned short)dX, (unsigned short)dY, color);
        flush();
        std::timer::wait(1000000);
    }
}