//Gra Jak Statki Na Niebie
//projekt #1 na laboratoria z PROI
#include "Player.h"
#include "test.h"
int main()
{
    //psie z kulawą nogą, nieokrzesane bydlaki
    //Do armat slepe oszołomy! Arghhhh...
    //Do stu tysięcy kartaczy! Arghhhh...
    //Niech to dunder swisnie! Arghhhh...
    //Zobaczymy sie w luku Dawy'ego Jones'a! Arghhhh...
    srand(time(NULL));
    testAll();
    Player player("");
    player.Start();
    player.menu();
    return 0;
}

//koniec
