//
// Created by jeuio on 01/12/2021.
//

#pragma once

#include "../Kernel/Interrupts/isr.h"
#include "../Kernel/ports.h"

#include "screen.h"

static void keyboardCallback(registers_t *regs);

unsigned char getLetter(unsigned char scancode);

void initKeyboard();