#include "Species.h"
#include <iostream>

Species::Species() : name_("Human"), power_(7), dexterity_(6), defense_(6) {}

void Species::ChooseSpecies() {
    int choice;
    std::cout << "Choose species:\n";
    std::cout << "1. Elf (Power+5, Dexterity+10, Defense+4)\n";
    std::cout << "2. Dwarf (Power+9, Dexterity+3, Defense+8)\n";
    std::cout << "3. Human (Power+7, Dexterity+6, Defense+6)\n";
    std::cout << "Enter choice (1-3): ";
    std::cin >> choice;

    switch(choice) {
        case 1:
            name_ = "Elf"; power_ = 5; dexterity_ = 10; defense_ = 4;
            break;
        case 2:
            name_ = "Dwarf"; power_ = 9; dexterity_ = 3; defense_ = 8;
            break;
        case 3:
            name_ = "Human"; power_ = 7; dexterity_ = 6; defense_ = 6;
            break;
        default:
            std::cout << "Invalid, defaulting to Human\n";
            name_ = "Human"; power_ = 7; dexterity_ = 6; defense_ = 6;
    }
    std::cout << "Chosen: " << name_ << "\n";
}