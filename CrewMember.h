#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class CrewMember//klasa pirata
{
private:
    string name;
    int hp;
    int attack;
    int level;
    int cost;//Domyslny pirat kosztuje 160-250 sztuk zlota
public:
    ///losuje spolgloske
    void consonant(string& name);
    ///losuje samogloske
    void vowel(string& name);
    ///Generuje imiona piratom
    ///
    ///Sluzy do tworzenia losowych nazw
    ///piratow na statku
    ///@return nazwa
    string NameGenerator();
    ///Konstruktor domyslny, przypisuje imie z generatora, losowe zycie i atak, przypisuje 1. poziom
    CrewMember()
        :CrewMember(NameGenerator(), rand()%31+70, rand()%21+30, 1)
    {

    }
    ///Konstruktor zwykly dodatkawo wprowadza koszt pirata
    CrewMember(string name_, int hp_, int attack_, int level_)
    {
        name = name_;
        hp = hp_;
        attack = attack_;
        level = level_;
        cost = getAttack()*3+getHP();
    }
    ///
    CrewMember& operator++();
    ///
    CrewMember operator++(int);
    ///Pirat awansuje na kolejny poziom, zwieksza sie jego zycie i atak
    void LVLUP();
    ///zwraca imie pirata
    string getName()
    {
        return name;
    }
    ///zmienia imie pirata
    void setName( string name_ )
    {
        name = name_;
    }
    ///zwraca level pirata
    int getLevel()
    {
        return level;
    }
    ///zwraca atak pirata
    int getAttack()
    {
        return attack;
    }
    ///zwraca zycie pirata
    int getHP()
    {
        return hp;
    }
    ///zwraca koszt pirata
    int getCost()
    {
        return cost;
    }
};

#endif //CREWMEMBER_H

//koniec
