#ifndef ENEMY_H
#define ENEMY_H

#include "Ship.h"

class Enemy//klasa przeciwnika
{
private:
    string name;
    int numbercrew;//
public:
    vector<Ship> ships2;
    //konstruktor domyslny
    Enemy()
        : Enemy("", 0)
    {

    }
    //konstruktor zwykly
    Enemy(string name_, int numbercrew_)
    {
        CrewMember crewm;
        name_ = crewm.getName();
        name = name_;
        numbercrew = numbercrew_;
        ships2 = vector<Ship>();
    }

    void AddShip(Ship ship);
    void Hit(int DMG);
};

#endif // ENEMY_H

//koniec
