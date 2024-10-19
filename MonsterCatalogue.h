#pragma once
#include "BinaryTree.h"
#include "Monster.h"
#define csv "monsters.csv"

class MonsterCatalogue {
private:
    BinaryTree<Monster> catalogue;
    bool isValidNumber(const string &str);
    bool isValidDecimal(const string &str);
public:
    bool addMonster(Monster &monster);
    bool loadFromCSV();
    void displayMonsters();
    void displayMonstersInOrder();
    Monster* getMonster();
};
