#include "Species.h"
#include <iostream>
#include <limits>

Species::Species() : name_(""), power_(0), dexterity_(0), defense_(0) {}

Species::Species(const std::string& name, dice power, int dexterity, int defense)
    : name_(name), power_(power), dexterity_(dexterity), defense_(defense) {}

void Species::ChooseSpecies() {
    int choice;

    std::cout << "Choose your species:" << std::endl;
    std::cout << "1. Elf" << std::endl;
    std::cout << "2. Dwarf" << std::endl;
    std::cout << "3. Human" << std::endl;
    std::cout << "Enter your choice (1-3): ";

    std::cin >> choice;

    switch(choice) {
        case 1: // Elf
            name_ = "Elf";
            power_ = 5;
            dexterity_ = 10;
            defense_ = 4;
            break;

        case 2: // Dwarf
            name_ = "Dwarf";
            power_ = 9;
            dexterity_ = 3;
            defense_ = 8;
            break;

        case 3: // Human
            name_ = "Human";
            power_ = 7;
            dexterity_ = 6;
            defense_ = 6;
            break;

        default:
            std::cout << "Invalid choice. Defaulting to Human." << std::endl;
            name_ = "Human";
            power_ = 7;
            dexterity_ = 6;
            defense_ = 6;
            break;
    }

    std::cout << "You chose: " << name_ << std::endl;
    std::cout << "Stats - Power: " << power_
              << ", Dexterity: " << dexterity_
              << ", Defense: " << defense_ << std::endl;
}

std::string Species::GetName() const {
    return name_;
}

dice Species::GetPower() const {
    return power_;
}

int Species::GetDexterity() const {
    return dexterity_;
}

int Species::GetDefense() const {
    return defense_;
}


void Species::SetName(const std::string& name) {
    name_ = name;
}

void Species::SetPower(dice power) {
    power_ = power;
}

void Species::SetDexterity(int dexterity) {
    dexterity_ = dexterity;
}

void Species::SetDefense(int defense) {
    defense_ = defense;
}