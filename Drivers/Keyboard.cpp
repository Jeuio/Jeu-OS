//
// Created by jeuio on 01/12/2021.
//

#include "Keyboard.h"

void initKeyboard() {

    registerInterruptHandler(IRQ1, keyboardCallback);
}

unsigned char getLetter(unsigned char scancode) {

    //@todo map the scancode to a key properly. this will be really painful

    switch (scancode) {

        case 0x01:
            return 0x1b;    // escape
        case 0x02:
            return 0x31;    // 1
        case 0x03:
            return 0x32;    // 2
        case 0x04:
            return 0x33;    // 3
        case 0x05:
            return 0x34;    // 4
        case 0x06:
            return 0x35;    // 5
        case 0x07:
            return 0x36;    // 6
        case 0x08:
            return 0x37;    // 7
        case 0x09:
            return 0x38;    // 8
        case 0x0a:
            return 0x39;    // 9
        case 0x0b:
            return 0x30;    // 0
        case 0x0c:
            return 0x00;    // ß
        case 0x0d:
            return 0x2c;    // ´
        case 0x0e:
            return 0x08;    // backspace
        case 0x0f:
            return 0x09;    // tab
        case 0x10:
            return 0x71;    // q
        case 0x11:
            return 0x77;    // w
        case 0x12:
            return 0x65;    // e
        case 0x13:
            return 0x72;    // r
        case 0x14:
            return 0x74;    // t
        case 0x15:
            return 0x7a;    // z
        case 0x16:
            return 0x75;    // u
        case 0x17:
            return 0x69;    // i
        case 0x18:
            return 0x6f;    // o
        case 0x19:
            return 0x70;    // p
        case 0x1a:
            return 0x00;    // ü
        case 0x1b:
            return 0x2b;    // +
        case 0x1c:
            return 0x00;    // enter
        case 0x1e:
            return 0x61;    // a
        case 0x1f:
            return 0x73;    // s
        case 0x20:
            return 0x64;    // d
        case 0x21:
            return 0x66;    // f
        case 0x22:
            return 0x67;    // g
        case 0x23:
            return 0x68;    // h
        case 0x24:
            return 0x6a;    // j
        case 0x25:
            return 0x6b;    // k
        case 0x26:
            return 0x6c;    // l
        case 0x27:
            return 0x00;    // ö @todo needs workaround
        case 0x28:
            return 0x00;    // ä @todo needs workaround
        case 0x29:
            return 0x5e;    // ^
        case 0x2a:
            return 0x00;    // left shift @todo implement this
        case 0x2b:
            return 0x23;    // #
        case 0x2c:
            return 0x79;    // y
        case 0x2d:
            return 0x78;    // x
        case 0x2e:
            return 0x63;    // c
        case 0x2f:
            return 0x76;    // v
        case 0x30:
            return 0x62;    // b
        case 0x31:
            return 0x6e;    // n
        case 0x32:
            return 0x6d;    // m
        case 0x33:
            return 0x2c;    // ,
        case 0x34:
            return 0x2e;    // .
        case 0x35:
            return 0x2d;    // -
        case 0x36:
            return 0x00;    // right shift @todo implement caps
        case 0x3a:
            return 0x00;    // caps lock
        case 0x3b:
            return 0x00;    // f1
        case 0x3c:
            return 0x00;    // f2
        case 0x3d:
            return 0x00;    // f3
        case 0x3e:
            return 0x00;    // f4
        case 0x3f:
            return 0x00;    // f5
        case 0x40:
            return 0x00;    // f6
        case 0x41:
            return 0x00;    // f7
        case 0x42:
            return 0x00;    // f8
        case 0x43:
            return 0x00;    // f9
        case 0x44:
            return 0x00;    // f10
        case 0x56:
            return 0x3c;    // <
        case 0x57:
            return 0x00;    // f11
        case 0x58:
            return 0x00;    // f12
    }

    return 0x00;
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