//
// Created by vladi on 06.03.2026.
//

#ifndef SESC_CORE_FIELD_H
#define SESC_CORE_FIELD_H
#include <vector>
#include <string>
#include <utility>

#include "Units/Hero.h"
using namespace std;


class Field{
    vector<Hero> heroes_;
    vector<vector<int>> field_;
    int fieldSize_ = 3;
    int currentHero_ = 0;

public:
    Field(vector<vector<int>> field, vector<Hero> heroes);
    Field(int cntPlayers);

    string DrawField() const;
    vector<vector<int>> ChangeCage(pair<int, int> CurrentPosition, pair<int, int> NextPosition);
    void Start();
    void UpdateField();

};


#endif //SESC_CORE_FIELD_H