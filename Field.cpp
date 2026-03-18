//
// Created by vladi on 06.03.2026.
//

#include "Field.h"
#include <iostream>
#include "Units/Hero.h"
#include <Units/Helpers/Cage.h>
using namespace std;

Field::Field (vector<vector<int>> field1, vector<Hero> heroes1) {
    field_ = field1;
    heroes_ = heroes1;
}

Field::Field(int cntPlayers) {
    std::cout << "Input size of field: ";
    std::cin >> fieldSize_;
    field_ = vector<vector<int>>  (fieldSize_, vector<int> (fieldSize_, 0));

    for (int i = 1; i <= cntPlayers; i++) {
        Hero tmpHero = Hero(i);
        heroes_.push_back(tmpHero);
    }
}


void Field::UpdateField() {
    for (int i = 0; i < heroes_.size(); i++) {
        Hero hero = heroes_[i];
        Cage pos = hero.GetPosition();
        field_[pos.x][pos.y] = i + 1;
    }
}

string Field::DrawField() {
    UpdateField();
    string FieldImage;
    for (int i = 0; i < field_.size(); i++) {
        FieldImage += "[";
        for (int j = 0; j < field_[i].size(); j++) {
            char c = '0';
            if (field_[i][j] != 0) {
                int id = field_[i][j] - 1;
                Hero hero = heroes_[id];
                c = to_string(hero.GetId())[0];
            }
            FieldImage += c;
            if (j < field_[i].size() - 1) FieldImage += "] [";
            else FieldImage += "]";
        }

        if (i < field_.size() - 1) FieldImage += '\n';
    }

    return FieldImage;
}

// vector<vector<int>> Field::ChangeCage(pair<int, int> CurrentPosition, pair<int, int> NextPosition) {
//     vector<vector<int>> field2 = field;
//     field2[CurrentPosition.first][CurrentPosition.second] = 0;
//     field2[NextPosition.first][NextPosition.second] = currentHero_[0];
//     return field2;
// }



