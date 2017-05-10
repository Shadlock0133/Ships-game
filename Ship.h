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
    ///Konstruktor prosty przypisuje imie, zycie aktualne i maksymalne, ilosc armat i ilosc masztow
    Ship(string name_)
        : Ship(name_, 500, 500, 2, 1)
    {

    }
    ///Konstruktor zwykly dodatkowo laczy z klasa piratow
    Ship(string name_, int hp_, int hpmax_, int cannons_, int masts_)
    {
        name = name_;
        hp = hp_;
        hpmax = hpmax_;
        cannons = cannons_;
        masts = masts_;
        crews = MyVector<CrewMember>();
    }

    Ship( const Ship& other )
    {
        name = other.name;
        hp = other.hp;
        hpmax = other.hpmax;
        cannons = other.cannons;
        masts = other.masts;
        crews = other.crews;
    }

    MyVector<CrewMember> &GetCrews()
    {
        return crews;
    };
    ///Dodaje pirata do statku
    void AddCrewMember(CrewMember crew);
    ///zmienia wartosc zycia aktualnego na maksymalne
    void Repair()
    {
        hp = hpmax;    //
    }
    ///wypisuje imie statku
    friend ostream& operator<<(std::ostream& out, const Ship& s);
    ///zwraca imie statku
    string getName()
    {
        return name;
    }
    ///zmienia zycie aktualne na podana
    void setHP(int hp_)
    {
        hp = hp_;
    }
    ///zmienia ilosc masztow na podana
    void setMasts(int masts_)
    {
        masts = masts_;
    }
    ///zmienia ilosc zalogi na statku na podana
    void setCountCrew(int countcrew_)
    {
        countcrew = countcrew_;
    }
    ///zwraca ilosc zalogi na statku
    int getCountCrew()
    {
        return countcrew;
    }
    ///zwraca ilosc zycia aktualnego
    int getHP()
    {
        return hp;
    }
    ///zwraca ilosc zycia maksymalnego
    int getHPMax()
    {
        return hpmax;
    }
    ///zwraca ilosc armat na statku
    int getCannons()
    {
        return cannons;
    }
    ///zwraca ilosc masztow na statku
    int getMasts()
    {
        return masts;
    }
    ///zmienia wartosc zycia maksymalnego na podana oraz zwieksza zycie aktualne o roznice podanego i maksymalnego
    void setHPMax( int hpmax_ );
    ///zmienia ilosc armat na podana
    void setCannons(int cannons_)
    {
        cannons = cannons_;
    }
    ///zmniejsza wartosc zycia aktualnego o podana
    void Hit(int DMG);

};

#endif // SHIP_H

//koniec
