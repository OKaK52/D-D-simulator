//
// Created by nikit on 11.03.2026.
//
#include <iostream>
#include "Unit.h"
#include "Hero.h"

int main() {
    Hero Nikita(2);
    Hero Egor(1);
    Nikita.Attack(Egor);
    Egor.Attack(Nikita);
    return 0;
}
