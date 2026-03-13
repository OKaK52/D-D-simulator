#include "CombatClass.h"
#include <iostream>
#include <limits>
#include <Dice.h>

CombatClass::CombatClass() {
    int ameba;
    std::cout << "Choose your CombatClass:" << std::endl;
    std::cout << "1 - Archer" << std::endl;
    std::cout << "2 - Warrior" << std::endl;
    std::cout << "Enter your choose(1-2):" << std::endl;
    std::cin >> ameba;
    switch(ameba) {
        case 1:
            name_ = Warrior;
            power_ = d10x2;
            atackDistance_ = 1;
            dexterity_ = 2;
            defense_ = 20;
            break;
        case 2:
            name_ = Archer;
            power_ = d6x2;
            atackDistance_ = 6;
            dexterity_ = 20;
            defense_ = 5;
            break;
        default:
            std::cout << "invalid choose. Defaulting to Warrior" << std::endl;
            name_ = Warrior;
            power_ = d10x2;
            atackDistance_ = 1;
            dexterity_ = 2;
            defense_ = 20;
            break;
    }
    std::cout << "You chose:" << name_ << std::endl;
    std::cout << "Stats: power:" << power_ << "dexterity:" << dexterity_ << "defense:" << defense_ << std::endl;
}
ClassName CombatClass::GetName() const {
    return name_;
}
DiceGroup CombatClass::GetPower() const {
    return power_;
}
int CombatClass::GetDefense() const {
    return defense_;
}

int get