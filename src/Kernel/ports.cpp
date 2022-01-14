//
// Created by jeuio on 29/11/2021.
//

unsigned char portByteIn(unsigned short port) {

    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void portByteOut(unsigned short port, unsigned char data) {

    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

unsigned short portWordIn(unsigned short port) {

    unsigned short result;
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}

void portWordOut(unsigned short port, unsigned short data) {

    __asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}