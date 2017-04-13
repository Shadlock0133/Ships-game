#include <cstdio>
#include "Player.h"
#include <windows.h>
#include <fstream>

#define MAX 9999

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


void ani3()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout <<endl <<endl;
    cout <<"                              "<<endl;
    cout <<"               _  "<<endl;
    cout <<"              /\333| "<<endl;
    cout <<"             /\333/  "<<endl;
    cout <<"            /\333/   "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    cout <<"          _";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"|\333/    "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    cout <<"          /|       "<<endl;
    cout <<"         *          "<<endl;
}

void ani1()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout <<endl <<endl;
    cout <<"                                "<<endl;
    cout <<"   _          "<<endl;
    cout <<"  |\333\134          "<<endl;
    cout <<"   \134\333\134          "<<endl;
    cout <<"    \134\333\134          "<<endl;
    cout <<"     \134\333|";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    cout<< "_      "<<endl;
    cout <<"       |\134          "<<endl;
    cout <<"         *          "<<endl;
}

void ani2()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout <<endl <<endl;
    cout <<"         _       "<<endl;
    cout <<"        /\333\134      "<<endl;
    cout <<"        |\333|      "<<endl;
    cout <<"        |\333|      "<<endl;
    cout <<"        |\333|      "<<endl;
    cout <<"        \\\333/      "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    cout <<"        /|\134      "<<endl;
    cout <<"         *       "<<endl;
}

void ani4()
{
    cout <<endl;
    cout <<"                    "<<endl;
    cout <<"                    "<<endl;
    cout <<"                    "<<endl;
    cout <<"                    "<<endl;
    cout <<"                    "<<endl;
    cout <<"                    "<<endl;
    cout <<"                    "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout <<"             ______ "<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    cout <<"         *->";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout <<"<\333\333\333\333\333\333>"<<endl;
}

void zycie(int a)
{
    int m;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    if (a==1) m=2;
    else if (a==2) m=10;
    else if (a==3) m=14;
    else if (a==4) m=12;
    else if (a==5) m=4;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),m);
    gotoxy(29,1);
    for (int i=0; i<6-a; i++)
        cout <<"\333\333";
    for (int i=0; i<a-1; i++)
        cout <<"  ";
}

void animacja(int numer)
{
    int i;
    zycie(numer);
    for (i=0; i<3; i++)
    {
        gotoxy(1,2);
        if (i==0) ani1();
        else if (i==1) ani2();
        else if (i==2) ani3();
        Sleep(100-10*i);
    }
    gotoxy(1,2);
    ani4();
    zycie(numer+1);
    Sleep(60);
    if (numer==5)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        gotoxy(19,1);
        cout <<"COMPUTER <          >";
        Sleep(60);
    }
    else
        for (i=2; i>=0; i--)
        {
            gotoxy(1,2);
            if (i==0) ani1();
            else if (i==1) ani2();
            else if (i==2) ani3();
            Sleep(130);
        }
}

void Player::EndGame()
{
    system("cls");
    cout<<"    Zeganaj mam nadzieje ze te piekne chwile spedzone razem"<<endl<<"    byly dla Ciebie tak mile jak dla mnie "<<getName()<<"! <3"<<endl<<endl<<endl<<endl
        <<"    ZARTOWALEM!"<<endl
        <<"    UMRZYJ!!!"<<endl
        <<"            ***WCISNIJ ENTER BY KONTYNUOWAC***"<<endl<<"        ";
    char c = getchar();
    system("cls");
    gotoxy(19,1);
    cout <<"COMPUTER <          >";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    gotoxy(22,4);
    cout <<" _________  ___ " <<endl;
    cout <<"                      \333\333\333\333\333\333\333\333\333 |   |" <<endl;
    cout <<"                      \333       \333 |---|" <<endl;
    cout <<"                      \333       \333 |   |" <<endl;
    cout <<"                      \333_______\333 | ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout <<"*";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    cout <<" |" <<endl;
    cout <<"                      \333\333\333\333\333\333\333\333\333 | . |" <<endl;
    cout <<"                        _|\333|_   |___|" <<endl;
    for (int i=1; i<6; i++)
        animacja(i);
    gotoxy(17,13);
    cout <<"GAME OVER!"<<endl;
    Sleep (2000);
    system("cls");
}



ostream& operator<<(std::ostream& out, const Player& p)
{
    out <<p.name;
    return out;
}

template <typename T>
T inputNewStat(string text)
{
    T choice;
    cout<<"    "<<text;
    cin>>choice;
    cin.clear();
    cin.ignore( 1000, '\n' );
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

void Player::CodesMenu()
{
    char choice;
    system("cls");
    cout<<"            1.***PODAJ KOD***"<<endl
        <<"            2.***WYJSCIE***"<<endl<<"        ";
    do
    {
        cin>>choice;
        cin.clear();
        cin.ignore( 1000, '\n' );
        switch(choice)
        {
        case '1':
            Codes();
            cout<<"        ";
            break;
        case '2':
            break;
        default:
            cout<<"            ***PODAJ JESZCZE RAZ!***"<<endl<<"        ";
        }
    }
    while(choice!='2');
}

void Player::Codes()
{
    string Code;
    //#MONEY,#REPAIRALL,#RUM
    cout<<"            ***KOD: *** ";
    cin>>Code;
    cin.clear();
    cin.ignore( 1000, '\n' );
    if(Code=="#MONEY") money+=10000;
    else if(Code=="#REPAIRALL") for(int i=0; i<ships.size(); i++) ships[0].Repair();
    else if(Code=="#RUM") rum+=1000;
    else cout<<"            ***NIE MA TAKIEGO KODU***"<<endl;
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
        <<"    Jak Cie zwa mlody odkrywco..."<<endl<<"        ";
    getline(cin, Name);
    setName(Name);
    cout<<"Podaj nazwe statku, "<<getName()<<"..."<<endl<<"        ";
    getline(cin, ShipName);
    Ship ship(ShipName);
    AddShip(ship);
    CrewMember crewm;
    ships[0].AddCrewMember(crewm);
    numbercrew++;
    cout<<"    A wiec powodzenia glup...eee...podrozniku! :D"<<endl<<endl
        <<"."<<endl
        <<"."<<endl
        <<"."<<endl
        <<"    Sir! Booo...jaaa...Zawsze chcialem zostac piratem i przezywac przygody!"<<endl
        <<"        Podaj swe imie chlopcze! Arghhhh..."<<endl
        <<"    "<<ships[0].crews[0].getName()<<" Kapitanie!"<<endl
        <<"        A wiec "<<ships[0].crews[0].getName()<<", RUSZAJMY KU PRZYGODZIE!"<<endl
        <<"###############################################################################"<<endl
        <<"            ***WCISNIJ ENTER BY KONTYNUOWAC***"<<endl<<"        ";
    char c = getchar();
}

void Player::menu()
{
    system("cls");
    char choice;//wybor akcji
    string Code;
    do
    {
        cout<<"-------------------------------------------------------------------------------"<<endl
            <<"        1.Cala Naprzod tchorzliwe fladry! Arghhhh..."<<endl
            <<"        2.W szeregu zbiorka krzywonogie niedolegi! Arghhhh...(Wglad w zaloge)"<<endl
            <<"        3.  ***SAVE***"<<endl
            <<"        4.  ***LOAD***"<<endl
            <<"        5.  ***OPTIONS***"<<endl
            <<"        6.Za burte szczurze ladowy? Arghhhh...(GAME OVER)"<<endl
            //<<"        x.<szept>Csiii...Mam kody. Arghhhh...</szept>"<<endl
            <<"    Co zamierzasz zrobic Kapitanie?: "<<endl<<"        ";

        cin>>choice;
        cin.clear();
        cin.ignore( 1000, '\n' );
        cout<<"-------------------------------------------------------------------------------"<<endl;
        switch(choice)
        {
        case '1':
            Swimming();
            break;
        case '2':
            Scancrew();
            break;
        case '3':
            SaveGame();
            break;
        case '4':
            LoadGame();
            break;
        case '5':
            Option();
            break;
        case '6':
            EndGame();
            break;
        case 'x':
            CodesMenu();
            break;
        default:
            cout<<"        Zla decyzja mlokosie! Arghhhh...";
        }
        cout<<endl;
    }
    while(choice != '6');
}

void Player::Option()
{
    cout<<"            ***CO CHCESZ ROBIC?***"<<endl
        <<"            ***1.ZMIENIC KOLOR TEKSTU***"<<endl
        <<"            ***2.ZMIENIC OKRET***"<<endl<<"        ";
    char choice;
    cin>>choice;
    int nrship;
    switch(choice)
    {
    case '1':
        int colour;
        cout<<"            ***JAKI KOLOR TEKSTU BYS CHCIAL? ***"<<endl;
        for(int i=0; i<16; i++)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
            cout<<"["<<i<<"] ";
        }
        cout<<endl;
        cin>>colour;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour);
        break;
    case '2':
        cout<<"            ***KTORYM OKRETEM BEDZIESZ TERAZ DOWODZIL?***"<<endl;
        for(int i=0; i<ships.size(); i++)
        {
            cout<<"        "<<i+1<<". "<<ships[i]<<endl;
        }
        nrship = inputNewStat("",0,ships.size());
        setShip(nrship);
        break;
    default:
        cout<<"            ***ZLE WYBRANO***"<<endl;
    }
}

void Player::Treasure()//znaleziono wyspe ze skarbem
{
    int Treasure = rand()%900+100;
    cout<<"    Kapitanie! Tam na piasku jest namalowany wielki czerwony ''X''"<<endl
        <<"            *****ZNALEZIONO STARA SKRZYNIE!*****"<<endl
        <<"            ***W SKRZYNI BYLO "<<Treasure<<" SZTUK ZLOTA***"<<endl;
    money += Treasure;
}

void Player::BuyingRum()//kupowanie rumu
{
    string answer;
    cout<<endl<<"###################################### BAR #####################################"<<endl
        <<"    *HICK* Witaaaam szanowneeego paaana w barze!"<<endl
        <<"    *HICK* W czyyym moglbym pomoc?"<<endl
        <<"    *HICK* Chwila, chwila! Nooo tak RUM! Juz podaje!"<<endl;
    int rum2 = inputNewStat("    *HICK* Tylkoooo... Ile paaan go sobie zyczy?: ", 0, MAX-rum);
    cout<<"    *HICK* Tooo bedzie...eee..."<<rum2*41+17<<" sztuk zlota, dobrze?: "<< "NIEEEE!!!!!"<<endl;

    do
    {
        cout<<"    *HICK* Znaczy... "<<rum2*15<<" lepiej(T/N)?: ";
        cin>>answer;
        cin.clear();
        cin.ignore( 1000, '\n' );
        if(answer=="T" || answer=="t")
        {
            if(rum*15<=money)
            {
                cout<<"    *HICK* Na miejscu czy na wynos?: Na wynos -.-"<<endl;
                money -= rum2*15;
                rum += rum2;
            }
            else cout<<"    Wypad z baru biedoku jeden, Ty! A kysz!"<<endl<<endl;
            answer = "koniec";
        }
        else if(answer=="N" || answer=="n")
        {
            cout<<"    *HICK* Eh... Nie to nie! Wincyj Rumu dla mnie!"<<endl;
            answer = "koniec";
        }
        else cout<<"    *HICK* Mozesz powtorzyc?"<<endl<<"        ";
    }
    while(answer!="koniec");
    cout<<"################################################################################"<<endl;
}

void Player::NewShip()//tworzenie nowego statku
{
    string answer;
    int x = rand()%4;//losowanie znizki
    cout<<endl<<"################################### DOKI ######################################"<<endl;
    if(x==0) cout<<"            ***JEST ZNIZKA!!!***"<<endl;
    cout<<"    Witaj w dokach podrozniku!"<<endl;
    int masts = inputNewStat(" Z ilu masztow ma skladac sie Twoj okret?: ", 1, 3);
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
    int hpmax = inputNewStat("    Podaj jego wytrzymalosc: ", hp_low, hp_high);
    int hp = hpmax;
    int cannons = inputNewStat("    No dobrze, a ile bys chcial miec na nim armat?: ", 1, cann_high);
    CrewMember crewm;
    cout<<"    Potrzebujesz jeszcze ciesli do statku, ale spokojna glowa mamy tu jednego!"<<endl
        <<"    "<<crewm.getName()<<"! Zostaniesz ciesla na tym okrecie."<<endl
        <<"    Tak jest! To dla mnie zaszczyt poznac pana, Kapitanie!"<<endl;
    int cost = hpmax*3 + cannons*200 + masts*300 + crewm.getCost();
    do
    {
        if(x!=4)
        {
            cout<<"    Teraz najmniej ciekawa rzecz... Koszt wynosi: "<<cost<<endl<<"    Wyrazasz zgode(T/N)?: ";
            cin>>answer;
            cin.clear();
            cin.ignore( 1000, '\n' );
        }
        if(answer=="T" || answer=="t")//potwierdzenie kupna
        {
            if(cost<=money)
            {
                string name = inputNewStat<string>("Pozostalo juz tylko podac zmyslna nazwe dla Twojego nowego okretu!: ");
                Ship newShip = Ship(name, hp, hpmax, cannons, masts);
                money -= cost;
                AddShip(newShip);
                int nrship = ships.size()-1;
                ships[nrship].AddCrewMember(crewm);
                numbercrew++;
            }
            else cout<<"    Wypad z baru biedoku jeden, Ty! A kysz!"<<endl<<endl;
            answer = "koniec";
        }
        else if(answer=="N" || answer=="n")//odmowa kupna
        {
            if(x==0)//dla x==0 z losowania dla odmowy istnieje znizka szansa na to 25%
            {
                cost -=  cannons*100;
                cout<<"    Ehh... Niech strace! To moze "<<cost<<"(T/N)?: ";
                cin>>answer;
                cin.clear();
                cin.ignore( 1000, '\n' );
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
    cout<<"###############################################################################"<<endl;
}

void Player::Island(int x)//wyspa jest: zamieszkana, ze skabem lub pusta. Odpowiednio od wyspy mozna wykonac specjalne dla niej akcje
{
    int a = 0;//nie mozna okrasc wioski na ktorej sie rozmawialo z tubylcami
    char choice1,choice2;//wybor akcji
    int used = 0;//czy korzystalismy opcji kupienia statku? 0-nie, 1-tak. Mozna tylko raz kupic statek na wyspie
    cout<<"    Lad na horyzoncie!"<<endl
        <<"    Kapitanie co zamierzasz?"<<endl
        <<"        1.Schodzimy na wyspe kamraci! Arghhhh..."<<endl
        <<"        2.Odwrot taktyczny bezuzyteczne malpiszony! Arghhhh..."<<endl<<"        ";
    do
    {
        cin>>choice1;
        cin.clear();
        cin.ignore( 1000, '\n' );
        if(x<21 && choice1=='1')//zamieszkana wyspa
        {
            cout<<"-------------------------------------------------------------------------------"<<endl
                <<"    Kapitanie! Wyspa jest zamieszkana!"<<endl;
            cout<<"        1.Powiekszmy flote! Arghhhh...(Nowy statek)"<<endl
                <<"        2.Wincyj mord do wykarmienia! Arghhhh...(Zatrudnij)"<<endl
                <<"        3.Trzeba zalatac lajbe! Arghhhh...(Ulepszanie)"<<endl
                <<"        4.Gdzie tu sprzedaja moj rum?! Arghhhh...(Kupowanie rumu)"<<endl
                <<"        5.Wszyscy nieudacznicy zyciowi! Odplywamy! Arghhhh..."<<endl
                <<"        6.Pladrujcie! Gwalccie! Rabujcie! I niczego nie zalujcie!"<<endl<<"          Arghhhh...(Pladrowanie)"<<endl<<"        ";
            do
            {
                cin>>choice2;
                cin.clear();
                cin.ignore( 1000, '\n' );
                switch(choice2)
                {
                case '1':
                    if(used==0) NewShip();
                    else cout<<"    Wincej panu juz nie moge pomoc."<<endl;
                    used = 1;
                    break;
                case '2':
                    HireCrewMember();
                    break;
                case '3':
                    Upgrade();
                    break;
                case '4':
                    BuyingRum();
                    break;
                case '5':
                    break;
                case '6':
                    if(a!=1) Plundering();
                    else cout<<"    Kapitanieee...chcesz okrasc wioske, z ktorej uslug korzystales? Brzydko :("<<endl;
                    break;
                default:
                    cout<<"    Kapitanie?"<<endl;
                }
                if((choice2!='6' || a!=0) && choice2!='5') cout<<"    Co dalej Kapitanie?"<<endl<<"        ";
                if(choice2!='6' && choice2!='5') a = 1;
            }
            while((choice2!='6' || a==1) && choice2!='5');
            cout<<"-------------------------------------------------------------------------------"<<endl<<endl;
        }
        else if(x<31 && choice1=='1')//pusta wyspa
        {
            cout<<"    Kapitanie! Na tej wyspie nic nie ma!"<<endl;
        }
        else if(x<36 && choice1=='1')//wyspa ze skarbem
        {
            Treasure();
        }
        else if(choice1!='1' && choice1!='2') cout<<"    Mozesz powtorzyc Kapitanie?"<<endl<<"        ";

    }
    while(choice1!='2' && choice1!='1');
}

void Player::Boarding()
{
    for(int i=0; i<ships[whichship].crews.size(); i++)
    {

    }
}

void Player::statek(Enemy enemy)
{
    int exp, mas;//ilosc masztow statku gracza
    mas = ships[whichship].getMasts();
    int hpmax_, hp_, cannons_, masts_ = mas, y = rand()%5;
    if(y==0 && mas>1) mas -= rand()%2;
    switch(mas)
    {
    case 1:
        hpmax_ = rand()%6*100+500;
        cannons_ += rand()%4+1;
        break;
    case 2:
        hpmax_ += rand()%21*200+1000;
        cannons_ += rand()%10+3;
        break;
    case 3:
        hpmax_ +=rand()%41*500+5000;
        cannons_ += rand()%31+10;
        break;
    }
    hp_ = hpmax_;
    Ship ship_("", hp_, hpmax_, cannons_, masts_);
    enemy.AddShip(ship_);
    for(int i=0; i<cannons_-rand()%6-2; i++)
    {
        CrewMember crewm;
        ship_.AddCrewMember(crewm);
    }
}

void Player::Fighting()
{
    Enemy enemy;
    statek(enemy);
    cout<<"DZIALAM"<<endl;
    cout<<"        BOCIANIE GNIAZDO?! JAK SYTUACJA?!"<<endl
        <<"    Maja "<<enemy.ships2[1].getMasts()<<endl;

    char choice;
    bool hit = 0, part1 = 1, part2 = 1, part3 = 1, part4 = 1;
    int DMG = 0,y,x,numbercannons = ships[whichship].getCannons();//y- atak od jednej armaty
    float attackratio = 1.0;
    cout<<"    Kapitanie rozkazuj!"<<endl
        <<"        1. OSTRZAL W DZIOB! Arghhhh...(1.5xDMG)"<<endl
        <<"        2. OSTRZAL W BURTE! Arghhhh...(Umozliwia 5.)"<<endl
        <<"        3. OSTRZAL W RUFE! Arghhhh...(Oslabia celnosc)"<<endl
        <<"        4. OSTRZAL W MASZT! Arghhhh...(Anulowanie ucieczki wroga)"<<endl
        <<"        5. ABORDAZ! Arghhhh...(Okradanie i zniszczenie od wew.)"<<endl
        <<"        6. NEGOCJUJEMY! Arghhhh..."<<endl
        <<"        7. ODWROT TAKTYCZNY! Arghhhh..."<<endl;
    while(choice!='7')
    {
        x = rand()%20;
        y = rand()%21+40;
        cout<<"        ";
        cin>>choice;
        cin.clear();
        cin.ignore( 1000, '\n' );
        switch(choice)
        {
        case '1':
            if(x<11)
            {
                part1 = 0;
                hit = 1;
            }
            else cout<<"            ***MISSED***"<<endl;
            break;
        case '2':
            if(x<14)
            {
                part2 = 0;
                hit = 1;
            }
            else cout<<"            ***MISSED***"<<endl;
            break;
        case '3':
            if(x<15)
            {
                part3 = 0;
                hit = 1;
            }
            else cout<<"            ***MISSED***"<<endl;
            break;
        case '4':
            if(x<15)
            {
                part4 = 0;
                hit = 1;
            }
            else cout<<"            ***MISSED***"<<endl;
            break;
        case '5':
            if(x<6 && part2==0)
            {
                Boarding();
            }
            else cout<<"    Nie powiodlo sie!"<<endl;
            break;
        case '6':
            cout<<"        It's a prank, bro! Piraci nie negocjuja! Arghhhh..."<<endl;
            break;
        case '7':
            if(x<11)
            {
                choice = '6';
                cout<<"    Nie powiodlo sie!"<<endl;
            }
            else cout<<"    Kapitanie ucieczka sie udala :)"<<endl;
            break;
        default:
            cout<<"    Co takiego?!"<<endl;
        }
        DMG = numbercannons*y*attackratio;
        if(hit==1) enemy.Hit(DMG);
        if(enemy.ships2[0].getHP()>0) cout<<"ENEMY: ["<<enemy.ships2[0].getHP()<<"/"<<enemy.ships2[0].getHPMax()<<"]"<<endl;
        else if(enemy.ships2[0].getHP()<=0)
        {
            int gold = rand()%201;
            choice = '7';
            cout<<"    STATEK ZOSTAL ZNISZCZONY KAPITANIE!"<<endl
                <<"            ***UDALO CI SIE WYLOWIC CZESC SKARBOW WROGA***"<<endl
                <<"            ***ZDOBYWASZ "<<gold<<" SZTUK ZLOTA"<<endl;
            for(int i=0; i<ships.size(); i++)
                for(int j=0; j<ships[i].crews.size(); j++)
                    ships[i].crews[j]++;
            money += gold;
        }

        //reset tury
        DMG = 0;
        hit = 0;
        if(part1==0) attackratio = 1.5;
    }
}

void Player::PiratesDetected()
{
    char choice1;
    cout<<"    Kapitanie! Czarna bandera na horyzoncie!"<<endl
        <<"    Co robimy?"<<endl
        <<"        1.TO CHYBA OCZYWISTE! BANDERA NA MASZT! WYTOCZYC DZIALA!"<<endl<<"          ZAGLE W DOL! I CALA NAPRZOD!"<<endl
        <<"        2.chyba uciekniemy :'("<<endl;
    cin>>choice1;
    cin.clear();
    cin.ignore( 1000, '\n' );
    switch(choice1)
    {
    case '1':
        Fighting();
        break;
    case '2':
        break;
    default:
        cout<<"    Kapitanie?!"<<endl<<"        ";
    }
}

void Player::Swimming()
{
    rum-=0.1*numbercrew;
    system("cls");
    cout<<endl<<"###############################################################################"<<endl;
    int x = rand()%101+1;//losowanie od 0 do 100 akcji, odpowiednio: wyspy, wrogich piratow, marynarki, niczego
    if(x<36)//wyspa
    {
        Island(x);
    }
    else if(x<76)//wrodzy piraci
    {
        PiratesDetected();
    }
    else if(x<86)//marynarka
    {
        cout<<"    Kapitanie! Marynka kieruje sie w nasza strone!"<<endl
            <<"        Cala wstecz spruchniale kolki! Arghhhh..."<<endl
            <<"        Jesli wam zycie mile i jeszcze kiedys panny ujrzec chcecie"<<endl
            <<"        to do wiosel zgnile dorsze! Arghhhh..."<<endl;
        //piraci do wiosel, zmiejsza to zadowolenie -5%(jeszcze nie wprowadzono)
    }
    else cout<<"    Wszedzie tylko woda na widoku! Arghhhh..."<<endl;//nic :|
    cout<<"###############################################################################"<<endl<<endl;
}

bool Player::UpgradeTransaction(int cost)
{
    string answer;
    cout<<"    To bedzie "<<cost<<" sztuk zlota."<<endl
        <<"    Zgoda?(T/N): ";
    do
    {
        cin>>answer;
        cin.clear();
        cin.ignore( 1000, '\n' );
        if(answer=="T" || answer=="t")
        {
            if(cost<money)
            {
                money -= cost;
                cout<<"    Gotowe!"<<endl;
                return 1;
            }
            else
            {
                cout<<"    Wypad z baru biedoku jeden, Ty! A kysz!"<<endl<<endl;
                return 0;
            }
        }
        else if(answer=="N" || answer=="n")
        {
            cout<<"    Mowi sie trudno, zegnam."<<endl;
            return 0;
        }
        else cout<<"    To jak?"<<endl<<"        ";
    }
    while(true);

}

void Player::Upgrade()//mozliwosc ulepszenia konkretnego statkua dokladnie: naprawa, ilosci armat, wytrzymalosc
{
    char choice2;
    int choice1, cost, newcannons, newhpmax;
    cout<<endl<<"################################## WARSZTAT ###################################"<<endl
        <<"    Zapraszam, zapraszam do mego bogatego warsztatu!"<<endl;
    for(int i=0; i<ships.size(); i++)
    {
        cout<<"    "<<i+1<<". "<<ships[i]<<endl;
    }
    choice1 = inputNewStat("Ktory stateczek mam operowac?: ",1,ships.size());
    cout<<"    Zatem, co robimy?"<<endl
        <<"    1. Naprawiamy?"<<endl
        <<"    2. Wieksza Wytrzymalosc?"<<endl
        <<"    3. Moze dorzucic kilka armat?"<<endl
        <<"    4. Czy moze sie pan rozmyslil?"<<endl<<"        ";
    do
    {
        cin>>choice2;
        cin.clear();
        cin.ignore( 1000, '\n' );
        switch(choice2)
        {
        case '1':
            cost = ships[choice1-1].getHPMax()-ships[choice1-1].getHP();
            if(UpgradeTransaction(cost)==1) ships[choice1-1].Repair();
            break;
        case '2':
            cout<<"    Jaka chcemy miec wytrzymalosc?: ";
            cin>>newhpmax;
            cin.clear();
            cin.ignore( 1000, '\n' );
            if(newhpmax>ships[choice1-1].getHPMax())
            {
                cost = (newhpmax - ships[choice1-1].getHPMax())*2;
                if(UpgradeTransaction(cost)==1) ships[choice1-1].setHPMax(newhpmax);
            }
            else cout<<"    Przepraszam. Ja nie zmniejsze. :|"<<endl;
            break;
        case '3':
            cout<<"    To ile ich dodac?: ";
            cin>>newcannons;
            cin.clear();
            cin.ignore( 1000, '\n' );
            cost = newcannons*200;
            if(UpgradeTransaction(cost)==1) ships[choice1-1].setCannons(newcannons);
            break;
        case '4':
            break;
        default:
            cout<<"    Przykro nie oferuje takich uslug"<<endl;
        }
        if(choice2!='4') cout<<"    Co dalej?"<<endl<<"        ";
    }
    while(choice2!='4');
    cout<<"################################################################################"<<endl;
}

void Player::Plundering()//pladrowanie wioski, zarobek, badz strata ale blokada do korzystania z innych opcji na zamieszkanej wyspie
{
    int x = (rand()%21+50)*ships[whichship].crews.size();//obrona wioski
    int gold = (rand()%6+5)*ships[whichship].crews.size()*level;
    if(gold>money) gold = 0;
    int attackcrew = 0;// suma ataku zalogi
    for(int j=0; j<ships[whichship].crews.size(); j++)
    {
        attackcrew += ships[whichship].crews[j].getAttack();
    }
    cout<<endl<<"################################ PLADROWANIE ##################################"<<endl
        <<"            ***ATAK ZALOGI: "<<attackcrew<<" ***"<<endl
        <<"            ***OBRONA WIOSKI: "<<x<<" ***"<<endl;
    if(x<attackcrew)
    {
        cout<<"        NAPRZOD TEPE SKORUPIAKI! ICH OBRONA PADLA PRZED NASZA POTEGA!!!"<<endl<<"        Arghhhh..."<<endl
            <<"            ***WIOSKA ZOSTALA OGRABIONA Z WSZELKICH DOBR!***"<<endl
            <<"               ***UDALO CI SIE UKRASC "<<gold<<" SZTUK ZLOTA***"<<endl
            <<"        Co tak stoicie i gapicie sie spruchniale kolki! Na okret!"<<endl<<"        Odplywamy! Arghhhh..."<<endl;
        money += gold;
    }
    else
    {
        cout<<"    Wynoscie sie stad parszywi piraci!"<<endl
            <<"    Niczego juz tu poza ponizeniem nie znajdziecie!"<<endl
            <<"            ***UCIEKAJAC W POSPIECHU TRACISZ "<<gold<<" SZTUK ZLOTA***"<<endl;
        if(money==0) cout<<"    BIEDOKI JEDNE,WY!"<<endl;
        money -= gold;
    }
    cout<<"###############################################################################"<<endl;
}

void Player::Scancrew()//wglad w ilosc okretow, zaloge na nich i ich statystyki
{
    float a = numbercrew, rumConsumption = a/10;
    string answer="";
    system("cls");
    int choice;
    cout<<endl<<"################################## EKWIPUNEK ##################################"<<endl
        <<"Witaj "<<name<<"! Oto Twoja potega!: "<<endl
        <<"    Plywasz aktualnie statkiem: "<<ships[whichship].getName()<<endl
        <<"    Tyle masz sztuk zlota: "<<money<<endl
        <<"    Tyle masz rumu: "<<rum<<"(-"<<rumConsumption<<")"<<endl
        <<"    Lista "<<ships.size();
    if(ships.size()==1) cout<<" statku"<<": "<<endl;
    else cout<<" statkow "<<": "<<endl;
    for(int i=0; i<ships.size(); i++)
    {
        cout<<"        "<<i+1<<". "<<ships[i]<<endl;
    }
    cout<<"    Liczba zalogi ogolem: "<<numbercrew<<endl;
    while(answer!="N" && answer!="n")
    {
        cout<<"    Czy chcesz przejrzec statek(T/N)?: ";
        cin>>answer;
        cin.clear();
        cin.ignore( 1000, '\n' );
        if(answer=="T" || answer=="t")
        {
            choice = inputNewStat("Ktory statek?: ", 1, ships.size());
            cout<<"->Masztow: "<<ships[choice-1].getMasts()<<endl
                <<"->Wytrzmyalosc: ["<<ships[choice-1].getHP()<<"/"<<ships[choice-1].getHPMax()<<"]"<<endl
                <<"->Armat: "<<ships[choice-1].getCannons()<<endl
                <<"    Zaloga:"<<endl;
            for(int i=0; i<ships[choice-1].GetCrews().size(); i++)
            {
                cout<<"->"<<i+1<<". "<<ships[choice-1].crews[i]<<endl;
            }
        }
        else if(answer=="N" || answer=="n") ;
        else cout<<"    Mozesz powtorzyc?"<<endl;
    }
    cout<<"###############################################################################"<<endl;
}

void Player::HireCrewMember()//zatrudnianie piratow do konkretnego okretu z losowymi statystykami
{
    int newmembers;//nowi piraci
    int choice;
    string answer;
    int cost =0;
    int a = 0;//akceptacja kupna
    cout<<endl<<"################################## KOSZARY ####################################"<<endl
        <<"    Zapraszam do koszar! Mamy tu swietnych wojownikow!"<<endl
        <<"    Piraci?! Hmmm... Alez oczywiscie ze ich tez mamy!"<<endl;
    newmembers = inputNewStat("Ilu pan potrzebuje, proponuje od jednego do dziesieciu?: ",1, 10);
    cout<<"    Na ktory statek ich zaprowadzic?:"<<endl;
    for(int i=0; i<ships.size(); i++)
    {
        cout<<"    "<<i+1<<". "<<ships[i]<<endl;
    }
    cout<<"        ";
    cin>>choice;
    cin.clear();
    cin.ignore( 1000, '\n' );
    cout<<"    Jak wejda na lajbe, to sie rozliczymy."<<endl
        <<"    Bedzie to kosztowac do "<<newmembers*250<<" sztuk zlota."<<endl
        <<"    Zgadza sie pan?(T/N): ";
    do
    {
        cin>>answer;
        cin.clear();
        cin.ignore( 1000, '\n' );
        if(answer=="T" || answer=="t")
        {
            if(newmembers*250<=money)
            {
                a = 1;
                cout<<"    Zatem chodzmy zobaczyc jak sie prezentuja!"<<endl;
            }
            else cout<<"    Wypad z baru biedoku jeden, Ty! A kysz!"<<endl<<endl;
            answer = "koniec";
        }
        else if(answer=="N" || answer=="n")
        {
            cout<<"    Ehhh...No coz, to do innego razu."<<endl;
            answer = "koniec";
        }
        else cout<<"    Nie uslyszalem"<<endl<<"        ";
    }
    while(answer!="koniec");
    for(int i=0; i<newmembers; i++)
    {
        CrewMember crewm;
        cost += crewm.getCost();
        ships[choice-1].AddCrewMember(crewm);
        numbercrew++;
    }
    cout<<"    A wiec wyszlo "<<cost<<". Zycze milego dnia."<<endl
        <<"###############################################################################"<<endl;
}

void Player::SaveGame()
{
    /* char AppDataFolder[ MAX_PATH ];
     SHGetFolderPathA( 0, CSIDL_APPDATA, 0, SHGFP_TYPE_DEFAULT, AppDataFolder );
     cin.get();
     string core;
     core = string( AppDataFolder ) + string( "\\SLOTS\\SAVES\\" ) + getName() + "\\" + getName() + ".txt";
     cout << core;
     system(( "explorer" + core ).c_str() );*/ //do wczytu




    string fileplayer;
    string path = "mkdir %APPDATA%\\SLOTS\\Saves\\"+getName();
    system(path.c_str());


    fileplayer = "%APPDATA%\\SLOTS\\Saves\\"+getName()+"\\"+getName()+".txt";
    ofstream file;
    file.open(fileplayer.c_str());
    cout<<fileplayer;
    file<<experience<<endl<<level<<endl<<money<<endl<<rum<<endl<<numbercrew<<endl;
    file.close();

    for(int i=0; i<ships.size(); i++)
    {
        //<<ships[0].crews[0].getSatisfaction()<<endl
        string fileship;
        fileship = "%APPDATA%\\SLOTS\\Saves\\Oj_Jeszcze_Nie_Tu\\Coraz_Blizej\\Jeszcze_Kilka_Folderow\\No_Ale_Nie_Poddawaj_sie\\Prosze_Juz_Ostatnie\\Dobra_Przestane\\Ostatni_raz\\Znaczy_Tamto_To_byl_Przedprzedostatni\\Dont_Worry_It_is_a_prank\\"+getName()+"\\"+ships[i].getName()+".txt";
        file.open(fileship.c_str());
        file<<ships[i].getHP()<<endl<<ships[i].getHPMax()<<endl<<ships[i].getCannons()<<endl<<ships[i].getMasts()<<endl<<endl;
        for(int j=0; j<ships[i].crews.size(); j++)
        {
            file<<ships[i].crews[j].getName()<<endl<<ships[i].crews[j].getHP()<<endl<<ships[i].crews[j].getAttack()<<endl<<ships[i].crews[j].getLevel()<<endl<<ships[i].crews[j].getCost()<<endl<<endl;
        }
        file.close();
    }
}

void Player::LoadGame()
{
    string fileplayer, player;
    cout<<"            ***PODAJ IMIE GRACZA DO WCZYTANIA: *** ";
    cin>>fileplayer;
    player = fileplayer;
    fileplayer = "%APPDATA%\\SLOTS\\Saves\\"+fileplayer+"\\"+fileplayer+".txt";
    cout<<fileplayer;
    fstream file;
    file.open(fileplayer.c_str());
    if(file.is_open())
    {
        setName(player);
        string experience_, level_, rum_, money_, numbercrew_;
        file.open(fileplayer.c_str());
        getline(file, experience_);
        getline(file, level_);
        getline(file, money_);
        getline(file, rum_);
        getline(file, numbercrew_);
        cout<<"money: "<<money_.c_str()<<endl;
        /*experience = experience_;
        level = level_;
        money = money_;
        rum = rum_;
        numbercrew = numbercrew_;*/
        file.close();
    }
    else cout<<"            ***NIE UDALO SIE OTWORZYC SAVE***"<<endl;
}

//koniec
