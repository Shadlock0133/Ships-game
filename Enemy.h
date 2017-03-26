#ifndef ENEMY_H
#define ENEMY_H

#include "Ship.h"

class Enemy//klasa przeciwnika
{
private:
    string name;
    int numbercrew;//
    vector<Ship> ships;
public:
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
        ships = vector<Ship>();
    }
    void AddShip(Ship ship);
};

#endif // ENEMY_H

//koniec
