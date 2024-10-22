#include "Dungeon.h"

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

Monster* Dungeon::getMonsterFromNumber(int roomNumber) {
    Room *room = rooms.returnFromNumber(roomNumber);
    if(!room) {
        return nullptr;
    }
    return &room->monster;
}