#pragma once
#include <iostream>

using namespace std;

class Spell {
private:
	string name;
	int damage;
public:
	Spell();
	Spell(string name, int damage);
	friend ostream& operator << (ostream& os, Spell& spell);
};
