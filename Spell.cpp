#include "Spell.h"
#include <iostream>

using namespace std;

Spell::Spell() : name(""), damage(0), mpCost(0) {
}

Spell::Spell(string name, int damage, int mpCost) : name(name), damage(damage), mpCost(mpCost) {
}

ostream &operator << (ostream &os, Spell &spell) {
    os << spell.name << "|" << spell.damage;
    return os;
}

bool Spell::operator == (Spell &spell) {
    return this->name == spell.name;
}

bool Spell::operator!=(Spell &spell) {
    return this->name != spell.name;
}

int Spell::getMpCost() {
    return this->mpCost;
}

int Spell::getDamage() {
    return this->damage;
}
