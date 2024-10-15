#include "Spell.h"
#include <iostream>

using namespace std;

Spell::Spell() : name(""), damage(0) {
}

Spell::Spell(string name, int damage) : name(name), damage(damage) {
}

ostream &operator << (ostream &os, Spell &spell) {
    os << spell.name << "|" << spell.damage;
    return os;
}

bool Spell::operator == (Spell &spell) {
    return this->name == spell.name;
}