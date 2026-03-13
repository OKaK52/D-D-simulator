//
// Created by nikit on 11.03.2026.
//

#ifndef SESC_CORE_ENEMY_H
#define SESC_CORE_ENEMY_H
#include "Cage.h"
#include <random>
#include <map>
#include "Dice.h"


class Enemy {
private:
    int id_;
    int health_;
    int maxHealth_;
    DiceGroup totalPower_;
    int totalDexterity_;
    int totalDefense_;
    int atackDistance_;
    Cage position_;
public:
    Enemy(int id);
    void Move();
    bool CheckDist();
    void Attack();
    int CountDamag(DiceGroup);
    int GetPosition();
};


#endif //SESC_CORE_ENEMY_H