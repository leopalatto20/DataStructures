#include "Player.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Player::Player(string name, string build) : name(name), build(build), maxSpells(0), hp(0) {
}

bool Player::loadStats() {
    if(build == "strength") {
        this->maxSpells = 5;
        this->hp = 75;
        return true;
    }
    if(build == "dexterity") {
        this->maxSpells = 6;
        this->hp = 60;
        return true;
    }
    if(build == "intelligence") {
        this->maxSpells = 10;
        this->hp = 45;
        return true;
    }
    return false;
}



void Player::showInfo() {
    cout << "Player: " << name << "\n";
    cout << "Build: " << build << "\n";
    cout << "Hp: " << hp << "\n";
    cout << "Spells list: \n";
    playerSpells.printInOrder();
    cout << "Defeated monsters: \n";
    defeatedMonsters.displayMonstersInOrder();
}

int Player::getMaxSpells() {
    return this->maxSpells;
}

bool Player::checkForDuplicateSpells(Spell spell) {
    return playerSpells.checkForExistent(spell);
}

bool Player::addSpell(Spell spell) {
    return playerSpells.insertData(spell);
}

bool Player::addMonster(Monster &monster) {
    return defeatedMonsters.addMonster(monster);
}
