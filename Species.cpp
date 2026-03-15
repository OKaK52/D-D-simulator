#include "Species.h"
#include <iostream>
#include <limits>


Species::Species() {
    int choice;

    std::cout << "Choose your species: " << std::endl;
    std::cout << "1. Elf" << std::endl;
    std::cout << "2. Dwarf" << std::endl;
    std::cout << "3. Human" << std::endl;
    std::cout << "Enter your choice (1-3): ";

    std::cin >> choice;

    switch(choice) {
        case 1: // Elf
            name_ = "Elf";
            maxHealth_ = 20;
            dexterity_ = 10;
            defense_ = 4;
            break;

        case 2: // Dwarf
            name_ = "Dwarf";
            maxHealth_ = 35;
            dexterity_ = 3;
            defense_ = 8;
            break;

        case 3: // Human
            name_ = "Human";
            maxHealth_ = 30;
            dexterity_ = 6;
            defense_ = 6;
            break;

        default:
            std::cout << "Invalid choice. Defaulting to Human." << std::endl;
            name_ = "Human";
            maxHealth_ = 30;
            dexterity_ = 6;
            defense_ = 6;
            break;
    }

    std::cout << "You chose: " << name_ << std::endl;
    std::cout << "Species stats: " << std::endl
              << "MaxHealth: " << maxHealth_ << std::endl
              << "Dexterity: " << dexterity_ << std::endl
              << "Defense: " << defense_ << std::endl;
}

std::string Species::GetName() const {
    return name_;
}

unsigned Species::GetMaxHealth() const {
    return maxHealth_;
}

unsigned Species::GetDexterity() const {
    return dexterity_;
}

unsigned Species::GetDefense() const {
    return defense_;
}