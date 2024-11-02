#pragma once
#include "MonsterCatalogue.h"
#include "Dungeon.h"
#include "Player.h"
#include "SpellShop.h"

bool isValidNumber(const string &str);
bool fightMonster(Player &player, Monster &monster);
void levelPlayerUp(Player &player);