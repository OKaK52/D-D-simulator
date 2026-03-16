//
// Created by nikit on 11.03.2026.
//

#ifndef SESC_CORE_ENEMY_H
#define SESC_CORE_ENEMY_H
#include "Cage.h"
#include <random>
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
    Enemy(){};

    void Move();
    bool CheckDist();
    unsigned CountDamage(Enemy attackedEnemy);
    bool CheckBreaking(Enemy attackedEnemy);
    void Damage(unsigned damage);
    void Attack(Enemy attackedEnemy);


    unsigned GetId();
    unsigned GetHealth();
    unsigned GetMaxHealth();
    DiceGroup GetPower();
    unsigned GetDexterity();
    unsigned GetDefense();
    unsigned GetAttackDistance();
    Cage GetPosition();

protected:
    unsigned SetInt(std::string str, unsigned defualt);

    void SetMaxHealth();
    void SetPower();
    void SetDexterity();
    void SetDefense();
    void SetAttackDistance();
    void SetPosition();
    void SetHealth(int health);
};


#endif //SESC_CORE_ENEMY_H