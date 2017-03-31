#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class CrewMember//klasa pirata
{
private:
    string name;
    int hp;
    int attack;
    int level;
    int cost;//Domyslny pirat kosztuje 160-250 sztuk zlota
    static int satisfaction;
public:
    void consonant(string& name);//
    void vowel(string& name);//
    /* void Mspolgloska(string& name);
     void Wspolgloska(string& name);
     void Msamogloska(string& name);
     void Wsamogloska(string& name);*/
    string NameGenerator();//
    //konstruktor domyslny
    CrewMember()
        :CrewMember(NameGenerator(), rand()%31+70, rand()%21+30, 1)
    {

    }
    //konstruktor zwykly
    CrewMember(string name_, int hp_, int attack_, int level_)
    {
        name = name_;
        hp = hp_;
        attack = attack_;
        level = level_;
        cost = getAttack()*3+getHP();
    }
    CrewMember& operator++();
    CrewMember operator++(int);
    friend ostream& operator<<(std::ostream& out, const CrewMember& c);
    void LVLUP();
    string getName()
    {
        return name;
    }
    void setName( string name_ )
    {
        name = name_;
    }
    int getAttack()
    {
        return attack;
    }
    int getHP()
    {
        return hp;
    }
    int getCost()
    {
        return cost;
    }
    static void setSatisfaction( int satisfaction_ ) { satisfaction = satisfaction_; }
    static int getSatisfaction() { return satisfaction; }
};

#endif //CREWMEMBER_H

//koniec
