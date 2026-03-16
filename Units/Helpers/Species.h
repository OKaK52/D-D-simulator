#ifndef SPECIES_H
#define SPECIES_H

#include <string>
#include "Dice.h"

class Species {
private:
    std::string name_;
    unsigned maxHealth_;
    unsigned dexterity_;
    unsigned defense_;

public:
    Species();

    std::string GetName() const;
    unsigned GetMaxHealth() const;
    unsigned GetDexterity() const;
    unsigned GetDefense() const;
};

#endif // SPECIES_H