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

    getline(file, line); //saltar la primer linea
    while(getline(file, line)) {
        string name;
        int damage;

        istringstream ss(line);

        getline(ss, name, ',');
        ss >> damage;
        ss.ignore();

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
    playerSpells.printList();
}


