//
// Created by nikit on 11.03.2026.
//

#include "../Units/Hero.h"

unsigned mean (const unsigned& a, const unsigned& b) {
    return (a + b) / 2 + (a + b) % 2;
}

Hero::Hero (unsigned id) {
    id_ = id;
    SetAvatar();
    maxHealth_ = species_.GetMaxHealth();
    health_ = maxHealth_;
    dexterity_ = species_.GetDexterity() + combatClass_.GetDexterity();
    defense_ = species_.GetDefense() + combatClass_.GetDefense();
    attackDistance_ = combatClass_.GetAttackDistance();
    power_ = combatClass_.GetPower();
    SetPosition();
};