#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster() : name(" "), cr(0.0), type(" "), size(" "), ac(0), hp(0), align(" ") {
}

Monster::Monster(string name, double cr, string type, string size, int ac, int hp, string align) : name(name), cr(cr), type(type), size(size), ac(ac), hp(hp), align(align){
}

Monster::~Monster() {
}

bool Monster::operator < (Monster &monster) {
    return this->ac < monster.ac;
}

bool Monster::operator > (Monster &monster) {
    return this->ac > monster.ac;
}

bool Monster::operator == (Monster &monster) {
    return this->ac == monster.ac;
}

bool Monster::operator<=(Monster &monster) {
    return this->ac <= monster.ac;
}


int Monster::getAc() {
    return this->ac;
}

string Monster::getName() {
    return this->name;
}

ostream &operator <<(ostream &os, Monster &monster) {
    os << monster.name << ", " << "HP: " << monster.hp;
    return os;
}

int Monster::getHp() {
    return this->hp;
}

void Monster::setHp(int hp) {
    this->hp = hp;
}

