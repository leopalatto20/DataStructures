#pragma once
#include "Monster.h"
#include "DLinkedList.h"
#include "Room.h"

class Dungeon {
private:
    DLinkedList<Room> rooms;
public:
    Dungeon();
    ~Dungeon();
    bool createRoom(Monster monster);
    void printRooms();
    Monster* getMonsterFromNumber(int roomNumber);
};
