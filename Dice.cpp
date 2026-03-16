//
// Created by nikit on 11.03.2026.
//
#include <string>
#include <iostream>
#include <random>
#include "Dice.h"

#include <chrono>
#include <map>



unsigned ThrowDice(Dice diceType) {
    // Определить диапазон
    unsigned max = diceType;

    // Инициализировать генератор случайных чисел
    // std::random_device rd;
    std::mt19937 gen(std::chrono::steady_clock().now().time_since_epoch().count());
    std::uniform_int_distribution<> distrib(1, max);

    // Сгенерировать случайное число в диапазоне [min, max]
    unsigned randomValue = distrib(gen);
    return randomValue;
};


const std::map<DiceGroup, DiceGroupPrmtrs> diceMultipliyers = {
    {d4x1, {d4, 1}},    {d4x2, {d4, 2}},    {d4x3, {d4, 3}},    {d4x4, {d4, 4}},    {d4x5, {d4, 5}},
    {d6x1, {d6, 1}},    {d6x2, {d6, 2}},    {d6x3, {d6, 3}},    {d6x4, {d6, 4}},    {d6x5, {d6, 5}},
    {d8x1, {d8, 1}},    {d8x2, {d8, 2}},    {d8x3, {d8, 3}},    {d8x4, {d8, 4}},    {d8x5, {d8, 5}},
    {d10x1, {d10, 1}},    {d10x2, {d10, 2}},    {d10x3, {d10, 3}},    {d10x4, {d10, 4}},    {d10x5, {d10, 5}},
    {d12x1, {d12, 1}},    {d12x2, {d12, 2}},    {d12x3, {d12, 3}},    {d12x4, {d12, 4}},    {d12x5, {d12, 5}},
    {d20x1, {d20, 1}},    {d20x2, {d20, 2}},    {d20x3, {d20, 3}},    {d20x4, {d20, 4}},    {d20x5, {d20, 5}},
};


unsigned ThrowDiceGroup(DiceGroup dices) {
    std::cout << "Throwing dices " << dices << "... ";
    unsigned sum = 0;
    unsigned multiplier = diceMultipliyers.at(dices).multiplier_;
    Dice diceType = diceMultipliyers.at(dices).dice_;
    for (unsigned i = 0; i < multiplier; i++) {
        unsigned dice = ThrowDice(diceType);
        sum += dice;
        std::cout << dice << " ";
    }
    std::cout << std::endl;
    return sum;
}


const std::map<std::string, DiceGroup> Name_DiceGruop = {
    {"d4x1", d4x1},  {"d4x2", d4x2},  {"d4x3", d4x3},  {"d4x4", d4x4},  {"d4x5", d4x5},
    {"d6x1", d6x1},  {"d6x2", d6x2},  {"d6x3", d6x3},  {"d6x4", d6x4},  {"d6x5", d6x5},
    {"d8x1", d8x1},  {"d8x2", d8x2},  {"d8x3", d8x3},  {"d8x4", d8x4},  {"d8x5", d8x5},
    {"d10x1", d10x1},  {"d10x2", d10x2},  {"d10x3", d10x3},  {"d10x4", d10x4},  {"d10x5", d10x5},
    {"d12x1", d12x1},  {"d12x2", d12x2},  {"d12x3", d12x3},  {"d12x4", d12x4},  {"d12x5", d12x5},
    {"d20x1", d20x1},  {"d20x2", d20x2},  {"d20x3", d20x3},  {"d20x4", d20x4},  {"d20x5", d20x5},
};


std::istream& operator >> (std::istream& in, DiceGroup& diceGroup) {
    std::string diceStr;
    bool valueSetted = false;
    in >> diceStr;
    while (!valueSetted) {
        try {
            diceGroup = Name_DiceGruop.at(diceStr);
            valueSetted = true;
        }
        catch (...) {
            std::cout << "Uncorrect input, try again - ";
            in >> diceStr;
        }
    }
    return in;
}

const std::map<DiceGroup, std::string> DiceGroup_Name = {
    {d4x1, "d4x1"},  {d4x2, "d4x2"},  {d4x3, "d4x3"},  {d4x4, "d4x4"},  {d4x5, "d4x5"},
    {d6x1, "d6x1"},  {d6x2, "d6x2"},  {d6x3, "d6x3"},  {d6x4, "d6x4"},  {d6x5, "d6x5"},
    {d8x1, "d8x1"},  {d8x2, "d8x2"},  {d8x3, "d8x3"},  {d8x4, "d8x4"},  {d8x5, "d8x5"},
    {d10x1, "d10x1"},  {d10x2, "d10x2"},  {d10x3, "d10x3"},  {d10x4, "d10x4"},  {d10x5, "d10x5"},
    {d12x1, "d12x1"},  {d12x2, "d12x2"},  {d12x3, "d12x3"},  {d12x4, "d12x4"},  {d12x5, "d12x5"},
    {d20x1, "d20x1"},  {d20x2, "d20x2"},  {d20x3, "d20x3"},  {d20x4, "d20x4"},  {d20x5, "d20x5"},
};

std::ostream& operator << (std::ostream& out, DiceGroup diceGroup) {
    std::string diceStr;
    diceStr = DiceGroup_Name.at(diceGroup);
    return out << diceStr;
}