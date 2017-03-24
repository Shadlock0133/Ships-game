#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#define MAX 9999
using namespace std;

template <typename T>
T inputNewStat(string name)
{
    T choice;
    cout<<name<<": ";
    cin>>choice;
    return choice;
}

int inputNewStat(string name, int lower_limit, int upper_limit)
{
    int result;
    do
    {
        result = inputNewStat<int>(name);
    } while(result < lower_limit || result > upper_limit);
    return result;
}

class CrewMember
{
private:
    string name;
    int hp;
    int attack;
    int defense;
    // Domyslny pirat kosztuje 180-330 sztuk zlota
    int cost = hp+attack*3+defense*2;
public:
    //konstruktor domyslny
    CrewMember(string name)
    {
//        CrewMember(name,50,30,20);
    }
    //konstruktor zwykly

};

class Ship
{
private:
    string name;
    int hp;                             // koszt = hp*3
    int cannons;                         // koszt = 200
    int masts;                          // koszt = 300
    float rum;                          // koszt = 5, 1/10 rumu wypijana przez 1 zaloganta przez 1 wykonanie funkcji swimming()
    int money;
    // Domyslny statek kosztuje 2000 zlota
    int cost = hp*3+cannons*200+masts*300;
    vector<CrewMember> crew;

public:
    //konstruktor domyslny
    Ship(string name)
    {
        Ship(name, 500, 1, 1, 0.0, 1000);
    }
    //konstruktor zwykly
    Ship(string name, int hp, int cannons, int masts, float rum, int money)
    {
        name = name;
        hp = hp;
        cannons = cannons;
        masts = masts;
        rum = rum;
        money = money;
        crew = vector<CrewMember>();
    }
    void Swimming();//zmniejszenie rumu co akcje
    void NewShip();//nowy statek do floty
    void BuyingRum();//uzupelnienie zapasow rumu
    void Plundering();//pladrowanie wyspy
    void Upgrade();//
    void Fight();
};

void vowel(string &name)//samogloska
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

void consonant(string &name)//spolgloska
{
    int x;
    x = rand()%19;
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
    x = rand()%5+4;
    if(x%2==0) vowel(name);
    else x++;
    consonant(name);
    x -= 2;
    for(int i=0; i<x/2; i++)
    {
        vowel(name);
        consonant(name);
    }
}

void HireCrewMember()//zatrudnianie piratow do konkretnego okretu z losowymi statystykami
{

}

void Upgrade()//mozliwosc ulepszenia konkretnego statkua dokladnie: ilosci armat, wytrzymalosc
{

}

void BuyingRum()//kupowanie rumu
{
    system("cls");
    string answer;
    int cost = 0;
    cout<<"    *HICK* Witaaaam szanowneeego paaana!"<<endl
        <<"    *HICK* W czyyym moglbym pomoc?"<<endl
        <<"    *HICK* Chwila, chwila! Nooo tak RUM! Juz podaje!"<<endl;
    int rum2 = inputNewStat("    *HICK* Tylkoooo... Ile paaan go sobie zyczy?", 0, MAX);
    cout<<"    *HICK* Tooo bedzie...eee..."<<rum2*23+17<<" sztuk zlota, dobrze?: "<< "NIEEEE!!!!!"<<endl;

    do
    {
        cout<<"    *HICK* Znaczy... "<<rum2*5<<" lepiej(T/N)?: ";
        cin>>answer;

        if(answer=="T" || answer=="t")
        {
            cout<<"    *HICK* Na miejscu czy na wynos?: Na wynos -.-"<<endl;
            cost -= rum2*5;
            answer = "koniec";
        }
        else if(answer=="N" || answer=="n")
        {
            cout<<"    *HICK* Eh... Nie to nie! Wincyj Rumu dla mnie!"<<endl;
            answer = "koniec";
        }
        else cout<<"    *HICK* Mozesz powtorzyc?"<<endl;
    }
    while(answer!="koniec");
}

void Plundering()//pladrowanie wioski, zarobek, ale blokada do korzystania z innych opcji na zamieszkanej wyspie
{

}

void Scancrew()//wglad w ilosc okretow, zaloge na nich i ich statystyki
{

}

void NewShip()//tworzenie nowego statku
{
    system("cls");
    string answer;
    int x = rand()%4;//losowanie znizki
    cout<<x;
    cout<<"    Witaj w dokach podrozniku!";
    int masts = inputNewStat(" Z ilu masztow ma skladac sie Twoj okret?", 1, 3);
    int hp_low, hp_high, cann_low, cann_high;
    switch (masts)
    {
    case 1:
        hp_low = 500;
        hp_high = 1000;
        cann_high = 4;
        break;
    case 2:
        hp_low = 1000;
        hp_high = 5000;
        cann_high = 12;
        break;
    case 3:
        hp_low = 5000;
        hp_high = 25000;
        cann_high = 40;
        break;
    }
    int hp = inputNewStat("    Podaj jego wytrzymalosc", hp_low, hp_high);
    int cannons = inputNewStat("    No dobrze, a ile bys chcial miec na nim armat?", 1, cann_high);
    int cost = hp*3+cannons*200+masts*300;

    do
    {
        if(x!=4)
        {
            cout<<"    Teraz najmniej ciekawa rzecz... Koszt wynosi: "<<cost<<endl<<"Wyrazasz zgode(T/N)?: ";
            cin>>answer;
        }

        if(answer=="T" || answer=="t")//potwierdzenie kupna
        {
            string name = inputNewStat<string>("    Pozostalo juz tylko podac zmyslna nazwe dla Twojego nowego okretu!");
            Ship newShip = Ship(name, hp, cannons, masts, 0.0, 0);
            answer = "koniec";
        }
        else if(answer=="N" || answer=="n")//odmowa kupna
        {
            if(x==0)//dla x==0 z losowania dla odmowy istnieje znizka szansa na to 25%
            {
                cost -=  cannons*100;
                cout<<"    Ehh... Niech strace! To moze "<<cost<<"?: ";
                cin>>answer;
            }
            else
            {
                cout<<"    No coz... Moze innym razem. Zegnam."<<endl;
                answer = "koniec";
            }
            x = 4;
        }
        else cout<<"    Mozesz powtorzyc?"<<endl;
    }
    while(answer!="koniec");
}

void Treassure()//znaleziono wyspe ze skarbem
{
    int treassure = rand()%2000+1000;
    cout<<"    Kapitanie! Tam na piasku jest namalowany wielki czerwony ''X''"<<endl
        <<"            ***ZNALEZIONO STARA SKRZYNIE!***"<<endl
        <<"            ***W SKRZYNI BYLO "<<treassure<<" SZTUK ZLOTA***"<<endl;
    //dodac skarb do kasy statku
}

void Island(int x)//wyspa jest: zamieszkana, ze skabem lub pusta. Odpowiednio od wyspy mozna wykonac specjalne dla niej akcje
{
    int choice;//wybor akcji
    int choice1 = 0;//czy korzystalismy opcji kupienia statku? 0-nie, 1-tak. Mozna tylko raz kupic statek na wyspie
    cout<<"    Lad na horyzoncie!"<<endl
        <<"    Kapitanie co zamierzasz?"<<endl<<endl
        <<"        1.Schodzimy na wyspe kamraci! Arghhhh..."<<endl
        <<"        2.Odwrot taktyczny! Arghhhh..."<<endl;
    cin>>choice;

    if(x<21 && choice==1)//zamieszkana wyspa
    {
        do
        {

            cout<<"-------------------------------------------------------------------------------"<<endl
                <<"    Kapitanie! Wyspa jest zamieszkana!"<<endl
                <<"        1.Powiekszmy flote! Arghhhh...(Nowy statek)"<<endl
                <<"        2.Wincyj mord do wykarmienia! Arghhhh...(Zatrudnij)"<<endl
                <<"        3.Trzeba zalatac lajbe! Arghhhh...(Ulepszanie)"<<endl
                <<"        4.Gdzie tu sprzedaja moj rum?! Arghhhh...(Kupowanie rumu)"<<endl
                <<"        5.Pladrujcie! Gwalccie! I niczego nie zalujcie! Arghhhh...(Pladrowanie)"<<endl
                <<"        6.Wszyscy nieudacznicy zyciowi! Odplywamy! Arghhhh..."<<endl;
            cin>>choice;
            cout<<"-------------------------------------------------------------------------------"<<endl;
            switch(choice)
            {
            case 1:
                if(choice1==0) NewShip();
                else cout<<"    Wincej panu juz nie pomoge."<<endl;
                choice1 = 1;
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
                cout<<"    Zla decyzja mlokosie! Arghhhh..."<<endl;
            }
        }
        while(choice!=6 && choice!=5);
    }
    else if(x<31 && choice==1)//pusta wyspa
    {
        cout<<"    Kapitanie! Na tej wyspie nic nie ma!"<<endl;
    }
    else if(x<36 && choice==1)//wyspa ze skarbem
    {
        Treassure();
    }
}

void Swimming()
{
    //rum-=0.1*liczbazalogi
    system("cls");
    cout<<endl<<"###############################################################################"<<endl;
    int x = rand()%101+1;//losowanie od 0 do 100 akcji, odpowiednio: wyspy, wrogich piratow, marynarki, niczego
    if(x<36)//wyspa
    {
        Island(x);
    }
    else if(x<76)//wrodzy piraci
    {
        cout<<"    Kapitanie! Czarna bandera na horyzoncie!"<<endl;

    }
    else if(x<86)//marynarka
    {
        cout<<"    Kapitanie! Marynka kieruje sie w nasza strone!"<<endl
            <<"        Cala wstecz spruchniale kolki! Arghhhh..."<<endl
            <<"        Jesli wam zycie mile i jeszcze kiedys spotkac panny ujrzec chcecie to do wiosel zgnile dorsze! Arghhhh..."<<endl;
        //piraci do wiosel, zmiejsza to zadowolenie -5%
    }
    else cout<<"Wszedzie tylko woda na widoku! Arghhhh..."<<endl;//nic :|
    cout<<"###############################################################################"<<endl<<endl;
}

void menu()
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
    while(choice != 3);
}

int main()
{
    //tepe skorupiaki, zgnile dorsze, bezuzyteczne malpiszony, mlokos, tchorzliwe fladry, szczury ladowe, krzywonogie niedolegi, nieudacznicy zyciowi, spruchniałe kołki, psie z kulawą nogą, nieokrzesane bydlaki
    //Do armat slepe oszołomy! Arghhhh...
    //Do stu tysięcy kartaczy! Arghhhh...
    //Niech to dunder swisnie! Arghhhh...
    //Zobaczymy sie w schowku Dawy'ego Jones'a! Arghhhh...
    //
    string PlayerName;
    string ShipName;
    srand(time(NULL));
    cout<<"###############################################################################"<<endl
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
        <<"###############################################################################"<<endl<<endl;
    menu();

    return 0;
}
