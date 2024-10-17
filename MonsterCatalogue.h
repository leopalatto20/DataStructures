#pragma once
#include "BinaryTree.h"
#include "Monster.h"
#define csv "monsters.csv"

class MonsterCatalogue {
private:
    BinaryTree<Monster> catalogue;
public:
    bool addMonster(Monster& monster);
    bool loadFromCSV();
    void displayMonsters();
    void displayMonstersInOrder();
    Monster* getMonster();
};
