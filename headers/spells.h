#ifndef SPELLS_H
#define SPELLS_H
#include <iostream>
#include <utility>
#include <vector>


class Spell{
    public:
        std::string spellName;
        std::string spellSchool;
        std::string spellDescription;
        int spellAccuracy;
        int spellPipCount;
        Spell(std::string name, std::string school, std::string description, int accuracy, int pipCount) : spellName(std::move(name)), spellSchool(std::move(school)), spellDescription(std::move(description)), spellAccuracy(accuracy), spellPipCount(pipCount) {};
};

class DamageSpell : public Spell{
    public:
        int lowerDamageRange;
        int upperDamageRange;
        DamageSpell(std::string name, std::string school, std::string description, int accuracy, int pipCount, int lowerDamage, int upperDamage) : Spell(std::move(name), std::move(school), std::move(description), accuracy, pipCount), lowerDamageRange(lowerDamage), upperDamageRange(upperDamage) {};
};

class HealSpell : public Spell {
    public:
        int spellHealAmount;
        HealSpell(std::string name, std::string school, std::string description, int accuracy, int pipCount, int healAmount) : Spell(std::move(name), std::move(school), std::move(description), accuracy, pipCount), spellHealAmount(healAmount) {};
};

inline void displayDamageSpells(const std::vector<DamageSpell>& damageSpells) {
    std::cout << "Damage Spells:" << std::endl;
    for (int i = 0; i < damageSpells.size(); i++) {
        std::cout << i+1 << ". " << damageSpells[i].spellName << " " << damageSpells[i].spellDescription << std::endl;
    }
    std::cout << std::endl;
}

inline void displayHealSpells(const std::vector<HealSpell>& healSpells) {
    std::cout << "Heal Spells:" << std::endl;
    for (int i = 0; i < healSpells.size(); i++) {
        std::cout << i + 1 << ". " << healSpells[i].spellName << " " << healSpells[i].spellDescription << std::endl;
    }

    std::cout << std::endl;
}

inline std::vector<DamageSpell> createDamageSpells() {
    return {
        {"Fire Cat", "fire", "Deals 70-110 Damage, 75% Accuracy, 1 Pip", 75, 1, 70, 110},
        {"Frost Beetle", "ice", "Deals 55-95 Damage, 80% Accuracy, 1 Pip", 80, 1, 55, 95},
        {"Thunder Snake", "storm", "Deals 95-135 Damage, 75% Accuracy, 1 Pip", 85, 1, 95, 135},
        {"Blood Bat", "myth", "Deals 60-100 Damage, 80% Accuracy, 1 Pip", 80, 1, 60, 100},
        {"Imp", "life", "Deals 55-95 Damage, 90% Accuracy, 1 Pip", 90, 1, 55, 95},
        {"Dark Sprite", "death", "Deals 55-95 Damage, 85% Accuracy, 1 Pip", 85, 1, 55, 95},
        {"Scarab", "balance", "Deals 55-95 Damage, 85% Accuracy, 1 Pip", 85, 1, 55, 95}
    };
}

inline std::vector<HealSpell> createHealSpells() {
    return {
    {"Heartbeat", "life", "Heals 245 Health, 90% Accuracy, 1 Pip", 90, 1, 245}
    };
}

#endif //SPELLS_H
