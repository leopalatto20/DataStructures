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
        return 1;
    }
    if(!spellShop.loadSpells()) {
        cout << "No se pudieron cargar los hechizos\n";
        return 1;
    }
    cout << endl;

    cout << "Crear dungeon...\n";
    for(int i = 0; i < ROOMS; i++) {
        Monster *pMonster = nullptr, copyMonster;

        pMonster = catalogue.getMonster();
        if(!pMonster) {
            cout << "No se pudo obtener un monstruo\n";
            return 1;
        }

        copyMonster = *pMonster;
        if(!dungeon.createRoom(copyMonster)) {
            cout << "No se pudo crear un cuarto\n";
            return 1;
        }
    }

    cout << endl;
    dungeon.printRooms();
    cout << endl;
    catalogue.deleteCatalogue(); //Borrar el catalogo despues de cargar los monstruos

    string  playerName, buildOptionStr, buildName;
    int buildOption;
    bool validOption = false;
    cout << "Ingresa el nombre de tu personaje: ";
    getline(cin,playerName);
    while(!validOption) {
        do {
            cout << "1. Fuerza: 75HP|5 Hechizos.\n"
                    "2. Destreza: 60HP|6 hechizos\n"
                    "3. Inteligencia: 45HP|10 hechizos\n"
                    "Escoge tu clase: ";
            cin >> buildOptionStr;
            if(!isValidNumber(buildOptionStr))
                cout << "No es un numero valido.\n";
        } while(!isValidNumber(buildOptionStr));
        buildOption = stoi(buildOptionStr);
        if(buildOption < 1 || buildOption > 3)
            cout << "El numero no esta dentro de las opciones.\n";
        else
            validOption = true;
    }
    switch(buildOption) {
        case 1: {
            buildName = "strength";
            break;
        }
        case 2: {
            buildName = "dexterity";
            break;
        }
        case 3: {
            buildName = "intelligence";
            break;
        }
    }

    Player player1(playerName, buildName);
    if(!player1.loadStats())
        return 1;
    cout << endl;
    int count = 0;
    while(count < player1.getMaxSpells()) { //Acabamos hasta que tengamos todos los hechizos
        cout << "Escoge tus hechizos\n";
        int option;
        string strOption;
        do {
            spellShop.printInOrder();
            cout << "Elige un hechizo: ";
            cin >> strOption;
            if(!isValidNumber(strOption)) {
                cout << "No es un numero valido, intenta de nuevo.\n";
            }
        } while(!isValidNumber(strOption));
        option = stoi(strOption);

        Spell *pSpell = spellShop.buyByNumber(option), spellCopy;
        if(!pSpell)
            cout << "Ese hechizo no existe.\n";
        else {
            spellCopy = *pSpell;
            if(!spellShop.deleteSpell(spellCopy))
                return 1;
            if(player1.checkForDuplicateSpells(spellCopy))
                cout << "Ya tienes ese hechizo.\n\n";
            else {
                if(player1.addSpell(spellCopy)) {
                    count++;
                    cout << "Agregando hechizo " << spellCopy << "\n\n";
                }
            }
        }
    }
    spellShop.deleteShop(); //Borrar la tienda despues de cargar los hechizos

    bool alivePlayer = true;
    int roomNumber = 1;
    while(alivePlayer && roomNumber <= ROOMS) {
        Monster *pMonster = dungeon.getMonsterFromNumber(roomNumber), copyMonster;
        if(!pMonster) {
            cout << "Error cargando al monstruo para pelear.\n";
            return 1;
        }
        copyMonster = *pMonster;
        if(fightMonster(player1, copyMonster)) {
            cout << "\nDerrotaste al monstruo, vas contra el siguiente.\n";
            player1.addMonster(copyMonster);
            cout << "Te curas antes de pelear contra el siguiente monstruo.\n\n";
            player1.setHp(player1.getHp() + 50);
            roomNumber++;
        }
        else {
            cout << "Perdiste contra el monstruo.\n";
            alivePlayer = false;
        }
    }
    cout << endl << endl;
    if(!alivePlayer) {
        cout << "Moriste en el cuarto " << roomNumber << "\n";
        cout << "Estas fueron tus estadisticas finales: \n";
        player1.showInfo();
        return 0;
    }
    cout << "¡Ganaste el juego, derrotaste a todos los monstruos!\n";
    cout << "Estadisticas finales: \n";
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

bool fightMonster(Player &player, Monster &monster) { //Si regresa false, el jugador murio, si regresa true gana
    cout << "Peleando contra: " << monster;
    cout << "\nEmpieza la pelea.\n";
    while(player.getHp() > 0 && monster.getHp() > 0) {
        int spellChoice, damage;
        string spellChoiceStr;
        bool validSpell = false;
        cout << "Tienes " << player.getHp() << " puntos de vida.\n";
        while(!validSpell) {
            do {
                player.showSpells();
                cout << "0. Usar hechizo default.\n\n";
                cout << "Escoge uno de tus hechizos: ";
                cin >> spellChoiceStr;
                if(!isValidNumber(spellChoiceStr))
                    cout << "No es un numero valido";
            } while(!isValidNumber(spellChoiceStr));
            spellChoice = stoi(spellChoiceStr);
            damage = player.getSpellDamage(spellChoice);
            if(damage <= 0)
                cout << "No tienes ese hechizo.\n";
            else
                validSpell = true;
        }

        cout << "\nLe haces " << damage << " de danio al monstruo.\n";
        monster.setHp(monster.getHp() - damage);

        if(monster.getHp() <= 0) {
            monster.setHp(0);
            return true;
        }
        cout << monster;
        cout << "\nAhora el monstruo te ataca y te hace 20 de danio.\n";
        player.setHp(player.getHp() - 20);
        if(player.getHp() <= 0) {
            player.setHp(0);
            return false;
        }
    }
    return player.getHp() > 0; //No es necesario pero me mandaba una advertencia cuando compilo entonces lopongo
}