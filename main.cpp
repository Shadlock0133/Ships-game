#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void Swimming()
{
    int x = rand()%101+1;


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
            <<"    1.Stworz statek"<<endl
            <<"    2.Zatrudnij zaloganta"<<endl
            <<"    3.Plyn"<<endl
            <<"    4.Walcz z wrogim statkiem"<<endl
            <<"    5.Rabuj wyspe"<<endl
            <<"    6.Ulepsz statek"<<endl
            <<"    7.Opusc Statek"<<endl
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
        default:
            cout<<"Twoj wybor nie pasuje do podanych";
        }
        cout<<endl<<endl<<endl<<endl<<endl;
    }
    while(choice != 7);
}

int main()
{
    string PlayerName;
    string ShipName;
    srand(time(NULL));
    cout<<"Budzisz sie rano przy kolejnej butelce rumu"<<endl
        <<"Postanawiasz wypic kolejny lyk skoro swit"<<endl
        <<"Butelka jest pusta T_T"<<endl
        <<"Rozbijasz skarbonke"<<endl
        <<"Bierzesz 3000 sztuk zlota i idziesz do portu"<<endl
        <<"Widzisz niesamowita oferte statku za jedyne 2000 sztuk zlota"<<endl
        <<"Sprzedawca Cie pyta o imie..."<<endl;
    getline(cin, PlayerName);
    cout<<"Podaj nazwe statku "<<PlayerName<<"..."<<endl;
    getline(cin, ShipName);
    cout<<"A wiec powodzenia glup...eee...podrozniku! :D"<<endl;
    menu();

    return 0;
}
