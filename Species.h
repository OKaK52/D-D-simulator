#ifndef SPECIES_H
#define SPECIES_H

#include <string>
#include "Dice.h"

class Species {
private:
    std::string name_;
    int maxHealth_;
    int dexterity_;
    int defense_;

public:
    Species();

    std::string GetName() const;
    int GetMaxHealth() const;
    int GetDexterity() const;
    int GetDefense() const;
};

#endif // SPECIES_H