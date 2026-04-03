#ifndef SPECIES_H
#define SPECIES_H
#include <string>

class Species {
private:
    std::string name_;
    int power_;
    int dexterity_;
    int defense_;

public:
    Species();
    void ChooseSpecies();
    std::string GetName() const { return name_; }
    int GetPower() const { return power_; }
    int GetDexterity() const { return dexterity_; }
    int GetDefense() const { return defense_; }
};

#endif