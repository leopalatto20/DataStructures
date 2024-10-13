#include "Player.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Player::Player(string name, string build) : name(name), build(build) {
    for(int i = 0; i < SPELLS; i++) {
        playerSpells[i] = Spell();
    }
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
    int counter(0);

    getline(file, line); //saltar la primer linea
    while(getline(file, line)) {
        string name;
        int damage;

        istringstream ss(line);

        getline(ss, name, ',');
        ss >> damage;

        Spell spell(name, damage);
        playerSpells[counter] = spell;
        counter++;
    }
    file.close();
    return true;
}

void Player::showInfo() {
    cout << "Name: " << name << "\n";
    cout << "Build: " << build << "\n";
    for(int i = 0; i < SPELLS; i++) {
        cout << "Spell " << i + 1 << ": " << playerSpells[i] << "\n";
    }
}

