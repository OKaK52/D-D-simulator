#ifndef SPECIES_H
#define SPECIES_H

#include <string>

class Species {
private:
    std::string name_;
    dice power_;
    int dexterity_;
    int defense_;

public:
    Species();

    Species(const std::string& name, dice power, int dexterity, int defense);

    void ChooseSpecies();

    std::string GetName() const;
    int GetPower() const;
    int GetDexterity() const;
    int GetDefense() const;

    void SetName(const std::string& name);
    void SetPower(dice power);
    void SetDexterity(int dexterity);
    void SetDefense(int defense);
};

#endif // SPECIES_H