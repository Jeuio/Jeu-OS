//
// Created by jeuio on 28/11/2021.
//

#pragma once

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

#define WHITE_ON_BLACK 0x0f

#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5



void print(const char* message, short col, short row, unsigned char attribute_byte);

void println(const char* message, short col, short row, unsigned char attribute_byte);

void clearScreen();

unsigned short getCursorPosition();

void setCursorPosition(unsigned short position);