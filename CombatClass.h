#ifndef COMBATCLASS_H
#define COMBATCLASS_H
#include <string>

class CombatClass {
private:
    std::string name_;
    int power_;
    int dexterity_;
    int defense_;

public:
    CombatClass();
    void ChooseClass();
    std::string GetName() const { return name_; }
    int GetPower() const { return power_; }
    int GetDexterity() const { return dexterity_; }
    int GetDefense() const { return defense_; }
};

#endif