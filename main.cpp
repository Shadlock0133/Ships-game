#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void vowel(string &name)//samog³oska
{
    int x;
    x=rand()%6;
    if(x==0) name+="a";
    else if(x==1) name+="e";
    else if(x==2) name+="i";
    else if(x==3) name+="o";
    else if(x==4) name+="u";
    else if(x==5) name+="y";
}

void consonant(string &name)//spó³g³oska
{
    int x;
    x=rand()%19;
    if(x==0) name+="b";
    else if(x==1) name+="c";
    else if(x==2) name+="d";
    else if(x==3) name+="f";
    else if(x==4) name+="g";
    else if(x==5) name+="h";
    else if(x==6) name+="j";
    else if(x==7) name+="k";
    else if(x==8) name+="l";
    else if(x==9) name+="m";
    else if(x==10) name+="n";
    else if(x==11) name+="p";
    else if(x==12) name+="q";
    else if(x==13) name+="r";
    else if(x==14) name+="s";
    else if(x==15) name+="t";
    else if(x==16) name+="v";
    else if(x==17) name+="x";
    else if(x==18) name+="z";
}

void NameGenerator(string &name)
{
    int x;
    x = rand()%4+5;
    if(x%2==0) vowel(name);
    else x++;
    consonant(name);
    x-=2;
    for(int i=0; i<x/2; i++)
    {
        vowel(name);
        consonant(name);
    }
}

void NewShip()
{

}

void HireCrewMember()
{

}

void Upgrade()
{

}

void BuyingRum()
{

}

void Plundering()
{

}

void Island()
{

}

void Scancrew()
{

}

void Swimming()
{
    //rum-=0.1*liczbazalogi
    cout<<endl<<"##################################################################"<<endl;
    int x = rand()%101+1;
    int choice;
    if(x<31)
    {
        cout<<"    Lad na horyzoncie!"<<endl
            <<"    Kapitanie co zamierzasz?"<<endl<<endl
            <<"    1.Schodzimy na wyspe kamraci! Arghhhh..."<<endl
            <<"    2.Odwrot taktyczny! Arghhhh..."<<endl;
        cin>>choice;
        cout<<"##################################################################"<<endl<<endl;
        if(x<11 && choice==1)
        {
            do
            {

                cout<<"------------------------------------------------------------------"<<endl
                    <<"    Kapitanie! Wyspa jest zamieszkana!"
                    <<"    1.Powiekszy flote! Arghhhh...(Nowy statek)"<<endl
                    <<"    2.Wincyj mord do wykarmienia! Arghhhh...(Zatrudnij)"<<endl
                    <<"    3.Trzeba zalatac lajbe! Arghhhh...(Ulepszanie)"<<endl
                    <<"    4.Gdzie tu sprzedaja moj rum?! Arghhhh...(Kupowanie rumu)"<<endl
                    <<"    5.Pladrujcie! Gwalccie! I niczego nie zalujcie! Arghhhh...(Pladrowanie)"<<endl
                    <<"    6.Wszyscy nieudacznicy zyciowi! Oplywamy! Arghhhh..."<<endl;
                cin>>choice;
                cout<<"------------------------------------------------------------------"<<endl;
                switch(choice)
                {
                case 1:
                    NewShip();
                    break;
                case 2:
                    HireCrewMember();
                    break;
                case 3:
                    Upgrade();
                    break;
                case 4:
                    BuyingRum();
                    break;
                case 5:
                    Plundering();
                    break;
                case 6:
                    break;
                default:
                    cout<<"Zla decyzja mlokosie! Arghhhh...";
                }
            }
            while(choice!=6 && choice!=5);
        }
    }
    else if(x<36)
    {

    }
    else if(x<51)
    {

    }
    else cout<<"Wszêdzie tylko woda na widoku! Arghhhh..."<<endl;
    cout<<endl;
}

class CrewMember
{
private:
    int hp;
    int attack;
    int defense;
    string name;
    // Domyœlny za³ogant kosztuje 90-210 sztuk zlota
    int cost = hp+attack*3+defense*2;
public:
    CrewMember(string name)
    {
        hp = 50;
        attack = 20;
        defense = 15;
        name = name;
    }

};

class Ship
{
private:
    string name;
    int hp;                             // koszt = hp*3
    int cannons;                        // koszt = 200
    int masts;                          // koszt = 300
    float rum;                          // koszt = 5, 1/10 rumu wypijana przez 1 zaloganta przez 1 wykonanie funkcji swimming()
    int money;
    // Domyœlny statek kosztuje 2000 zlota
    int cost = hp*3+cannons*200+masts*300;
    vector<CrewMember> crew;
public:
    Ship(string name)
    {
        hp = 500;
        cannons = 1;
        masts = 1;
        money = 1000;
        crew = vector<CrewMember>();
    }
    void Swimming();
    void Fight();
    void BuyingRum();
    void Plundering();
    void Upgrade();
};

void menu()
{
    int choice;
    do
    {
        cout<<"------------------------------------------------------------------"<<endl
            <<"    1.Cala Naprzod tchorzliwe fladry! Arghhhh..."<<endl
            <<"    2.W szeregu zbiorka krzywonogie niedolegi! Arghhhh...(Wglad w zaloge)"<<endl
            <<"    3.Za burte szczuru ladowy? Arghhhh...(Koniec)"<<endl
            <<"    Co zamierzasz zrobic Kapitanie?: ";
        cin>>choice;
        cout<<"------------------------------------------------------------------"<<endl;
        switch(choice)
        {
        case 1:
            Swimming();
            break;
        case 2:
            Scancrew();
            break;
        case 3:
            break;
        default:
            cout<<"Zla decyzja mlokosie! Arghhhh...";
        }
        cout<<endl<<endl;
    }
    while(choice != 8);
}

int main()
{
    int Survival=0;
    string PlayerName;
    string ShipName;
    srand(time(NULL));
    cout<<"##################################################################"<<endl
        <<"Budzisz sie rano przy kolejnej butelce rumu"<<endl
        <<"Postanawiasz wypic kolejny lyk skoro swit"<<endl
        <<"Butelka jest pusta T_T"<<endl
        <<"Rozbijasz butelke o skarbonke"<<endl
        <<"Bierzesz 3000 sztuk zlota i idziesz do portu"<<endl
        <<"Widzisz niesamowita oferte statku za jedyne 2000 sztuk zlota"<<endl
        <<"Sprzedawca Cie pyta o imie..."<<endl;
    getline(cin, PlayerName);
    cout<<"Podaj nazwe statku "<<PlayerName<<"..."<<endl;
    getline(cin, ShipName);
    cout<<"A wiec powodzenia glup...eee...podrozniku! :D"<<endl
        <<"##################################################################"<<endl<<endl;
    menu();
    return 0;
}
