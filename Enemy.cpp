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

bool Enemy::CheckDist() {

}

bool Enemy::CheckBreaking(Enemy attackedEnemy) {
    unsigned value = ThrowDiceGroup(power_);
    return value > attackedEnemy.GetDefense();
}

unsigned Enemy::CountDamage(Enemy attackedEnemy) {
    return ThrowDiceGroup(power_);
};

void Enemy::Damage(unsigned damage) {
    if (maxHealth_ > damage) health_ = health_ - damage;
    else health_ = 0;
}

void Enemy::Attack(Enemy attackedEnemy) {
    bool breaked = CheckBreaking((attackedEnemy));
    if (breaked) {
        unsigned damage = CountDamage(attackedEnemy);
        attackedEnemy.Damage(damage);
    }
}

unsigned Enemy::GetId() {return id_;}
unsigned Enemy::GetHealth() {return health_;}
unsigned Enemy::GetMaxHealth() {return maxHealth_;}
DiceGroup Enemy::GetPower() {return power_;}
unsigned Enemy::GetDexterity() {return dexterity_;}
unsigned Enemy::GetDefense() {return defense_;}
unsigned Enemy::GetAttackDistance() {return attackDistance_;}
Cage Enemy::GetPosition() {return position_;}