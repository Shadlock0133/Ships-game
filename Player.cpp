#include "Player.h"
#define MAX 99999

template <typename T>
T inputNewStat(string text)
{
    T choice;
    cout<<text<<": ";
    cin>>choice;
    return choice;
}

int inputNewStat(string text, int lower_limit, int upper_limit)
{
    int result;
    do
    {
        result = inputNewStat<int>(text);
    }
    while(result < lower_limit || result > upper_limit);
    return result;
}

void Player::AddShip(Ship ship)
{
    ships.push_back(ship);
}

ostream& operator<<(std::ostream& out, const Player& p)
{
    out <<p.name;
    return out;
}

void Player::Start()
{
    string ShipName,Name;
    cout<<"###############################################################################"<<endl
        <<"Budzisz sie rano przy kolejnej butelce rumu"<<endl
        <<"Postanawiasz wypic kolejny lyk skoro swit"<<endl
        <<"Butelka jest pusta T_T"<<endl
        <<"Rozbijasz butelke o skarbonke"<<endl
        <<"Bierzesz 3000 sztuk zlota i idziesz do portu"<<endl
        <<"Widzisz niesamowita oferte statku za jedyne 2000 sztuk zlota"<<endl
        <<"    Jak Cie zwa mlody odkrywco..."<<endl;
    getline(cin, Name);
    setName(Name);
    cout<<"Podaj nazwe statku, "<<getName()<<"..."<<endl;
    getline(cin, ShipName);
    Ship ship(ShipName);
    AddShip(ship);
    CrewMember crewm;
    ships[0].AddCrewMember(crewm);
    cout<<"    A wiec powodzenia glup...eee...podrozniku! :D"<<endl
        <<".   .   .   .   ."<<endl
        <<"    Sir! Booo...jaaa...Zawsze chcialem zostac piratem i przezywac przygody!"<<endl
        <<"        Podaj swe imie chlopcze! Arghhhh..."<<endl
        <<"    "<<ships[0].crews[0].getName()<<""<<endl
        <<"###############################################################################"<<endl<<endl;
}

void Player::Scancrew()//wglad w ilosc okretow, zaloge na nich i ich statystyki
{
    float a = numbercrew, rumConsumption = a/10;
    cout<<"###############################################################################"<<endl
        <<"Witaj "<<name<<"! Oto Twoja potega!: "<<endl
        <<"    Tyle masz sztuk zlota: "<<money<<endl
        <<"    Tyle masz rumu: "<<rum<<"(-"<<rumConsumption<<")"<<endl
        <<"    Lista "<<ships.size();
    if(ships.size()==1) cout<<" statku "<<": "<<endl;
    else cout<<" statkow "<<": "<<endl;
    string answer="";
    int choice;
    for(int i=0; i<ships.size(); i++)
    {
        cout<<"        "<<i+1<<". "<<ships[i]<<endl;
    }
    cout<<"    Liczba zalogi ogolem: "<<numbercrew<<endl;
    while(answer=="N" || answer=="n")
    {
        cout<<"    Czy chcesz przejrzec zaloge(T/N)?: "<<endl;
        cin>>answer;
        if(answer=="T" || answer=="t")
        {
            cout<<"    Ktorego statku?"<<endl;
            cin>>choice;
            for(int i=0; i<ships[choice-1].GetCrews().size(); i++)
            {
                cout<<"        "<<i+1<<". "<<ships[choice-1].crews[i]<<endl;
            }
        }
        else if(answer=="N" || answer=="n") ;
        else cout<<"    Mozesz powtorzyc?"<<endl;
    }
    cout<<"###############################################################################"<<endl;
}

void Player::Treassure()//znaleziono wyspe ze skarbem
{
    int treassure = rand()%900+100;
    cout<<"    Kapitanie! Tam na piasku jest namalowany wielki czerwony ''X''"<<endl
        <<"            *****ZNALEZIONO STARA SKRZYNIE!*****"<<endl
        <<"            ***W SKRZYNI BYLO "<<treassure<<" SZTUK ZLOTA***"<<endl;
    money += treassure;
}

void Player::BuyingRum()//kupowanie rumu
{
    system("cls");
    string answer;
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
            money -= rum2*5;
            rum += rum2;
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

void Player::NewShip()//tworzenie nowego statku
{
    system("cls");
    string answer;
    int x = rand()%4;//losowanie znizki
    if(x==0) cout<<"JEST ZNIZKA!!!"<<endl;
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
    int hpmax = inputNewStat("    Podaj jego wytrzymalosc", hp_low, hp_high);
    int hp = hpmax;
    int cannons = inputNewStat("    No dobrze, a ile bys chcial miec na nim armat?", 1, cann_high);
    int cost = hpmax*3+cannons*200+masts*300;

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
            Ship newShip = Ship(name, hp, hpmax, cannons, masts);
            money -= cost;
            AddShip(newShip);
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

void Player::Island(int x)//wyspa jest: zamieszkana, ze skabem lub pusta. Odpowiednio od wyspy mozna wykonac specjalne dla niej akcje
{
    int choice;//wybor akcji
    int choice1 = 0;//czy korzystalismy opcji kupienia statku? 0-nie, 1-tak. Mozna tylko raz kupic statek na wyspie
    cout<<"    Lad na horyzoncie!"<<endl
        <<"    Kapitanie co zamierzasz?"<<endl<<endl
        <<"        1.Schodzimy na wyspe kamraci! Arghhhh..."<<endl
        <<"        2.Odwrot taktyczny bezuzyteczne malpiszony! Arghhhh..."<<endl;
    cin>>choice;

    if(x<21 && choice==1)//zamieszkana wyspa
    {
        cout<<"-------------------------------------------------------------------------------"<<endl
            <<"    Kapitanie! Wyspa jest zamieszkana!"<<endl
            <<"        1.Powiekszmy flote! Arghhhh...(Nowy statek)"<<endl
            <<"        2.Wincyj mord do wykarmienia! Arghhhh...(Zatrudnij)"<<endl
            <<"        3.Trzeba zalatac lajbe! Arghhhh...(Ulepszanie)"<<endl
            <<"        4.Gdzie tu sprzedaja moj rum?! Arghhhh...(Kupowanie rumu)"<<endl
            <<"        5.Pladrujcie! Gwalccie! Rabujcie! I niczego nie zalujcie!"<<endl<<"          Arghhhh...(Pladrowanie)"<<endl
            <<"        6.Wszyscy nieudacznicy zyciowi! Odplywamy! Arghhhh..."<<endl;
        cin>>choice;
        do
        {
            switch(choice)
            {
            case 1:
                if(choice1==0) NewShip();
                else cout<<"    Wincej panu juz nie pomoge."<<endl;
                choice1 = 1;
                break;
            case 2:
                //HireCrewMember();
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
            cout<<"-------------------------------------------------------------------------------"<<endl;
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

void Player::Swimming()
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
            <<"        Jesli wam zycie mile i jeszcze kiedys spotkac panny ujrzec chcecie"<<endl
            <<"        to do wiosel zgnile dorsze! Arghhhh..."<<endl;
        //piraci do wiosel, zmiejsza to zadowolenie -5%
    }
    else cout<<"    Wszedzie tylko woda na widoku! Arghhhh..."<<endl;//nic :|
    cout<<"###############################################################################"<<endl<<endl;
}

void Player::Upgrade()//mozliwosc ulepszenia konkretnego statkua dokladnie: ilosci armat, wytrzymalosc
{
    int choice;
    cout<<"###############################################################################"<<endl
        <<"    Zapraszam, zapraszam do mego bogatego warsztatu!"<<endl
        <<"    W czym moge pomoc?"<<endl
        <<"    1. W naprawie zniszczen?"<<endl
        <<"    2. W poprawieniu jakosci?"<<endl
        <<"    3. Moze dorzucic kilka armat?"<<endl;
    switch(choice)
    {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    default:
        cout<<"    Przykro nie oferuje takich uslug"<<endl;
    }
    cout<<"###############################################################################"<<endl;
}

void Player::Plundering()//pladrowanie wioski, zarobek, ale blokada do korzystania z innych opcji na zamieszkanej wyspie
{

}
//koniec
