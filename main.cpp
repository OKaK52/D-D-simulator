//
// Created by nikit on 11.03.2026.
//
#include <iostream>
#include "Units/Unit.h"
#include "Units/Hero.h"
#include "Field.h"

int main() {
    Field field = Field(2);
    cout << field.DrawField();
    return 0;
}