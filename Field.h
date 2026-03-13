//
// Created by vladi on 06.03.2026.
//

#ifndef SESC_CORE_FIELD_H
#define SESC_CORE_FIELD_H
#include <vector>
#include <string>
#include <utility>
using namespace std;


class Field{
    vector<Heroes> heroes;
    vector<vector<int>> field;
    int FieldSize;
    pair<int, int> CurrentPosition;
    pair<int, int> NextPosition;

public:
    Field(vector<vector<int>> field, vector<Heroes> heroes);
    pair<int, int> GetPosition();
    string DrawField();
    vector<vector<int>> ChangeField(pair<int, int> CurrentPosition, pair<int, int> NextPosition);
};


#endif //SESC_CORE_FIELD_H