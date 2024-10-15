#include "MonsterCatalogue.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

bool MonsterCatalogue::addMonster(Monster& monster) {
    return catalogue.insert(monster);
}

bool MonsterCatalogue::loadFromCSV() {
    ifstream file(csv);

    if(!file.is_open()) {
        return false;
    }

    string line;

    getline(file, line); //saltar la primer linea
    while(getline(file, line)) {
        string name, type, size, align, cell;
        double cr;
        int ac, hp;
        stringstream ss(line);
        int count(0);

        while(getline(ss, cell, ',')) {
            switch(count) {
                case 0: {
                    name = cell;
                    break;
                }
                case 1: {
                    cr = stod(cell);
                    break;
                }
                case 2: {
                    type = cell;
                    break;
                }
                case 3: {
                    size = cell;
                    break;
                }
                case 4: {
                    ac = stoi(cell);
                    break;
                }
                case 5: {
                    hp = stoi(cell);
                    break;
                }
                case 6: {
                    align = cell;
                    break;
                }
                default: {
                    return false;
                }
            }
            count++;
        }
        Monster monster(name, cr, type, size, ac, hp, align);
        catalogue.insert(monster);
    }
    file.close();
    return true;
}

void MonsterCatalogue::displayMonsters() {
    catalogue.displayTree();
}

Monster* MonsterCatalogue::getMonster() {
    int wantedMonster = rand() % 763;
    Monster* foundMonster = catalogue.searchInOrder(wantedMonster);

    return foundMonster;
}
