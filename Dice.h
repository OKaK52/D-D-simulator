//
// Created by nikit on 11.03.2026.
//

#ifndef SESC_CORE_DICE_H
#define SESC_CORE_DICE_H


enum Dice: int {d4 = 4, d6 = 6, d8 = 8, d10 = 10, d12 = 12, d20 = 20};
int ThrowDice(Dice diceType);
enum DiceGroup {
    d4x1, d6x1, d8x1, d10x1, d12x1, d20x1,
    d4x2, d6x2, d8x2, d10x2, d12x2, d20x2,
    d4x3, d6x3, d8x3, d10x3, d12x3, d20x3,
    d4x4, d6x4, d8x4, d10x4, d12x4, d20x4,
    d4x5, d6x5, d8x5, d10x5, d12x5, d20x5
};
int ThrowDiceGroup(DiceGroup dices);


#endif //SESC_CORE_DICE_H