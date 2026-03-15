#ifndef SESC_CORE_CAGE_H
#define SESC_CORE_CAGE_H
#include <cmath>

struct Cage {
    unsigned x;
    unsigned y;

    int countDistance(Cage target) {
        return abs(x - target.x) + abs(y - target.y);
    }
};

#endif //SESC_CORE_CAGE_H