//
// Created by nikit on 11.03.2026.
//

#ifndef SESC_CORE_HERO_H
#define SESC_CORE_HERO_H
#include "Enemy.h"
#include "CombatClass.h"
#include "Species.h"

class Hero : public Enemy {
private:
    CombatClass combatClass_;
    Species species_;
public:
    Hero (unsigned id);
};


#endif //SESC_CORE_HERO_H