#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"
#include "Enemy.h"
#include <vector>

class Player//klasa gracza
{
private:
    string name;
    int whichship;
    int level;
    int experience;
    int money;
    float rum;
    int numbercrew;
    int haveship;
    int maxship;
    int satisfaction;
public:
    vector<Ship> ships;
    ///konstruktor prosty przypisuje imie gracza, zloto poczatkowe, wartosc rumu, ilosc zalogi, ktorym statkiem plynie, level, maksymalna ilosc statkow jakie gracz moze posiadac, doswiadczenie i zadowolenie zalogi
    Player(string name_)
        : Player(name_, 1000, 10.0, 0, 0, 1, 1, 0, 75)
    {

    }
    ///konstruktor zwykly dodatkowo laczy z klasa statku i przydziela wartosc zmiennej haveship na ilosc posiadanych statkow
    Player(string name_, int money_, float rum_, int numbercrew_, int whichship_, int level_, int maxship_, int experience_, int satisfaction_)
    {
        name = name_;
        money = money_;
        rum = rum_;
        numbercrew = numbercrew_;
        ships = vector<Ship>();
        whichship = whichship_;
        level = level_;
        maxship = maxship_;
        experience = experience_;
        satisfaction = satisfaction_;
        haveship = ships.size();
    }
    ///scenariusz poczatkowy tworzenie podstawowych atrybutow gracza i pierwszy okret
    void Start();
    ///menu wpisywania kodow
    void CodesMenu();
    ///kody do gry zmieniajace wartosci konkretnych atrybutow na wyzsze
    void Codes();
    ///dodaje podany statek do gracza
    void AddShip(Ship ship);
    ///usuwa wszystkie statki gracza
    void RemoveAllShips();
    ///metoda zwieksza wartosc rumu kosztem zmniejszenia wartosci zlota
    void BuyingRum();
    ///metoda zmniejsza wartosc rumu, jezeli zmniejszy rum to zwiekszy zadowolenie, w innym wypadku zmniejszy je,
    ///jezeli zadowolenie jest mniejsze niz 30 jest szansa na uruchomienie metody Mutiny()
    ///oraz losuje x, nastepnie w zaleznosci od x uruchamia metode:Island(),PiratesDetected() lub MarineDetected()
    void Swimming();
    ///metoda zwraca wszelkie informacje o atrybutach gracza i jego statkow jak i zalogi
    void Scancrew();
    ///metoda tworzy nowy statek o parametrach podanych przez uzytkownika, ale do okreslonych ograniczen
    void NewShip();
    ///metada zwiekszajaca ilosc zlota gracza
    void Treasure();
    ///metoda w zaleznosci od parametru x uruchamia metody:Treasure() lub poprzez wybor gracza:
    ///NewShip(),HireCrewMember(),Upgrade(),BuyingRum(),Plundering()
    ///jezeli ktoras z pierwszych 4 zostala wybrana to metoda Plundering() nie moze zostac uruchomiona
    void Island(int x);
    ///metoda poprzez wybor statku do wprowadzenia zmian moze uruchomic metody klasy statku: Repair() lub SetHPMax() kosztem zmniejszenia zlota gracza
    void Upgrade();
    ///metoda dodaje piratow do wybranego statku kosztem zlota gracza
    void HireCrewMember();
    ///metoda dajaca wybor na uruchomienie metody Fighting()
    void PiratesDetected();
    ///metoda tworzaca obiekt klasy Enemy i przeprowadzenie symulacji zmniejszania zycia statkow gracza i przeciwnika do momentu az jeden ze statkow
    ///osignie wartosc 0 lub nizej, jezeli statek przeciwnika spadnie do zera pierwszy to doswiadczenie, zloto gracza rosnie, umozliwia uruchomienie
    ///metody LVLUP() jak i zwieksza wartosc level piratow na statku whichship
    ///w przypadku gdy zycie statku gracza spada do 0 gracza zloto maleje
    void Fighting();
    ///metoda aktualnie nie jest aktywna i wykorzystywana
    void Boarding();
    ///metoda na zmiane koloru tekstu terminala oraz zmiana statku ktorym gracz steruje
    void Option();
    ///wzaleznosci od ilosci piratow i ich atatku na statku o numerze rownym whichship decyduje o zwiekszeniu lub zmniejszeniu wartosci szlota gracza
    void Plundering();
    bool UpgradeTransaction(int cost);
    ///metoda umozliwiajaca wybor Swimming(),ScanScrew(),SaveGame(),LoadGame(),EndGame(),CodesMenu()
    void menu();
    ///metoda wylaczaja program
    void EndGame();
    ///zapis atrybutow gracza,jego statkow i piratow w oddzielnych plikach
    void SaveGame();
    ///wczytanie atrybutow gracza,jego statkow i piratow z plikow w zaleznosci od padanego imienia gracza
    void LoadGame();
    ///metoda ktora zwraca informacje o niskiej wartosci zadowolenia
    void Mutiny();
    ///metoda zmniejsza zycie statku, jesli zycie spada do 0 i nizej, zmienia wartosc zycia statku na 1 oraz odbiera 1/3 ilosc zlota gracza
    void MarineDetected();
    ///zwraca imie gracza
    friend ostream& operator<<(std::ostream& out, const Player& p);
    ///zwraca imie gracza
    string getName()
    {
        return name;
    }
    ///zmienia imie gracza
    void setName( string name_ )
    {
        name = name_;
    }
    ///zmienia wartosc parametru whichship odpowiedzialnego za zwracanie informacje ktory statek jest zmieniany
    void setShip( int whichship_ )
    {
        whichship = whichship_;
    }
    ///zwieksza level gracza informujac uzytkownika, co 4 levele gracz zyskuje dodatkowy statek
    void LVLUP()
    {
        if(experience>=500*level*(1+level))
        {
            level++;
            if(level%4==0) maxship++;
            cout<<endl<<"            ***LEVEL UP!!!***"<<endl
                <<"            ***YOU GET "<<level<<" LEVEL!!!***"<<endl<<endl;
        }
    }
};

#endif // PLAYER_H

//koniec
