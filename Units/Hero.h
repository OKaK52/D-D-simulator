//
// Created by nikit on 11.03.2026.
//

#ifndef SESC_CORE_HERO_H
#define SESC_CORE_HERO_H
#include "../Units/Unit.h"
#include "../Units/Helpers/CombatClass.h"
#include "Helpers/Species.h"

class Hero : public Unit {
private:
    CombatClass combatClass_;
    Species species_;
public:
    Hero (unsigned id);
};


#endif //SESC_CORE_HERO_H