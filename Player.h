#pragma once
#include <iostream>
#include "Spell.h"
#include "MonsterCatalogue.h"
#include "DLinkedList.h"
#define DEXTERITY_SPELLS "dexterity.csv"
#define STRENGTH_SPELLS "strength.csv"
#define SPELLS 4

using namespace std;

class Player {
private:
	string name;
	string build;
	MonsterCatalogue defeatedMonsters;
	DLinkedList<Spell> playerSpells;
	bool loadSpells(string filename);
public:
	Player(string name, string build);
	bool loadBuild();
	void showInfo();
};