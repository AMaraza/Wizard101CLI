#include <iostream>
#include "headers/spells.h"
#include "headers/combat.h"
#include "headers/player.h"

void drawField(Player& player, Enemy& enemy, std::vector<Spell>& spells);

int main() {
    //Declare Spells, Player, and Enemy
    std::vector<Spell> spells = createSpells();
    Player player(1, 250, 25, "death");
    Enemy enemy(150, "life");
    bool playerTurn = true;

    drawField(player, enemy, spells);

    int choice;
    std::cin >> choice;

    if (choice <= spells.size()) {
        castSpell(spells, choice, player, enemy, playerTurn);
    }
    else if (choice > spells.size()) {
        std::cout << "Turn Passed";
        player.currentPips++;
    }

    std::cout << std::endl;

    std::cout << "Player Health: " << player.currentHealth << " | Player Pips: " << player.currentPips << std::endl;

    std::cout << "Enemy Health: " << enemy.currentHealth << std::endl;

    return 0;
}

std::vector<Spell> createSpells() {
    std::vector<Spell> spells;
    //std::string name, std::string school, std::string description, std::string type, int accuracy, int pipCount, int lowerRange, int upperRange

    //Damage Spells
    Spell fireCat("Fire Cat", "fire", "Deals 70-110 Damage, 75% Accuracy, 1 Pip", "damage", 75, 1, 70, 110);
    Spell frostBeetle("Frost Beetle", "ice", "Deals 55-95 Damage, 80% Accuracy, 1 Pip", "damage", 80, 1, 55, 95);
    Spell thunderSnake("Thunder Snake", "storm", "Deals 95-135 Damage, 75% Accuracy, 1 Pip", "damage", 85, 1, 95, 135);
    Spell bloodBat("Blood Bat", "myth", "Deals 60-100 Damage, 80% Accuracy, 1 Pip", "damage", 80, 1, 60, 100);
    Spell imp("Imp", "life", "Deals 55-95 Damage, 90% Accuracy, 1 Pip", "damage", 90, 1, 55, 95);
    Spell darkSprite("Dark Sprite", "death", "Deals 55-95 Damage, 85% Accuracy, 1 Pip", "damage", 85, 1, 55, 95);
    Spell scarab("Scarab", "balance", "Deals 55-95 Damage, 85% Accuracy, 1 Pip", "damage", 85, 1, 55, 95);

    //Healing Spells
    Spell heartbeat("Heartbeat", "life", "Heals 245 Health, 90% Accuracy, 1 Pip", "heal", 90, 1, 245, 0);

    spells.push_back(fireCat);
    spells.push_back(frostBeetle);
    spells.push_back(thunderSnake);
    spells.push_back(bloodBat);
    spells.push_back(imp);
    spells.push_back(darkSprite);
    spells.push_back(scarab);
    spells.push_back(heartbeat);

    return spells;
}

void drawField(Player& player, Enemy& enemy, std::vector<Spell>& spells) {
    system("clear");
    std::cout << "Player Health: " << player.currentHealth << " | Player Pips: " << player.currentPips << std::endl;
    std::cout << "Enemy Health: " << enemy.currentHealth << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < spells.size(); i++) {
        std::cout << i + 1 << ". " << spells[i].spellName << ": " << spells[i].spellDescription << std::endl;
    }
    std::cout << spells.size() + 1 << ". Pass";

    std::cout << std::endl;
    std::cout << "Choose a Spell(1-9):" << std::endl;
}

void castSpell(const std::vector<Spell>& spells, int choice, Player& player, Enemy& enemy, bool playerTurn) {
    int minDamage = 0, maxDamage = 0;
    int finalDamage = 0;
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> fizzle(0, 100);
    int fizzleChance = fizzle(gen);

    for (int i = 0; i < spells.size(); i++) {
        if (i == choice - 1) {
            if (spells[i].spellType == "damage") {
                if (fizzleChance < spells[i].spellAccuracy) {
                    std::cout << "Casting: " << spells[i].spellName << std::endl;
                    minDamage = spells[i].spellLowerRange;
                    maxDamage = spells[i].spellUpperRange;
                    std::uniform_int_distribution<> distrib(minDamage, maxDamage);
                    finalDamage = distrib(gen);
                    if (playerTurn) {
                        enemy.currentHealth -= finalDamage;
                    }
                    else {
                        player.currentHealth -= finalDamage;
                    }

                    std::cout << "Damage Dealt: " << finalDamage << std::endl;
                }
                else if (fizzleChance > spells[i].spellAccuracy) {
                    std::cout << "Casting: " << spells[i].spellName << std::endl;
                    std::cout << "Spell Fizzled" << std::endl;
                    player.currentPips++;
                }
            }
            else if (spells[i].spellType == "heal") {
                if (spells[i].spellUpperRange == 0) {
                    if (playerTurn && fizzleChance < spells[i].spellAccuracy) {
                        std::cout << "Casting: " << spells[i].spellName << std::endl;
                        player.currentHealth += spells[i].spellLowerRange;
                        std::cout << "Health Healed: " << spells[i].spellLowerRange << std::endl;
                    }
                    else if (!playerTurn && fizzleChance < spells[i].spellAccuracy) {
                        std::cout << "Casting: " << spells[i].spellName << std::endl;
                        enemy.currentHealth += spells[i].spellLowerRange;
                        std::cout << "Health Healed: " << spells[i].spellLowerRange << std::endl;
                    }
                    else {
                        std::cout << "Casting: " << spells[i].spellName << std::endl;
                        std::cout << "Spell Fizzled" << std::endl;
                        player.currentPips++;
                    }
                }
                else {
                    minDamage = spells[i].spellLowerRange;
                    maxDamage = spells[i].spellUpperRange;
                    if (fizzleChance < spells[i].spellAccuracy) {
                        std::cout << "Casting: " << spells[i].spellName << std::endl;
                        minDamage = spells[i].spellLowerRange;
                        maxDamage = spells[i].spellUpperRange;
                        std::uniform_int_distribution<> distrib(minDamage, maxDamage);
                        finalDamage = distrib(gen);
                        if (playerTurn) {
                            player.currentHealth += finalDamage;
                        }
                        else {
                            enemy.currentHealth += finalDamage;
                        }

                        std::cout << "Health Healed: " << finalDamage << std::endl;
                    }
                    else if (fizzleChance > spells[i].spellAccuracy) {
                        std::cout << "Casting: " << spells[i].spellName << std::endl;
                        std::cout << "Spell Fizzled" << std::endl;
                        player.currentPips++;
                    }
                }
            }
        }
    }
}