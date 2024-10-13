#include "Spell.h"
#include <iostream>

using namespace std;

Spell::Spell() : name(""), damage(damage) {
}

Spell::Spell(string name, int damage) : name(name), damage(damage) {
}

ostream &operator << (ostream &os, Spell &spell) {
    os << spell.name;
    return os;
}
