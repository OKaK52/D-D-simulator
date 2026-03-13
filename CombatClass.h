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
    int atackDistance_;
    int dexterity_;
    int defense_;

public:
    CombatClass();

    ClassName GetName() const;
    DiceGroup GetPower() const;
    int GetDexterity() const;
    int GetDefense() const;
};
#endif //SESC_CORE_COMBATCLASS_H