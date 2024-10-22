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
	Spell defaultAttack;
	int maxSpells;
	int hp;
	int mp;
public:
	Player(string name, string build);
	void showInfo();
	int getMaxSpells();
	bool checkForDuplicateSpells(Spell spell);
	bool addSpell(Spell &spell);
	bool loadStats();
	bool addMonster(Monster &monster);
	int useSpell(int spellNum);
};