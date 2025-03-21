//
// Created by Ally Maraza on 3/21/25.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <utility>

class Player {
    public:
    int playerLevel;
    int currentHealth;
    int healthMax;
    int currentMana;
    int manaMax;
    int currentPips;
    std::string playerSchool;
    Player(int level, int health, int mana, std::string school) : playerLevel(level), healthMax(health), manaMax(mana), currentPips(1), playerSchool(std::move(school)) {
        currentHealth = health;
        currentMana = mana;
    }
};

class Enemy {
    public:
    int currentHealth;
    int healthMax;
    int currentPips;
    std::string enemySchool;
    Enemy(int health, std::string school) : healthMax(health), currentPips(1), enemySchool(std::move(school)){
        currentHealth = health;
    };
};

#endif //PLAYER_H

