//
// Created by jeuio on 11/12/2021.
//

#pragma once

#include "../Kernel/Interrupts/isr.h"
#include "../Kernel/ports.h"

void initMouse();

static void mouseCallback(registers_t *regs);