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

    std::string GetName() const;
    int GetPower() const;
    int GetDexterity() const;
    int GetDefense() const;

    void SetName(const std::string& name);
    void SetPower(int power);
    void SetDexterity(int dexterity);
    void SetDefense(int defense);
};

#endif // SPECIES_H