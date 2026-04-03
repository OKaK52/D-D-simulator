#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Field.h"

int main() {
    srand(time(NULL));

    std::cout << "Welcome to the DND";


    int players;
    std::cout << "Enter number of players (2-6): ";
    std::cin >> players;

    if (players < 2) players = 2;
    if (players > 6) players = 6;

    Field game(players);
    game.StartGame();

    return 0;
}