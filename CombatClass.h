#ifndef SESC_CORE_COMBATCLASS_H
#define SESC_CORE_COMBATCLASS_H
#include <iostream>
#include <string>
class CombatClass {
private:
    std::string name_;
    int power_;
    int dexterity_;
    int defense_;
public:
    CombatClass();
    CombatClass(const std::string& name, int power, int dexterity, int defense);
    void ChooseClass();
    std::string GetName() const;
    int GetPower() const;
    int GetDexterity() const;
    int GetDefense() const;
    void SetName(const std::string& name);
    void SetPower(int power);
    void SetDexterity(int dexterity);
    void SetDefense(int defense);
};
#endif //SESC_CORE_COMBATCLASS_H