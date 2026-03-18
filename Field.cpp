//
// Created by vladi on 06.03.2026.
//

#include "Field.h"
#include <iostream>
using namespace std;

Field::Field (vector<vector<int>> field1, vector<Heroes> heroes1) {
    field = field1;
    heroes = heroes1;
}

string Field::DrawField() {
    string FieldImage;
    for (int i = 0; i < field.size(); i++) {
        FieldImage += "[";
        for (int j = 0; j < field[i].size(); j++) {
            FieldImage += to_string(field[i][j]);
            if (j < field[i].size() - 1) {
                FieldImage += "] [";
            }
        }
        FieldImage += "]";
        if (i < field.size() - 1) {
            FieldImage += "\n";
        }
    }
    return FieldImage;
}

vector<vector<int>> Field::ChangeField(pair<int, int> CurrentPosition, pair<int, int> NextPosition) {
    vector<vector<int>> field2 = field;
    field2[CurrentPosition.first][CurrentPosition.second] = 0;
    field2[NextPosition.first][NextPosition.second] = CurrentHero[0];
    return field2;
}

pair<int, int> Field::GetPosition() {
    NextPosition = CurrentHero[1];
    return NextPosition;
}



