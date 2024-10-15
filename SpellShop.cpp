#include "SpellShop.h"
#include <iostream>
#include <fstream>
#include <sstream>
#define SPELLS "Spells.csv"

using namespace std;

bool SpellShop::loadSpells() {
    ifstream file(SPELLS);

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
                default: {
                    return false;
                }
            }
            count++;
        }
        Spell spell(name, damage);
        spellList.insertData(spell);
    }
    file.close();
    return true;
}

void SpellShop::printInOrder() {
    spellList.printInOrder();
}

Spell* SpellShop::buyByNumber(int num) {
    return spellList.returnFromNumber(num);
}