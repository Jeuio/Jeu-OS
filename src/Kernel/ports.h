//
// Created by jeuio on 29/11/2021.
//

#pragma once

unsigned char portByteIn(unsigned short port);

void portByteOut(unsigned short port, unsigned char data);

unsigned short portWordIn(unsigned short port);

void portWordOut(unsigned short port, unsigned short data);