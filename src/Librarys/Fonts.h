//
// Created by jeuio on 13.01.2022.
//

#pragma once

namespace Fonts {

    enum Characters {

        a = 0, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
    };

    namespace Custom {

        static const unsigned char characters[][10]{
                {   // a
                        0b00000000,
                        0b00000000,
                        0b01111110,
                        0b00000001,
                        0b01111111,
                        0b10000001,
                        0b10000001,
                        0b01111111,
                        0b00000000,
                        0b00000000
                },
                {   // b
                        0b10000000,
                        0b10000000,
                        0b10000000,
                        0b10000000,
                        0b11111110,
                        0b10000001,
                        0b10000001,
                        0b11111110,
                        0b00000000,
                        0b00000000
                },
                {   // c
                        0b00000000,
                        0b00000000,
                        0b00111111,
                        0b01000000,
                        0b10000000,
                        0b10000000,
                        0b01000000,
                        0b00111111,
                        0b00000000,
                        0b00000000
                },
                {   // d
                        0b00000001,
                        0b00000001,
                        0b00000001,
                        0b00000001,
                        0b01111111,
                        0b10000001,
                        0b10000001,
                        0b01111111,
                        0b00000000,
                        0b00000000
                },
                {   // e
                        0b00000000,
                        0b00111100,
                        0b01000010,
                        0b10000001,
                        0b11111110,
                        0b10000000,
                        0b10000001,
                        0b01111110,
                        0b00000000,
                        0b00000000
                },
                {   // f
                        0b00000000,
                        0b00000111,
                        0b00001000,
                        0b00010000,
                        0b01111100,
                        0b00010000,
                        0b00010000,
                        0b00010000,
                        0b00000000,
                        0b00000000
                },
                {   // g
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b01111110,
                        0b10000010,
                        0b10000010,
                        0b01111110,
                        0b00000010,
                        0b00000010,
                        0b11111100
                },
                {   // h
                        0b10000000,
                        0b10000000,
                        0b10000000,
                        0b10000000,
                        0b11111110,
                        0b10000001,
                        0b10000001,
                        0b10000001,
                        0b00000000,
                        0b00000000
                },
                {   // i
                        0b00000000,
                        0b00010000,
                        0b00000000,
                        0b00110000,
                        0b00010000,
                        0b00010000,
                        0b00010000,
                        0b00111000,
                        0b00000000,
                        0b00000000
                },
                {   // j
                        0b00000000,
                        0b00000001,
                        0b00000000,
                        0b00001111,
                        0b00000001,
                        0b00000001,
                        0b00000001,
                        0b00000001,
                        0b00000010,
                        0b00111100
                },
                {   // k
                        0b10000000,
                        0b10000000,
                        0b10000000,
                        0b10010000,
                        0b10100000,
                        0b11000000,
                        0b10100000,
                        0b10010000,
                        0b00000000,
                        0b00000000
                },
                {   // l
                        0b11100000,
                        0b00100000,
                        0b00100000,
                        0b00100000,
                        0b00100000,
                        0b00100000,
                        0b00100000,
                        0b00011110,
                        0b00000000,
                        0b00000000
                },
                {   // m
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b11101100,
                        0b10010010,
                        0b10010010,
                        0b10010010,
                        0b10010010,
                        0b00000000,
                        0b00000000
                },
                {   // n
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b01000000,
                        0b01111100,
                        0b01000010,
                        0b01000010,
                        0b01000010,
                        0b00000000,
                        0b00000000
                },
                {   // o
                        0b00000000,
                        0b00000000,
                        0b00111100,
                        0b01000010,
                        0b01000010,
                        0b01000010,
                        0b01000010,
                        0b00111100,
                        0b00000000,
                        0b00000000
                },
                {   // p
                        0b00000000,
                        0b00000000,
                        0b10111100,
                        0b11000010,
                        0b10000010,
                        0b11000010,
                        0b10111100,
                        0b10000000,
                        0b10000000,
                        0b10000000
                },
                {   // q
                        0b00000000,
                        0b00000000,
                        0b01111010,
                        0b10000110,
                        0b10000010,
                        0b10000110,
                        0b01111010,
                        0b00000010,
                        0b00000010,
                        0b00000010
                },
                {   // r
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b10111000,
                        0b11000100,
                        0b10000000,
                        0b10000000,
                        0b10000000,
                        0b00000000,
                        0b00000000
                },
                {   // s
                        0b00000000,
                        0b00000000,
                        0b01111100,
                        0b10000010,
                        0b01110000,
                        0b00011100,
                        0b10000010,
                        0b01111100,
                        0b00000000,
                        0b00000000
                },
                {   // t
                        0b00010000,
                        0b00010000,
                        0b00010000,
                        0b00010000,
                        0b01111100,
                        0b00010000,
                        0b00010000,
                        0b00010010,
                        0b00001100,
                        0b00000000
                },
                {   // u
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b01000010,
                        0b01000010,
                        0b01000010,
                        0b00111100,
                        0b00000000,
                        0b00000000
                },
                {   // v
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b01000100,
                        0b01000100,
                        0b00101000,
                        0b00101000,
                        0b00010000,
                        0b00000000,
                        0b00000000
                },
                {   // w
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b10000001,
                        0b01011010,
                        0b00100100,
                        0b00000000,
                        0b00000000
                },
                {   // x
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00101000,
                        0b00010000,
                        0b00101000,
                        0b00000000,
                        0b00000000
                },
                {   // y
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00100010,
                        0b00010100,
                        0b00001000,
                        0b00010000,
                        0b00100000
                },
                {   // z
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00111100,
                        0b00001000,
                        0b00010000,
                        0b00111100,
                        0b00000000,
                        0b00000000
                },
                {   // A
                        0b00000000,
                        0b11111111,
                        0b10000001,
                        0b10000001,
                        0b11111111,
                        0b10000001,
                        0b10000001,
                        0b10000001,
                        0b00000000,
                        0b00000000
                },
                {   // B
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // C
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // D
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // E
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // F
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // G
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // H
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // I
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // J
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // K
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // L
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // M
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // N
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // O
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // P
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // Q
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // R
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // S
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // T
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // U
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // V
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // W
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // X
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // Y
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
                {   // Z
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000,
                        0b00000000
                },
        };
    }
}