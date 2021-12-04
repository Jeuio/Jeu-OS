//
// Created by jeuio on 28/11/2021.
//

#pragma once

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

/*
 * Color codes for foreground:
 * 0 = black, 1 = dark blue, 2 = dark green, 3 = blue, 4 = red, 5 = magenta, 6 = brown, 7 = light gray
 * 8 = gray, 9 = dark gray, 10 = light green, 11 = light blue, 12 = dark red, 13 = pink, 14 = yellow, 15 = white
 */
#define VGA_WHITE_ON_BLACK 0x0f

#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5



void print(const char* message, short col = -1, short row = -1, unsigned char attribute_byte = VGA_WHITE_ON_BLACK);

void println(const char* message, short col = -1, short row = -1, unsigned char attribute_byte = VGA_WHITE_ON_BLACK);

void clearScreen();

unsigned short getCursorPosition();

void setCursorPosition(unsigned short position);