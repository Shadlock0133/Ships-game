#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

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
    cout<<endl<<endl;
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
    float rum;                     // koszt = 5, 1/10 rumu wypijana przez 1 zaloganta przez 1 wykonanie funkcji swimming()
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
            <<"    2.W szeregu zbiorka krzywonogie niedolegi! Arghhhh...(Wglad w zaloge)"<<endl
            <<"    3.Za burte szczuru ladowy? Arghhhh...(Koniec)"<<endl
            <<"    Co zamierzasz zrobic Kapitanie?: ";
        cin>>choice;
        cout<<"------------------------------------------------------------------"<<endl;
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
