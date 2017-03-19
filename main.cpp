#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void Swimming()
{
    cout<<endl<<endl<<"##################################################################";
    int x = rand()%101+1;
    int choice;
    if(x<31)
    {
        cout<<"    Lad na horyzoncie!"<<endl
            <<"    Kapitanie co zamierzasz?"<<endl<<endl
            <<"    1.Schodzimy na wyspe! Kamraci! Arghhhh...(Rabowanie)"<<endl
            <<"    2.Odwrot taktyczny! Arghhhh...(Ucieczka)"<<endl<<endl;
        cin>>choice;
        if(x<11)
        {

        }
    }
    else if(x<36)
    {

    }
    else if(x<51)
    {

    }
    cout<<endl<<endl;
}

class CrewMember
{
private:
    int hp;
    int attack;
    int defense;
    string name;
    // Domyœlny za³ogant kosztuje 160 zlota
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
            <<"    2.W szeregu zbiorka krzywonogie niedolegi! Arghhhh...(wglad w zaloge)"
            <<"    2.Powiekszy flote! Arghhhh...(Nowy statek)"<<endl
            <<"    3.Wincyj mord do wykarmienia! Arghhhh...(Zatrudnij)"<<endl
            <<"    4.Najwyzszy czas zatopic moja szable w czyjejs krwi! Arghhhh...(Atak na wroga)"<<endl


            <<"    7.Trzeba zalatac lajbe! Arghhhh...(Ulepszanie)"<<endl
            <<"    8.Za burte szczuru ladowy? Arghhhh...(Koniec)"<<endl
            <<"------------------------------------------------------------------"<<endl;
        cout<<"Co zamierzasz zrobic?: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        default:
            cout<<"Twoj wybor nie pasuje do podanych";
        }
        cout<<endl<<endl<<endl<<endl<<endl;
    }
    while(choice != 8);
}

int main()
{
    string PlayerName;
    string ShipName;
    srand(time(NULL));
    cout<<"##################################################################"<<endl
        <<"Budzisz sie rano przy kolejnej butelce rumu"<<endl
        <<"Postanawiasz wypic kolejny lyk skoro swit"<<endl
        <<"Butelka jest pusta T_T"<<endl
        <<"Rozbijasz skarbonke"<<endl
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
