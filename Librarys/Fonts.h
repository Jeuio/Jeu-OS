//
// Created by jeuio on 13.01.2022.
//

#pragma once

namespace Fonts {

    enum Characters {

        a = 0, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
    };

    namespace Custom {

        static const unsigned char[][8] {
            {   // a
                0b00000000,
                0b00000000,
                0b00000000,
                0b00000000,
                0b00000000,
                0b00000000,
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
                0b11111110
            },
            {   // c
                0b00111110,
                0b01000001,
                0b10000000,
                0b10000000,
                0b10000000,
                0b10000000,
                0b01000001,
                0b00111110
            },
            {   // d
                0b00000001,
                0b00000001,
                0b00000001,
                0b00000001,
                0b01111111,
                0b10000001,
                0b10000001,
                0b01111111
            },
            {   // e
                0b00000000,
                0b00111100,
                0b01000010,
                0b10000001,
                0b11111110,
                0b10000000,
                0b10000001,
                0b01111110
            }
        }
    }
}