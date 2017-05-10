#include "CrewMember.h"

void CrewMember::vowel(string& name)//samogloska
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

void CrewMember::consonant(string& name)//spolgloska
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

string CrewMember::NameGenerator()//generowanie imion dla piratow
{
    //najpierw tworzysz zmienna lokalna zeby wygenerowac imie i potem je zwrocic a nie od razu przypisywac do pola name w obiekcie CrewMember ktory jeszcze nie istnieje!!!
    string name;
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
    return name;
}

CrewMember& CrewMember::operator++()
{
    LVLUP();
    return *this;
}

CrewMember CrewMember::operator++(int)
{
    CrewMember old = *this;
    LVLUP();
    return old;
}

void CrewMember::LVLUP()
{

    hp += rand()%3+5;
    attack += rand()%3+4;
    level++;
}

//koniec
