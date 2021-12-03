#include "../Drivers/screen.h"

int kernel_main() {

    clearScreen();
    char message1[] = {"Welcome to Jeu-OS"};
    println(message1, 31, 0, 0x0f);
    char message2[] = {"I really don't like how i dealt with this text display thing."};
    println(message2, -1, -1, 0x0f);
    char message3[] = {"Please redo this crap!"};
    println(message3, -1, -1, 0x04);

    return 0;
}