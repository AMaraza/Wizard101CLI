#ifndef COMBAT_H
#define COMBAT_H
#include <iostream>
#include <vector>
#include "spells.h"
#include <random>

inline int castDamageSpell(int spellChoice, std::vector<DamageSpell>& spells) {
    int minDamage = 0, maxDamage = 0;
    int finalDamage = 0;
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> fizzle(0, 100);
    int fizzleChance = fizzle(gen);

    for (int i = 0; i < spells.size(); i++) {
        if (i == spellChoice - 1) {
            if (fizzleChance < spells[i].spellAccuracy) {
                std::cout << "Casting: " << spells[i].spellName << std::endl;
                minDamage = spells[i].lowerDamageRange;
                maxDamage = spells[i].upperDamageRange;
                std::uniform_int_distribution<> distrib(minDamage, maxDamage);
                finalDamage = distrib(gen);
                std::cout << "Damage Dealt: " << finalDamage << std::endl;
            }
            else if (fizzleChance > spells[i].spellAccuracy) {
                std::cout << "Casting: " << spells[i].spellName << std::endl;
                std::cout << "Spell Fizzled" << std::endl;
                return 0;
            }
        }
    }
    return finalDamage;
}

inline int castHealSpell(int spellChoice, std::vector<HealSpell>& spells) {
    for (int i = 0; i < spells.size(); i++) {
       if (i == spellChoice - 1) {
           std::cout << "Casting: " << spells[i].spellName << std::endl;
           return spells[i].spellHealAmount;
       }
    }
    return 0;
}

#endif //COMBAT_H
