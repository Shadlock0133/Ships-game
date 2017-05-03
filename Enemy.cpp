#include "Enemy.h"

void Enemy::AddShip(Ship ship_)
{
    ships2.push_back(ship_);
}

void Enemy::CreateShip(int mas)
{
    int hpmax_, hp_, cannons_, masts_ = mas, y = rand()%5;
    if(y==0 && mas>1) mas -= rand()%2;
    switch(mas)
    {
    case 1:
        hpmax_ = rand()%6*100+500;
        cannons_ = 2;
        break;
    case 2:
        hpmax_ = rand()%21*200+1000;
        cannons_ = 4;
        break;
    case 3:
        hpmax_ = rand()%41*500+5000;
        cannons_ = 6;
        break;
    }
    hp_ = hpmax_;
    Ship ship_("", hp_, hpmax_, cannons_, masts_);
    AddShip(ship_);
    for(int i=0; i<cannons_-rand()%6-2; i++)
    {
        CrewMember crewm;
        ship_.AddCrewMember(crewm);
    }
}

//koniec
