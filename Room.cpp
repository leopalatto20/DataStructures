#include "Room.h"

Room::Room(Monster monster) : monster(monster) {
}

Room::~Room() {
}

ostream &operator<<(ostream &os, Room &room) {
    os << "Room with: " << room.monster;
    return os;
}