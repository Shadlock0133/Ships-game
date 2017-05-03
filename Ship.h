#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include "CrewMember.h"
#include "MyVector.h"

class Ship//klasa statku
{
private:
    string name;
    int hp;                             // koszt = hp*3
    int hpmax;
    int cannons;                        // koszt = 200
    int masts;                          // koszt = 300
    int countcrew;
public:
    MyVector<CrewMember> crews;
    //konstruktor prosty
    Ship(string name_)
        : Ship(name_, 500, 500, 2, 1)
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
        crews = MyVector<CrewMember>();
    }
    MyVector<CrewMember> &GetCrews()
    {
        return crews;
    };
    void AddCrewMember(CrewMember crew);
    void Repair()
    {
        hp = hpmax;    //
    }
    friend ostream& operator<<(std::ostream& out, const Ship& s);
    string getName()
    {
        return name;
    }
    void setHP(int hp_)
    {
        hp = hp_;
    }
    void setMasts(int masts_)
    {
        masts = masts_;
    }
    void setCountCrew(int countcrew_)
    {
        countcrew = countcrew_;
    }
    int getCountCrew()
    {
        return countcrew;
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
        cannons = cannons_;
    }
    void Hit(int DMG);

};

#endif // SHIP_H

//koniec
