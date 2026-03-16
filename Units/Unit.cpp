//
// Created by nikit on 11.03.2026.
//

#include "../Units/Unit.h"
#include "../Units/Helpers/Cage.h"
#include <iostream>
#include <string>
#include "../Units/Helpers/Dice.h"


unsigned Unit::SetInt(std::string str, unsigned defualt = 1) {
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

void Unit::SetName() {
    std::cout << "Enter name: ";
    std::cin >> name_;
}
void Unit::SetMaxHealth() {
    maxHealth_ = SetInt("MAX HEALTH", 20);
    health_ = maxHealth_;
};
void Unit::SetPower() {
    std::cout << "Input POWER for enemy in diceGruop (for example - d4x1) - ";
    std::cin >> power_;
};
void Unit::SetDexterity() {
    dexterity_ = SetInt("DEXTERITY", 10);
}
void Unit::SetDefense() {
    defense_ = SetInt("DEFENSE", 15);
}
void Unit::SetAttackDistance() {
    attackDistance_ = SetInt("DISTANCE", 1);
}
void Unit::SetPosition() {
    std::cout << "Set position for yor enemy, x y (for example: 3 5) - ";
    std::cin >> position_.x >> position_.y;;
}


Unit::Unit (unsigned id) : id_(id){
    SetName();
    SetMaxHealth();
    SetPower();
    SetDexterity();
    SetDefense();
    SetAttackDistance();
    SetPosition();
};


bool Unit::CheckDist(Unit target) {
    Cage targetPosition = target.GetPosition();
    Cage ourPosition = GetPosition();
    unsigned dist = Cage::CountDistance(targetPosition, ourPosition);
    std::cout << "Distance = " << dist << std::endl;
    bool reaching = dist <= attackDistance_;
    if (!reaching) std::cout << name_ << " can't reach " << target.name_ << std::endl;
    return reaching;
}


bool Unit::CheckBreaking(Unit target) {
    std::cout << "Checking piercing of armor: " << std::endl;
    unsigned value = ThrowDiceGroup(power_);
    bool breaking = value > target.GetDefense();
    if (!breaking) std::cout << "UNLUCK! The armor is NOT PIERCED!" << std::endl;
    else std::cout << "GOODLUCK! The armor PIERCED!" << std::endl;
    return breaking;
}


unsigned Unit::CountDamage() {
    std::cout << "Counting Damage..." << std::endl;
    return ThrowDiceGroup(power_);
};


void Unit::Damage(unsigned damage) {
    if (health_ > damage) health_ = health_ - damage;
    else {
        health_ = 0;
        isAlive_ = false;
    };
}


void Unit::Attack(Unit& target) {
    std::cout << name_ << " attacking " << target.name_ << std::endl;
    bool reaching = CheckDist(target);
    if (reaching) {
        bool breaking = CheckBreaking(target);
        if (breaking) {
            unsigned damage = CountDamage();
            std::cout << name_ << " damaged " << target.name_ << " on " << damage << "hp" << std::endl;
            target.Damage(damage);
        }
    }
    std::cout << std::endl;
}


unsigned Unit::GetId() {return id_;}
unsigned Unit::GetHealth() {return health_;}
unsigned Unit::GetMaxHealth() {return maxHealth_;}
DiceGroup Unit::GetPower() {return power_;}
unsigned Unit::GetDexterity() {return dexterity_;}
unsigned Unit::GetDefense() {return defense_;}
unsigned Unit::GetAttackDistance() {return attackDistance_;}
Cage Unit::GetPosition() {return position_;}
bool Unit::IsAlive() {return isAlive_;}