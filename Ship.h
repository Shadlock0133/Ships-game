#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include "CrewMember.h"

class Ship//klasa statku
{
private:
    string name;
    int hp;                             // koszt = hp*3
    int hpmax;
    int cannons;                        // koszt = 200
    int masts;                          // koszt = 300
public:
    vector<CrewMember> crews;
    //konstruktor prosty
    Ship(string name_)
        : Ship(name_, 500, 500, 1, 1)
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
    vector<CrewMember> &GetCrews()
    {
        return crews;
    };
    void AddCrewMember(CrewMember crew);
    void Repair()
    {
        hp = hpmax;    //
    }
    friend ostream& operator<<(std::ostream& out, const Ship& s);
    int setHP(int hp_)
    {
        hp = hp_;
    }
    int getHP()
    {
        return hp;
    }
    int getHPMax()
    {
        return hpmax;
    }
    int getCannons()
    {
        return cannons;
    }
    int getMasts()
    {
        return masts;
    }
    void setHPMax( int hpmax_ );
    void setCannons(int cannons_)
    {
        cannons += cannons_;
    }

};

#endif // SHIP_H

//koniec
