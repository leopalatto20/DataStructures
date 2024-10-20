#include <iostream>
#include "main.h"
#define ROOMS 20

using namespace std;

int main() {
    srand(time(0));
    MonsterCatalogue catalogue;
    Dungeon dungeon;
    SpellShop spellShop;

    if(!catalogue.loadFromCSV()) {
        cout << "No se pudo crear el catalogo\n";
        return 0;
    }
    catalogue.displayMonstersInOrder();
    if(!spellShop.loadSpells()) {
        cout << "No se pudieron cargar los hechizos\n";
        return 0;
    }
    cout << endl;

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
    cout << endl;
    dungeon.printRooms();
    cout << endl;
    catalogue.deleteCatalogue(); //Borrar el catalogo despues de cargar los monstruos

    Player player1("barbiGeimpleis", "strength");
    if(!player1.loadStats())
        return 0;
    int count = 0;
    while(count < player1.getMaxSpells()) {
        int option;
        string strOption;
        do {
            spellShop.printInOrder();
            cout << "Enter a number: ";
            cin >> strOption;
            if(!isValidNumber(strOption)) {
                cout << "Not a valid number, try again.\n";
            }
        } while(!isValidNumber(strOption));
        option = stoi(strOption);
        Spell *pSpell = spellShop.buyByNumber(option), spellCopy;
        if(!pSpell)
            cout << "Not an existent spell\n";
        else {
            spellCopy = *pSpell;
            if(!spellShop.deleteSpell(spellCopy))
                return 0;
            if(player1.checkForDuplicateSpells(spellCopy))
                cout << "You already have that spell\n\n";
            else {
                if(player1.addSpell(spellCopy)) {
                    count++;
                    cout << "Added " << spellCopy << "\n\n";
                }
            }
        }
    }
    spellShop.deleteShop(); //Borrar la tienda despues de cargar los hechizos
    Monster *pMonster = dungeon.getDeadMonster(1), copyMonster;
    if(!pMonster)
        return 0;
    copyMonster = *pMonster;
    player1.addMonster(copyMonster);
    cout << "Mostrando informacion del jugador: \n";
    player1.showInfo();

    return 0;
}

bool isValidNumber(const string &str) {
    for(int i = 0; i < str.length(); i++) {
        if(!isdigit(str[i]))
            return false;
    }
    return true;
}