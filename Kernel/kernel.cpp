#include "../Drivers/screen.h"

int kernel_main() {

    clearScreen();
    println("Welcome to Jeu-OS", 31, 0, 0x0f);
    println("I really don't like how i dealt with this text display thing.", -1, -1, 0x0f);
    println("Please redo this crap!", -1, -1, 0x04);

    return 0;
}