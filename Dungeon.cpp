#include "Dungeon.h"
#include <iostream>

Dungeon::Dungeon() {
}

bool Dungeon::createRoom(Monster monster) {
    Room newRoom(monster);
    if(!rooms.insertData(newRoom))
        return false;
    return true;
}

void Dungeon::printRooms() {
    rooms.printList();
}