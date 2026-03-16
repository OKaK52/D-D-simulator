#ifndef SESC_CORE_CAGE_H
#define SESC_CORE_CAGE_H
#include <cmath>

struct Cage {
    int x;
    int y;

    static unsigned CountDistance(Cage cage1, Cage cage2) {
        return abs(cage1.x - cage2.x) + abs(cage1.y - cage2.y);
    }
};

#endif //SESC_CORE_CAGE_H