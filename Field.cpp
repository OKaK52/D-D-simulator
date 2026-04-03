#include "Field.h"
#include <iostream>
#include <limits>

Field::Field(int numPlayers) {
    std::cout << "\n=== GAME SETUP ===\n";
    std::cout << "Enter field size (3-10): ";
    std::cin >> fieldSize_;
    if (fieldSize_ < 3) fieldSize_ = 3;
    if (fieldSize_ > 10) fieldSize_ = 10;

    // Создание героев
    for (int i = 1; i <= numPlayers; i++) {
        Hero hero(i);
        hero.CreateCharacter();
        heroes_.push_back(hero);
    }

    currentHeroIndex_ = 0;
    PlaceHeroesOnField();
}

void Field::PlaceHeroesOnField() {
    // Расставляем героев по углам и краям
    int positions[][2] = {{0,0}, {0, fieldSize_-1}, {fieldSize_-1, 0}, {fieldSize_-1, fieldSize_-1}};

    for (int i = 0; i < heroes_.size() && i < 4; i++) {
        heroes_[i].SetPosition({positions[i][0], positions[i][1]});
    }

    // Если игроков больше 4, ставим остальных по краям
    if (heroes_.size() > 4) {
        heroes_[4].SetPosition({fieldSize_/2, 0});
    }
    if (heroes_.size() > 5) {
        heroes_[5].SetPosition({fieldSize_/2, fieldSize_-1});
    }
}

void Field::UpdateDisplayField() {
    // Создаём пустое поле
    displayField_ = std::vector<std::vector<char>>(fieldSize_, std::vector<char>(fieldSize_, ' '));

    // Расставляем живых героев
    for (const auto& hero : heroes_) {
        if (hero.IsAlive()) {
            Cage pos = hero.GetPosition();
            if (pos.x >= 0 && pos.x < fieldSize_ && pos.y >= 0 && pos.y < fieldSize_) {
                displayField_[pos.x][pos.y] = hero.GetAvatar();
            }
        }
    }
}

void Field::DrawField() {
    UpdateDisplayField();

    std::cout << "\n  ";
    for (int j = 0; j < fieldSize_; j++) {
        std::cout << " " << j << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < fieldSize_; i++) {
        std::cout << i << " ";
        for (int j = 0; j < fieldSize_; j++) {
            std::cout << "[" << displayField_[i][j] << "]";
        }
        std::cout << "\n";
    }

    // Вывод статистики героев
    std::cout << "\n--- Heroes Status ---\n";
    for (const auto& hero : heroes_) {
        if (hero.IsAlive()) {
            std::cout << hero.GetAvatar() << ". " << hero.GetName()
                      << " | HP: " << hero.GetHealth()
                      << " | Pos: (" << hero.GetPosition().x << "," << hero.GetPosition().y << ")\n";
        } else {
            std::cout << hero.GetAvatar() << ". " << hero.GetName() << " - DEFEATED\n";
        }
    }
}

bool Field::CheckWin() {
    int aliveCount = 0;
    for (const auto& hero : heroes_) {
        if (hero.IsAlive()) aliveCount++;
    }
    return aliveCount <= 1;
}

void Field::NextTurn() {
    do {
        currentHeroIndex_ = (currentHeroIndex_ + 1) % heroes_.size();
    } while (!heroes_[currentHeroIndex_].IsAlive());
}

void Field::StartGame() {
    std::cout << "\n========================================\n";
    std::cout << "              GAME START!              \n";
    std::cout << "========================================\n";

    int turnCount = 0;

    while (!CheckWin()) {
        turnCount++;
        std::cout << "\n========== TURN " << turnCount << " ==========\n";

        while (!heroes_[currentHeroIndex_].IsAlive()) {
            currentHeroIndex_ = (currentHeroIndex_ + 1) % heroes_.size();
        }

        DrawField();
        std::cout << "\n>>> " << heroes_[currentHeroIndex_].GetName()
                  << "'s turn (Hero " << heroes_[currentHeroIndex_].GetAvatar() << ") <<<\n";

        heroes_[currentHeroIndex_].action(heroes_);  // <- ВОТ ТАК, маленькая 'a'

        currentHeroIndex_ = (currentHeroIndex_ + 1) % heroes_.size();
    }

    std::cout << "\n========================================\n";
    std::cout << "              GAME OVER!               \n";
    std::cout << "========================================\n";

    for (const auto& hero : heroes_) {
        if (hero.IsAlive()) {
            std::cout << "\n🏆 WINNER: " << hero.GetName() << " (Hero " << hero.GetAvatar() << ")!\n";
        }
    }
}