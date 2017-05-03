#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"
#include "Enemy.h"

class Player//klasa gracza
{
private:
    string name;
    int whichship;
    int level;
    int experience;
    int money;
    float rum;// koszt = 5, 1/10 rumu wypijana przez 1 zaloganta przez 1 wykonanie funkcji swimming()
    int numbercrew;
    int haveship;
    int maxship;
    int satisfaction;
public:
    vector<Ship> ships;
    //konstruktor prosty
    Player(string name_)
        : Player(name_, 1000, 10.0, 0, 0, 1, 1, 0, 75)
    {

    }
    //konstruktor zwykly
    Player(string name_, int money_, float rum_, int numbercrew_, int whichship_, int level_, int maxship_, int experience_, int satisfaction_)
    {
        name = name_;
        money = money_;
        rum = rum_;
        numbercrew = numbercrew_;
        ships = vector<Ship>();
        whichship = whichship_;
        level = level_;
        maxship = maxship_;
        experience = experience_;
        satisfaction = satisfaction_;
        haveship = ships.size();
    }
    void Start();
    void CodesMenu();
    void Codes();
    void AddShip(Ship ship);
    void RemoveAllShips();
    void BuyingRum();//uzupelnienie zapasow rumu
    void Swimming();//
    void Scancrew();//
    void NewShip();//
    void Treasure();//
    void Island(int x);//
    void Upgrade();//
    void HireCrewMember();
    void PiratesDetected();
    void Fighting();//
    void Boarding();
    void Option();
    void Plundering();//pladrowanie wyspy
    bool UpgradeTransaction(int cost);
    void menu();//
    void EndGame();
    void SaveGame();
    void LoadGame();
    void Mutiny();
    void MarineDetected();
    friend ostream& operator<<(std::ostream& out, const Player& p);
    string getName()
    {
        return name;
    }
    void setName( string name_ )
    {
        name = name_;
    }
    void setShip( int whichship_ )
    {
        whichship = whichship_;
    }
    void LVLUP()
    {
        if(experience>=500*level*(1+level))
        {
            level++;
            if(level%4==0) maxship++;
            cout<<endl<<"            ***LEVEL UP!!!***"<<endl
                <<"            ***YOU GET "<<level<<" LEVEL!!!***"<<endl<<endl;
        }
    }
};

#endif // PLAYER_H

//koniec
