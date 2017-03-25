#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"

class Player//klasa gracza
{
    string name;
    int money;
    float rum;// koszt = 5, 1/10 rumu wypijana przez 1 zaloganta przez 1 wykonanie funkcji swimming()
    // ships.size()
    int numbercrew;// =
    vector<Ship> ships;
public:
    //konstruktor prosty
    Player(string name_)
    : Player(name_, 1000, 10.0, 1)
    {

    }
    //konstruktor zwykly
    Player(string name_, int money_, float rum_, int numbercrew_)
    {
        name = name_;
        money = money_;
        rum = rum_;
        numbercrew = numbercrew_;
        ships = vector<Ship>();
    }
    void Start();
    void AddShip(Ship ship);
    void BuyingRum();//uzupelnienie zapasow rumu
    void Swimming();//
    void Scancrew();//
    void NewShip();//
    void Treassure();//
    void Island(int x);//
    void Upgrade();//
    void Plundering();//pladrowanie wyspy
    friend ostream& operator<<(std::ostream& out, const Player& p);
    string getName() { return name; }
    void setName( string name_ ) { name = name_; }
    /*int getMoney() { return money; }
    void setMoney( int money_ ) { money = money_; }
    int getRum() { return rum; }
    void setRum( int rum_ ) { rum = rum_; }*/
};

#endif // PLAYER_H

//koniec
