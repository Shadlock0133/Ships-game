#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <vector>
#include "CrewMember.h"

using namespace std;

class Ship//klasa statku
{
private:
    string name;
    int hp;                             // koszt = hp*3
    int hpmax;
    int cannons;                        // koszt = 200
    int masts;                          // koszt = 300
    // Domyslny statek kosztuje 2000 zlota
    int cost = hpmax*3+cannons*200+masts*300;
    vector<CrewMember> crews;

public:
    //konstruktor prosty
    Ship(string name_)
    : Ship(name_,500, 500, 1, 1)
    {

    }
    //konstruktor zwykly
    Ship(string name_, int hp_, int hpmax_, int cannons_, int masts_)
    {
        name = name_;
        hp = hp_;
        hpmax = hpmax_;
        cannons = cannons_;
        masts = masts_;
        crews = vector<CrewMember>();
    }
    vector<CrewMember> &GetCrews() {return crews;};
    void Swimming();//zmniejszenie rumu co akcje
    void Plundering();//pladrowanie wyspy
    void Upgrade();//
    void Fight();
    friend ostream& operator<<(std::ostream& out, const Ship& p);
};

#endif // SHIP_H
