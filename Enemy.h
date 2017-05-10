#ifndef ENEMY_H
#define ENEMY_H

#include "Ship.h"

class Enemy//klasa przeciwnika
{
private:
    int numbercrew;//
public:
    vector<Ship> ships2;
    ///konstruktor domyslny, tworzy przeciwnika z zerowa iloscia piratow
    Enemy()
        : Enemy(0)
    {

    }
    ///konstruktor zwykly laczy z klasa statkow
    Enemy(int numbercrew_)
    {
        numbercrew = numbercrew_;
        ships2 = vector<Ship>();
    }
    ///dodaje statek
    void AddShip(Ship ship);
    ///tworzy statek o okreslonych parametrach
    void CreateShip(int mas);
};

#endif // ENEMY_H

//koniec
