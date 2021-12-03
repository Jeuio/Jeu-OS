#include "../Drivers/screen.h"

int kernel_main() {

    clearScreen();
    println("Welcome to Jeu-OS", 31, 0, VGA_WHITE_ON_BLACK);
    println("I really don't like how i dealt with this text display thing.", -1, -1, 0x03);
    println("Please redo this crap!", -1, -1, 0x01);
    println("Please redo this crap!", -1, -1, 0x02);

    return 0;
}