//
// Created by nikit on 11.03.2026.
//

#ifndef SESC_CORE_ENEMY_H
#define SESC_CORE_ENEMY_H
#include "Cage.h"
#include <random>
#include <map>
#include "Dice.h"
#include <iostream>

struct UnsgndParameter {
    std::string name_;
    unsigned defualt;
};

class Enemy {
protected:
    unsigned id_;
    unsigned health_;
    unsigned maxHealth_;
    DiceGroup power_;
    unsigned dexterity_;
    unsigned defense_;
    unsigned attackDistance_;
    Cage position_;

public:
    Enemy(unsigned id);
    void Move();
    bool CheckDist();
    unsigned CountDamage(DiceGroup);
    void Attack();
    unsigned GetPosition();

private:
    unsigned SetInt(std::string str, unsigned defualt);

    void SetMaxHealth();
    void SetPower();
    void SetDexterity();
    void SetDefense();
    void SetAttackDistance();
    void SetPosition();
};


#endif //SESC_CORE_ENEMY_H