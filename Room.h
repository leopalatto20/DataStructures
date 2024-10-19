#pragma once
#include "Monster.h"

class Room {
public:
    Monster monster;
    Room(Monster monster);
    friend ostream &operator << (ostream &os, Room &room);;
};