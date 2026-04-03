#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <string>
#include "Hero.h"

class Field {
private:
    std::vector<Hero> heroes_;
    std::vector<std::vector<char>> displayField_;
    int fieldSize_;
    int currentHeroIndex_;

public:
    Field(int numPlayers);
    
    void StartGame();
    void DrawField();
    void UpdateDisplayField();
    bool CheckWin();
    void NextTurn();
    void PlaceHeroesOnField();
};

#endif