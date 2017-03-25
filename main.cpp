//Gra Jak Statki Na Niebie
//projekt #2 na laboratoria z PROI
#include <windows.h>
#include "Player.h"

void menu(Player& player)
{
    int choice;//wybor akcji
    do
    {
        cout<<"-------------------------------------------------------------------------------"<<endl
            <<"        1.Cala Naprzod tchorzliwe fladry! Arghhhh..."<<endl
            <<"        2.W szeregu zbiorka krzywonogie niedolegi! Arghhhh...(Wglad w zaloge)"<<endl
            <<"        3.Za burte szczurze ladowy? Arghhhh...(GAME OVER)"<<endl
            <<"    Co zamierzasz zrobic Kapitanie?: "<<endl;
        cout<<"-------------------------------------------------------------------------------"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            player.Swimming();
            break;
        case 2:
            player.Scancrew();
            break;
        case 3:
            cout<<"Zeganaj mam nadzieje ze te piekne chwile spedzone razem"<<endl<<"byly dla Ciebie tak mile jak dla mnie "<<player.getName()<<"! <3"<<endl;
            break;
        default:
            cout<<"Zla decyzja mlokosie! Arghhhh...";
        }
        cout<<endl<<endl;
    }
    while(choice != 3);
}

int main()
{
    //tepe skorupiaki, zgnile dorsze, bezuzyteczne malpiszony, mlokos, tchorzliwe fladry, szczury ladowe, krzywonogie niedolegi, nieudacznicy zyciowi, spruchniałe kołki, psie z kulawą nogą, nieokrzesane bydlaki
    //Do armat slepe oszołomy! Arghhhh...
    //Do stu tysięcy kartaczy! Arghhhh...
    //Niech to dunder swisnie! Arghhhh...
    //Zobaczymy sie w luku Dawy'ego Jones'a! Arghhhh...
    srand(time(NULL));
    Player player("");
    player.Start();
    menu(player);
    return 0;
}

//koniec
