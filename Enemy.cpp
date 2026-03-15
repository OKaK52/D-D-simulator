//
// Created by nikit on 11.03.2026.
//

#include "Enemy.h"
#include "Cage.h"
// #include "Species.h"
// #include "Class.h"
#include <iostream>
#include <string>
#include <map>


unsigned Enemy::SetInt(std::string str, unsigned defualt = 1) {
    unsigned value = defualt;
    std::cout << "Input " << str << " for enemy - ";
    try {
        std::cin >> value;
    }
    catch (...) {
        std::cout << "Uncorrect input, try again - ";
        try { std::cin >> value; }
        catch (...) { std::cout << "Setted defualt mean - " << defualt; }
    }
    return value;
};


void Enemy::SetMaxHealth() {
    maxHealth_ = SetInt("MAX HEALTH", 20);
    health_ = maxHealth_;
};
void Enemy::SetPower() {
    std::cout << "Input POWER for enemy in diceGruop (for example - d4x1) - ";
    std::cin >> power_;
};

void Enemy::SetDexterity() {
    dexterity_ = SetInt("DEXTERITY", 10);
}

void Enemy::SetDefense() {
    defense_ = SetInt("DEFENSE", 15);
}

void Enemy::SetAttackDistance() {
    attackDistance_ = SetInt("DISTANCE", 1);
}

void Enemy::SetPosition() {
    std::cout << "Set position for yor enemy, x y (for example: 3 5) - ";
    std::cin >> position_.x >> position_.y;;
}

Enemy::Enemy (unsigned id) : id_(id){
    SetMaxHealth();
    SetPower();
    SetDexterity();
    SetDefense();
    SetAttackDistance();
    SetPosition();
};