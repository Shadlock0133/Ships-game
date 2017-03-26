#include "Player.h"
#define MAX 99999

void Player::CodesMenu()
{
    int choice;
    cout<<"            1.***PODAJ KOD***"<<endl
        <<"            2.***WYJSCIE***"<<endl<<"        ";
    do
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
            Codes();
            cout<<"        ";
            break;
        case 2:
            break;
        default:
            cout<<"            ***PODAJ JESZCZE RAZ!***"<<endl<<"        ";
        }
    }
    while(choice!=2);
}

void Player::Codes()
{
    string code;
    //#MONEY,#REPAIRALL,#RUM
    cout<<"            ***KOD:*** ";
    cin>>code;
    if(code=="#MONEY") money+=10000;
    else if(code=="#REPAIRALL") for(int i=0; i<ships.size(); i++) ships[0].Repair();
    else if(code=="#RUM") rum+=1000;
    else cout<<"            ***NIE MA TAKIEGO KODU***"<<endl;
}

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
        <<"###############################################################################"<<endl<<endl;
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
    string answer;
    cout<<"    *HICK* Witaaaam szanowneeego paaana w barze!"<<endl
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
            if(rum*5<money)
            {
                cout<<"    *HICK* Na miejscu czy na wynos?: Na wynos -.-"<<endl;
                money -= rum2*5;
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
}

void Player::NewShip()//tworzenie nowego statku
{
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
        }
        if(answer=="T" || answer=="t")//potwierdzenie kupna
        {
            if(cost<money)
            {
                string name = inputNewStat<string>("    Pozostalo juz tylko podac zmyslna nazwe dla Twojego nowego okretu!");
                Ship newShip = Ship(name, hp, hpmax, cannons, masts);
                money -= cost;
                AddShip(newShip);
                newShip.AddCrewMember(crewm);
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
    int a = 0;//nie mozna okrasc wioski na ktorej sie rozmawialo z tubylcami
    int choice1,choice2;//wybor akcji
    int used = 0;//czy korzystalismy opcji kupienia statku? 0-nie, 1-tak. Mozna tylko raz kupic statek na wyspie
    cout<<"    Lad na horyzoncie!"<<endl
        <<"    Kapitanie co zamierzasz?"<<endl
        <<"        1.Schodzimy na wyspe kamraci! Arghhhh..."<<endl
        <<"        2.Odwrot taktyczny bezuzyteczne malpiszony! Arghhhh..."<<endl<<"        ";
    do
    {
        cin>>choice1;

        if(x<21 && choice1==1)//zamieszkana wyspa
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
                switch(choice2)
                {
                case 1:
                    if(used==0) NewShip();
                    else cout<<"    Wincej panu juz nie moge pomoc."<<endl;
                    used = 1;
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
                    break;
                case 6:
                    if(a!=1) Plundering();
                    else cout<<"    Kapitanieee...chcesz okrasc wioske, z ktorej uslug korzystales? Brzydko :("<<endl;
                    break;
                default:
                    cout<<"    Kapitanie?"<<endl;
                }
                if((choice2!=6 || a!=0) && choice2!=5) cout<<"    Co dalej Kapitanie?"<<endl<<"        ";
                if(choice2!=6 && choice2!=5) a = 1;
            }
            while((choice2!=6 || a==1) && choice2!=5);
            cout<<"-------------------------------------------------------------------------------"<<endl<<endl;
        }
        else if(x<31 && choice1==1)//pusta wyspa
        {
            cout<<"    Kapitanie! Na tej wyspie nic nie ma!"<<endl;
        }
        else if(x<36 && choice1==1)//wyspa ze skarbem
        {
            Treassure();
        }
        else if(choice1!=1 && choice1!=2) cout<<"    Mozesz powtorzyc Kapitanie?"<<endl<<"        ";

    }
    while(choice1!=2 && choice1!=1);
}

void Player::Fighting()
{
    int choice1;
    int x;
    Enemy enemy;
    for(int i=0;i<ships.size()+rand()%2;i++)
    {
        int hp_, hpmax_, cannons_, masts_;
        Ship ship_("", hp_, hpmax_, cannons_, masts_);
        enemy.AddShip(ship_);

    }
    cout<<"    Kapitanie! Czarna bandera na horyzoncie!"<<endl
        <<"    Co robimy?"<<endl
        <<"        1.TO CHYBA OCZYWISTE! BANDERA NA MASZT! WYTOCZYC DZIALA!"<<endl<<"          ZAGLE W DOL! I CALA NAPRZOD!"<<endl
        <<"        2.chyba uciekniemy :'("<<endl;
    cin>>choice1;
    switch(choice1)
    {
    case 1:
        cout<<"        BOSMANIE?! JAK SYTUACJA?!"<<endl
            <<"    ";
        break;
    case 2:
        break;
    default:
        cout<<"        CO?! DAWAJ POWTORZ!"<<endl<<"        ";
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
        Fighting();
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
    int choice1,choice2;
    int cost;
    int newcannons;
    int newhpmax;
    cout<<"    Zapraszam, zapraszam do mego bogatego warsztatu!"<<endl
        <<"    Ktory stateczek mam operowac? :)"<<endl;
    for(int i=0; i<ships.size(); i++)
    {
        cout<<"    "<<i+1<<". "<<ships[i]<<endl;
    }
    cout<<"        ";
    cin>>choice1;
    cout<<"    Zatem, co robimy?"<<endl
        <<"    1. Naprawiamy?"<<endl
        <<"    2. Wieksza Wytrzymalosc?"<<endl
        <<"    3. Moze dorzucic kilka armat?"<<endl
        <<"    4. Czy moze sie pan rozmyslil?"<<endl<<"        ";

    do
    {
        cin>>choice2;
        switch(choice2)
        {
        case 1:
            cost = ships[choice1-1].getHPMax()-ships[choice1-1].getHP();
            if(UpgradeTransaction(cost)==1) ships[choice1-1].Repair();
            break;
        case 2:
            cout<<"    Jaka chcemy miec wytrzymalosc?: ";
            cin>>newhpmax;
            if(newhpmax>ships[choice1-1].getHPMax())
            {
                cost = (newhpmax - ships[choice1-1].getHPMax())*2;
                if(UpgradeTransaction(cost)==1) ships[choice1-1].setHPMax(newhpmax);
            }
            else cout<<"    Przepraszam. Ja nie zmniejsze. :|"<<endl;
            break;
        case 3:
            cout<<"    To ile ich dodac?: ";
            cin>>newcannons;
            cost = newcannons*200;
            if(UpgradeTransaction(cost)==1) ships[choice1-1].setCannons(newcannons);
            break;
        case 4:
            break;
        default:
            cout<<"    Przykro nie oferuje takich uslug"<<endl;
        }
        cout<<"    Co dalej?"<<endl<<"        ";
    }
    while(choice2!=4);
    cout<<endl;
}

void Player::Plundering()//pladrowanie wioski, zarobek, badz strata ale blokada do korzystania z innych opcji na zamieszkanej wyspie
{
    int x = (rand()%20+30)*numbercrew;//obrona wioski
    int gold = rand()%201+100;
    if(gold>money) gold = 0;
    int attackcrew = 0;// suma ataku zalogi
    for(int i=0; i<ships.size(); i++)
    {
        for(int j=0; j<ships[i].crews.size(); j++)
        {
            attackcrew += ships[i].crews[j].getAttack();
        }
    }
    cout<<"            ***ATAK ZALOGI: "<<attackcrew<<" ***"<<endl;
    cout<<"            ***OBRONA WIOSKI: "<<x<<" ***"<<endl;
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
            <<"            ***UCIEKAJAC W POSPIECHU TRACISZ "<<gold/2<<" SZTUK ZLOTA***"<<endl;
        money -= gold/2;
    }
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
    while(answer!="N" && answer!="n")
    {
        cout<<"    Czy chcesz przejrzec statek?(T/N): ";
        cin>>answer;
        if(answer=="T" || answer=="t")
        {
            cout<<"    Ktory statek?: ";
            cin>>choice;
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
    int newmembers = 0;//nowi piraci
    int choice;
    string answer;
    int cost =0;
    int a = 0;//akceptacja kupna
    cout<<"    Zapraszam do koszar! Mamy tu swietnych wojownikow!"<<endl
        <<"    Piraci?! Hmmm... Alez oczywiscie ze ich tez mamy!"<<endl
        <<"    Ilu pan potrzebuje?: ";
    cin>>newmembers;
    cout<<"    Na ktory statek ich zaprowadzic?:"<<endl;
    for(int i=0; i<ships.size(); i++)
    {
        cout<<"    "<<i+1<<". "<<ships[i]<<endl;
    }
    cout<<"        ";
    cin>>choice;
    cout<<"    Jak wejda na lajbe, to sie rozliczymy."<<endl
        <<"    Bedzie to kosztowac do "<<newmembers*250<<" sztuk zlota."<<endl
        <<"    Zgadza sie pan?(T/N): ";
    do
    {
        cin>>answer;
        if(answer=="T" || answer=="t")
        {
            if(newmembers*250<money)
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
    cout<<"    A wiec wyszlo "<<cost<<". Zycze milego dnia."<<endl;
}

//koniec
