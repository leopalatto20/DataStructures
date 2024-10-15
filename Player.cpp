#include "Player.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Player::Player(string name, string build) : name(name), build(build) {
}

bool Player::loadBuild() {
    if(build == "dexterity")
        return loadSpells(DEXTERITY_SPELLS);
    if(build == "strength")
        return loadSpells(STRENGTH_SPELLS);
    return false;
}

bool Player::loadSpells(string filename) {
    ifstream file(filename);

    if(!file.is_open()) {
        return false;
    }

    string line;

    if(!getline(file, line)) {
        file.close();
        return false;
    }

    while(getline(file, line)) {
        string cell, name;
        int damage, count(0);
        stringstream ss(line);

        while(getline(ss, cell, ',')) {
            switch(count) {
                case 0: {
                    name = cell;
                    break;
                }
                case 1: {
                    damage = stoi(cell);
                    break;
                }
            }
            count++;
        }
        Spell spell(name, damage);
        playerSpells.insertData(spell);
    }
    file.close();
    return true;
}

void Player::showInfo() {
    cout << "Player: " << name << "\n";
    cout << "Build: " << build << "\n";
    cout << "Spells list: \n";
    playerSpells.printInOrder();
}
