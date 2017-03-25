#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <iostream>

using namespace std;

class CrewMember//klasa pirata
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
 //       CrewMember(name,50,30,20);
    }
    //konstruktor zwykly


};

#endif //CREWMEMBER_H
