#ifndef SESC_CORE_COMBATCLASS_H
#define SESC_CORE_COMBATCLASS_H
#include <iostream>
#include <string>
#include "Dice.h"

enum ClassName {Warrior, Archer};

class CombatClass{
private:
    ClassName name_;
    DiceGroup power_;
    unsigned attackDistance_;
    unsigned dexterity_;
    unsigned defense_;

public:
    CombatClass();

    ClassName GetName() const;
    DiceGroup GetPower() const;
    unsigned GetAttackDistance() const;
    unsigned GetDexterity() const;
    unsigned GetDefense() const;
};
#endif //SESC_CORE_COMBATCLASS_H