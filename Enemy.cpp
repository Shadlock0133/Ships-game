#include "Enemy.h"

void Enemy::AddShip(Ship ship_)
{
    ships2.push_back(ship_);
}

void Enemy::Hit(int DMG)
{
    int hp_ = ships2[0].getHP()-DMG;
    ships2[0].setHP(hp_);
}

//koniec
