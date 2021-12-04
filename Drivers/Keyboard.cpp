//
// Created by jeuio on 01/12/2021.
//

#include "Keyboard.h"

void initKeyboard() {

    registerInterruptHandler(IRQ1, keyboardCallback);
}

unsigned char getLetter(unsigned char scancode) {

    //@todo map the scancode to a key properly. this will be really painful

    return scancode;
}

static void keyboardCallback(registers_t *regs) {

    unsigned char scancode = portByteIn(0x60);
    char key[2];
    key[0] = getLetter(scancode);
    if (key[0] == 0) {
        return;
    }
    key[1] = 0x00;

    print(key, -1 ,-1 , VGA_WHITE_ON_BLACK);
}