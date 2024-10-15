#pragma once
#include <iostream>
#include "Spell.h"
#include "MonsterCatalogue.h"
#include "DLinkedList.h"

using namespace std;

class Player {
private:
	string name;
	string build;
	MonsterCatalogue defeatedMonsters;
	DLinkedList<Spell> playerSpells;
	bool loadSpell(Spell spell);
	const int MAX_SPELLS;
	int determineMaxSpells(const string& build);
public:
	Player(string name, string build);
	void showInfo();
	int getMaxSpells();
	bool checkForDuplicateSpells(Spell spell);
	bool addSpell(Spell spell);
};