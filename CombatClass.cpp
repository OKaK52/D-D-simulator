#include "CombatClass.h"
#include <iostream>
#include <limits>
CombatClass::CombatClass() {
    int ameba;
    std::cout << "Choose your CombatClass:" << std::endl;
    std::cout << "1 - Archer" << std::endl;
    std::cout << "2 - Warrior" << std::endl;
    std::cout << "Enter your choose(1-2):" << std::endl;
    std::cin >> ameba;
    switch(ameba) {
        case 1:
            name_ = "Warrior";
            power_ = 10;
            dexterity_ = 2;
            defense_ = 20;
            break;
        case 2:
            name_ = "Archer";
            power_ = 15;
            dexterity_ = 20;
            defense_ = 5;
            break;
        default:
            std::cout << "invalid choose. Defaulting to Warrior" << std::endl;
            name_ = "Warrior";
            power_ = 10;
            dexterity_ = 2;
            defense_ = 20;
            break;
    }
    std::cout << "You chose:" << name_ << std::endl;
    std::cout << "Stats: power:" << power_ << "dexterity:" << dexterity_ << "defense:" << defense_ << std::endl;
}
std::string CombatClass::GetName() const {
    return name_;
}
int CombatClass::GetPower() const {
    return power_;
}
int CombatClass::GetDefense() const {
    return defense_;
}
int CombatClass::GetDexterity() const {
    return dexterity_;
}
void CombatClass::SetName(const std::string& name) {
    name_ = name;
}
void CombatClass::SetPower(int power) {
    power_ = power;
}
void CombatClass::SetDefense(int defense) {
    defense_ = defense;
}
void CombatClass::SetDexterity(int dexterity) {
    dexterity_ = dexterity;
}