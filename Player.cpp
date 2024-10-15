#include "Player.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Player::Player(string name, string build) : name(name), build(build), MAX_SPELLS(determineMaxSpells(build)) {
}

int Player::determineMaxSpells(const string &build) {
    if(build == "strength")
        return 5;
    if(build == "dexterity")
        return 6;
    if(build == "intelligence")
        return 10;
}


void Player::showInfo() {
    cout << "Player: " << name << "\n";
    cout << "Build: " << build << "\n";
    cout << "Spells list: \n";
    playerSpells.printInOrder();
}

bool Player::loadSpell(Spell spell) {
    return playerSpells.insertData(spell);
}

int Player::getMaxSpells() {
    return this->MAX_SPELLS;
}

bool Player::checkForDuplicateSpells(Spell spell) {
    return playerSpells.checkForExistent(spell);
}

bool Player::addSpell(Spell spell) {
    return playerSpells.insertData(spell);
}
