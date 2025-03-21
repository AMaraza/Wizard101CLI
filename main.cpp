#include <iostream>
#include "headers/spells.h"
#include "headers/combat.h"
#include "headers/player.h"

int main() {
    std::vector<DamageSpell> damageSpells = createDamageSpells();
    std::vector<HealSpell> healSpells = createHealSpells();
    Player player(1, 500, 50, "storm");
    Enemy enemy(110, "death");

    int damageSpellSize = damageSpells.size();
    //int healSpellSize = healSpells.size();

    std::vector<Spell> spells;
    spells.reserve(damageSpells.size());
    spells.reserve(healSpells.size());


    for (const DamageSpell& spell : damageSpells) {
        spells.push_back(spell);
    }

    for (const HealSpell& spell : healSpells) {
        spells.push_back(spell);
    }

    int enemyHealth = enemy.currentHealth;
    int playerHealth = player.currentHealth;
    int choice;
    bool enemyAlive = true;

    do {
        std::cout << "Enemy Health: " << enemyHealth << std::endl;
        std::cout << "Player Health: " << playerHealth << std::endl;

        std::cout << "\nSpells: " << std::endl;
        for (int i = 0; i < spells.size(); i++) {
            std::cout << i + 1 << ". " << spells[i].spellName << ": " << spells[i].spellDescription << std::endl;
        }
        std::cout << "9. Pass";
        std::cout << std::endl;

        std::cout << "Select a Spell: (" << "1-" << spells.size() << ")" << std::endl;
        std::cin >> choice;

        if (choice < 1) {
            std::cout << "Invalid Choice" << std::endl;
        }
        else {
            if (choice > damageSpells.size() && choice <= healSpells.size() + damageSpells.size()) {
                choice -= damageSpellSize;
                playerHealth += castHealSpell(choice, healSpells);
            }
            else if (choice < damageSpells.size()) {
                enemyHealth -= castDamageSpell(choice, damageSpells);
            }
            else if (choice > healSpells.size() + damageSpells.size()) {
                std::cout << "Turn Passed";
            }

            if (enemyHealth <= 0) {
                enemyHealth = 0;
                enemyAlive = false;
            }
        }
    } while (enemyAlive);


    return 0;
}