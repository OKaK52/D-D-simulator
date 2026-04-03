#ifndef HERO_H
#define HERO_H

#include "Cage.h"
#include "Species.h"
#include "CombatClass.h"
#include <string>
#include <vector>

class Hero {
private:
    int id_;
    std::string name_;
    Cage position_;
    Species species_;
    CombatClass combatClass_;
    int health_;
    int maxHealth_;
    bool wasAttacking_;

public:
    Hero(int id);
    void CreateCharacter();

    int GetId() const { return id_; }
    Cage GetPosition() const { return position_; }
    void SetPosition(Cage pos) { position_ = pos; }
    char GetAvatar() const { return '0' + id_; }
    bool IsAlive() const { return health_ > 0; }
    std::string GetName() const { return name_; }
    int GetHealth() const { return health_; }

    int GetTotalDexterity() const;
    int GetTotalPower() const;
    int GetTotalDefense() const;

    void action(std::vector<Hero>& heroes);  // <- ЭТОТ МЕТОД ДОЛЖЕН БЫТЬ
    void Attack(Hero& target);
    void TakeDamage(int damage);
    void PrintStats();
    void Move(int dx, int dy);
};

#endif