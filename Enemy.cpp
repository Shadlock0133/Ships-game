#include "Enemy.h"

void Enemy::AddShip(Ship ship)
{
    ships2.push_back(ship);
}

void Enemy::Hit(int which, int DMG)
{
    int hp_ = ships2[which-1].getHP()-DMG;
    ships2[which-1].setHP(hp_);
}

//koniec
