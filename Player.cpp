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
        this->mp = 100;
        this->defaultAttack = Spell("Lions Claw", 15, 0);
        return true;
    }
    if(build == "dexterity") {
        this->maxSpells = 6;
        this->hp = 60;
        this->mp = 100;
        this->defaultAttack = Spell("Ichimonji", 10, 0);
        return true;
    }
    if(build == "intelligence") {
        this->maxSpells = 10;
        this->hp = 45;
        this->mp = 100;
        this->defaultAttack = Spell("Glintsote Pebble", 3, 0);
        return true;
    }
    return false;
}



void Player::showInfo() {
    cout << "Player: " << name << "\n";
    cout << "Build: " << build << "\n";
    cout << "Hp: " << hp << "\n";
    cout << "Default attack: " << defaultAttack << "\n";
    cout << "Spells list: \n";
    playerSpells.printInOrder();
    cout << "Defeated monsters: \n";
    defeatedMonsters.displayMonstersInOrder();
}

void Player::showSpells() {
    playerSpells.printInOrder();
    cout << "Default spell: " << defaultAttack << endl;
}

int Player::getMaxSpells() {
    return this->maxSpells;
}

bool Player::checkForDuplicateSpells(Spell spell) {
    return playerSpells.checkForExistent(spell);
}

bool Player::addSpell(Spell &spell) {
    return playerSpells.insertData(spell);
}

bool Player::addMonster(Monster &monster) {
    return defeatedMonsters.addMonster(monster);
}

 int Player::getSpellDamage(int spellNum) {
    if(spellNum == 0)
        return defaultAttack.getDamage();
    Spell *spell = playerSpells.returnFromNumber(spellNum);
    if(!spell)
        return 0;
    int mpCost = spell->getMpCost();
    if(mp - mpCost < 0)
        return 0;
    return spell->getDamage();
}

int Player::getHp() {
    return this->hp;
}

void Player::setHp(int hp) {
    this->hp = hp;
}