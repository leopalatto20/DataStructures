#pragma once
#include "BinaryTree.h"
#include "Monster.h"
#define csv "monsters.csv"

class MonsterCatalogue {
private:
    BinaryTree<Monster> catalogue;
    bool isValidNumber(const string &str);
    bool isValidDecimal(const string &str);
    unsigned int treeSize;
public:
    MonsterCatalogue();
    bool addMonster(Monster &monster);
    bool loadFromCSV();
    void displayMonsters();
    void displayMonstersInOrder();
    Monster* getMonster();
    void deleteCatalogue();
};
