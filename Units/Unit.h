//
// Created by nikit on 11.03.2026.
//

#ifndef SESC_CORE_ENEMY_H
#define SESC_CORE_ENEMY_H
#include "../Units/Helpers/Cage.h"
#include <random>
#include "../Units/Helpers/Dice.h"
#include <iostream>

struct UnsgndParameter {
    std::string name_;
    unsigned defualt;
};

class Unit {
protected:
    bool isAlive_;
    unsigned id_;
    unsigned health_;
    unsigned maxHealth_;
    DiceGroup power_;
    unsigned dexterity_;
    unsigned defense_;
    unsigned attackDistance_;
    Cage position_;

public:
    std::string name_;

    Unit(unsigned id);
    Unit(){};

    void Move();
    bool CheckDist(Unit target);
    unsigned CountDamage();
    bool CheckBreaking(Unit target);
    void Damage(unsigned damage);
    void Attack(Unit& target);


    unsigned GetId();
    unsigned GetHealth();
    unsigned GetMaxHealth();
    DiceGroup GetPower();
    unsigned GetDexterity();
    unsigned GetDefense();
    unsigned GetAttackDistance();
    Cage GetPosition();
    bool IsAlive();

protected:
    unsigned SetInt(std::string str, unsigned defualt);

    void SetName();
    void SetMaxHealth();
    void SetPower();
    void SetDexterity();
    void SetDefense();
    void SetAttackDistance();
    void SetPosition();
    void SetHealth(int health);
};


#endif //SESC_CORE_ENEMY_H