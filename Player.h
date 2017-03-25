#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "Ship.h"

using namespace std;

class Player//klasa gracza
{
    string name;
    int money;
    float rum;// koszt = 5, 1/10 rumu wypijana przez 1 zaloganta przez 1 wykonanie funkcji swimming()
    vector<Ship> ships;
public:
    void AddShip(Ship ship);
    void BuyingRum();//uzupelnienie zapasow rumu
    void Swimming();//zmniejszenie rumu co akcje
    void Scancrew();//
    friend ostream& operator<<(std::ostream& out, const Player& p);
    string getName() { return name; }
    void setName( string name_ ) { name = name_; }
};

#endif // PLAYER_H
