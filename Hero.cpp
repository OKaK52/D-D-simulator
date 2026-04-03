#include "Hero.h"
#include <iostream>
#include <cstdlib>

// Конструктор
Hero::Hero(int id) : id_(id), species_(), combatClass_() {
    health_ = 100;
    maxHealth_ = 100;
    wasAttacking_ = false;
    position_ = {0, 0};
    name_ = "";
}

// CreateCharacter
void Hero::CreateCharacter() {
    std::cout << "\n=== Creating Hero " << id_ << " ===\n";
    species_.ChooseSpecies();
    combatClass_.ChooseClass();
    name_ = species_.GetName() + " " + combatClass_.GetName();
    PrintStats();
}

// Геттеры
int Hero::GetTotalDexterity() const {
    return species_.GetDexterity() + combatClass_.GetDexterity();
}

int Hero::GetTotalPower() const {
    return species_.GetPower() + combatClass_.GetPower();
}

int Hero::GetTotalDefense() const {
    return species_.GetDefense() + combatClass_.GetDefense();
}

// Action - ВАЖНО: имя должно совпадать с объявлением в Hero.h
void Hero::action(std::vector<Hero>& heroes) {
    int freeSteps = GetTotalDexterity();
    wasAttacking_ = false;

    std::cout << "\n" << name_ << " (Hero " << id_ << ")\n";
    std::cout << "HP: " << health_ << "/" << maxHealth_ << " | Steps: " << freeSteps << "\n";
    std::cout << "Commands: Move X Y | Attack | End\n> ";

    std::string input;
    std::getline(std::cin, input);

    size_t space = input.find(' ');
    std::string cmd = (space != std::string::npos) ? input.substr(0, space) : input;

    if (cmd == "Move" || cmd == "move") {
        if (space != std::string::npos) {
            std::string rest = input.substr(space + 1);
            size_t space2 = rest.find(' ');
            if (space2 != std::string::npos) {
                int dx = std::stoi(rest.substr(0, space2));
                int dy = std::stoi(rest.substr(space2 + 1));
                int stepsNeeded = abs(dx) + abs(dy);

                if (stepsNeeded <= freeSteps) {
                    position_.x += dx;
                    position_.y += dy;
                    std::cout << "Moved to (" << position_.x << "," << position_.y << ")\n";
                } else {
                    std::cout << "Not enough steps!\n";
                }
            }
        }
    }
    else if (cmd == "Attack" || cmd == "attack") {
        // Ищем цель
        for (int i = 0; i < heroes.size(); i++) {
            if (heroes[i].IsAlive() && heroes[i].GetId() != id_) {
                int distance = position_.countDistance(heroes[i].GetPosition());
                if (distance <= 1) {
                    Attack(heroes[i]);
                    wasAttacking_ = true;
                    break;
                }
            }
        }
        if (!wasAttacking_) {
            std::cout << "No enemies in range!\n";
        }
    }
    else if (cmd == "End" || cmd == "end") {
        std::cout << "Turn ended\n";
    }
    else {
        std::cout << "Unknown command\n";
    }
}

// Attack
void Hero::Attack(Hero& target) {
    int damage = rand() % 30 + GetTotalPower();
    std::cout << "\n*** " << name_ << " attacks " << target.GetName() << "! ***\n";
    std::cout << "Damage: " << damage << "\n";
    target.TakeDamage(damage);
}

// TakeDamage
void Hero::TakeDamage(int damage) {
    health_ -= damage;
    if (health_ < 0) health_ = 0;
    std::cout << name_ << " took " << damage << " damage! HP: " << health_ << "\n";
}

// PrintStats
void Hero::PrintStats() {
    std::cout << "\n--- " << name_ << " (Hero " << id_ << ") ---\n";
    std::cout << "Health: " << health_ << "/" << maxHealth_ << "\n";
    std::cout << "Power: " << GetTotalPower() << "\n";
    std::cout << "Dexterity: " << GetTotalDexterity() << "\n";
    std::cout << "Position: (" << position_.x << "," << position_.y << ")\n";
}

// Move
void Hero::Move(int dx, int dy) {
    position_.x += dx;
    position_.y += dy;
}