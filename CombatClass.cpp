#include "CombatClass.h"
#include <iostream>

CombatClass::CombatClass() : name_("Warrior"), power_(10), dexterity_(2), defense_(20) {}

void CombatClass::ChooseClass() {
    int choice;
    std::cout << "Choose class:\n";
    std::cout << "1. Warrior (Power+10, Dexterity+2, Defense+20)\n";
    std::cout << "2. Archer (Power+15, Dexterity+20, Defense+5)\n";
    std::cout << "Enter choice (1-2): ";
    std::cin >> choice;

    switch(choice) {
        case 1:
            name_ = "Warrior"; power_ = 10; dexterity_ = 2; defense_ = 20;
            break;
        case 2:
            name_ = "Archer"; power_ = 15; dexterity_ = 20; defense_ = 5;
            break;
        default:
            std::cout << "Invalid, defaulting to Warrior\n";
            name_ = "Warrior"; power_ = 10; dexterity_ = 2; defense_ = 20;
    }
    std::cout << "Chosen: " << name_ << "\n";
}