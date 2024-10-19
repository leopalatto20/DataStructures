#pragma once
#include <iostream>
using namespace std;

class Monster {
private:
    string name;
    double cr;
    string type;
    string size;
    int ac;
    int hp;
    string align;
public:
    Monster();
    Monster(string name, double cr, string type, string size, int ac, int hp, string align);
    ~Monster();
    bool operator < (Monster& monster);
    bool operator > (Monster& monster);
    bool operator == (Monster& monster);
    bool operator <= (Monster& monster);
    int getAc();
    string getName();

    friend ostream &operator << (ostream &os, Monster &monster);
};