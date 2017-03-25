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
    //int satisfaction;
    //int level;
    // Domyslny pirat kosztuje 140-250 sztuk zlota
    int cost = hp+attack*3;
public:
    void consonant(string& name);//
    void vowel(string& name);//
    string NameGenerator();//
    //konstruktor domyslny
    CrewMember()
    :CrewMember(NameGenerator(),rand()%51+50,rand()%21+30)
    {

    }
    //konstruktor zwykly
    CrewMember(string name_, int hp_, int attack_)
    {
        name = name_;
        hp = hp_;
        attack = attack_;
    }
    friend ostream& operator<<(std::ostream& out, const CrewMember& c);
    string getName() { return name; }
    void setName( string name_ ) { name = name_; }
};

#endif //CREWMEMBER_H

//koniec
