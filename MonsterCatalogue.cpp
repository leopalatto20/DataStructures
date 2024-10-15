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
        string name, type, size, align;
        double cr;
        int ac, hp;
        istringstream ss(line);

        getline(ss, name, ',');
        ss >> cr;
        ss.ignore();
        getline(ss, type, ',');
        getline(ss, size, ',');
        ss >> ac;
        ss.ignore();
        ss >> hp;
        ss.ignore();
        getline(ss, align);

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
