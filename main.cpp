#include <iostream>
#include "MonsterCatalogue.h"
#include "Dungeon.h"
#include "Player.h"
#include "SpellShop.h"
#define ROOMS 20

using namespace std;

int main() {
    srand(time(nullptr));
    MonsterCatalogue catalogue;
    Dungeon dungeon;
    SpellShop spellShop;

    if(!catalogue.loadFromCSV()) {
        cout << "No se pudo crear el catalogo\n";
        return 0;
    }
    if(!spellShop.loadSpells()) {
        cout << "No se pudieron cargar los hechizos\n";
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

    Player player1("barbiGeimpleis", "strength");
    int count = 0;
    while(count < player1.getMaxSpells()) {
        int option;
        spellShop.printInOrder();
        cout << "Enter a number: ";
        cin >> option;
        Spell* pSpell = spellShop.buyByNumber(option), spellCopy;
        if(!pSpell) {
            cout << "Not an existent spell\n";
        }
        else {
            spellCopy = *pSpell;
            if(!spellShop.deleteSpell(spellCopy))
                return 0;
            if(player1.checkForDuplicateSpells(spellCopy)) {
                cout << "You already have that spell\n\n";
            }
            else {
                if(player1.addSpell(spellCopy)) {
                    count++;
                    cout << "Added " << spellCopy << "\n\n";
                }
            }
        }
    }
    cout << endl << "Mostrando informacion del jugador: \n";
    player1.showInfo();

    return 0;
}
