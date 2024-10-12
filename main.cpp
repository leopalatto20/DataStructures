#include <iostream>
#include "MonsterCatalogue.h"
#include "Dungeon.h"
#define ROOMS 20

using namespace std;

int main() {
    srand(time(0));
    MonsterCatalogue catalogue;
    Dungeon dungeon;

    if(!catalogue.loadFromCSV()) {
        cout << "No se pudo crear el catalogo\n";
        return 0;
    }

    cout << "Crear dungeon...\n";
    for(int i = 0; i < ROOMS; i++) {
        Monster *pMonster = nullptr, copyMonster;

        pMonster = catalogue.getMonster();
        if(!pMonster) {
            cout << "No se pudo obtener un monstruo\n";
            return 0;
        }

        copyMonster = *pMonster;
        if(!dungeon.createRoom(copyMonster)) {
            cout << "No se pudo crear un cuarto\n";
            return 0;
        }
    }
    dungeon.printRooms();
}
