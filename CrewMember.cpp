#include "CrewMember.h"

static int satisfaction = 50;

ostream& operator<<(std::ostream& out, const CrewMember& c)
{
    out<<"|Imie: "<<c.name<<"| |Zycie: "<<c.hp<<"| |Atak: "<<c.attack<<"|";
    return out;
}

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

/*
void CrewMember::Wspolgloska(string &name)
{
    int x=rand()%19;
    if(x==0) name+="B";
    if(x==1) name+="C";
    if(x==2) name+="D";
    if(x==3) name+="F";
    if(x==4) name+="G";
    if(x==5) name+="H";
    if(x==6) name+="J";
    if(x==7) name+="K";
    if(x==8) name+="M";
    if(x==9) name+="N";
    if(x==10) name+="P";
    if(x==11) name+="Q";
    if(x==12) name+="R";
    if(x==13) name+="S";
    if(x==14) name+="T";
    if(x==15) name+="W";
    if(x==16) name+="V";
    if(x==17) name+="X";
    if(x==18) name+="Z";
}

void CrewMember::Mspolgloska(string &name)
{
    int x=rand()%20;
    if(x==0) name="b";
    if(x==1) name="c";
    if(x==2) name="d";
    if(x==3) name="f";
    if(x==4) name="g";
    if(x==5) name="h";
    if(x==6) name="j";
    if(x==7) name="k";
    if(x==8) name="m";
    if(x==9) name="n";
    if(x==10) name="p";
    if(x==11) name="q";
    if(x==12) name="r";
    if(x==13) name="s";
    if(x==14) name="t";
    if(x==15) name="w";
    if(x==16) name="v";
    if(x==17) name="x";
    if(x==18) name="z";
    if(x==19) name="l";
}

void CrewMember::Wsamogloska(string &name)
{
    int x=rand()%6;
    if(x==0) name+="A";
    if(x==1) name+="E";
    if(x==2) name+="I";
    if(x==3) name+="O";
    if(x==4) name+="U";
    if(x==5) name+="Y";
}

void CrewMember::Msamogloska(string &name)
{
    int x=rand()%6;
    if(x==0) name="a";
    if(x==1) name="e";
    if(x==2) name="i";
    if(x==3) name="o";
    if(x==4) name="u";
    if(x==5) name="y";
}

string CrewMember::NameGenerator()
{
    string litera;
    int licznik=0;
    int x=rand()%5+4;
    if(x%2==1)
    {
        Wspolgloska(name);
        if(name=="S")
        {
            int y=rand()%3;
            if(y==0) name+="t";
            licznik++;
        }
        if(name=="P" || name=="T")
        {
            int y=rand()%3;
            if(y==0) name+="h";
            licznik++;
        }
        if(name=="C" || name=="T")
        {
            int y=rand()%3;
            if(y==0) name+="r";
            licznik++;
        }
        if(name=="C")
        {
            int y=rand()%3;
            if(y==0) name+="t";
            licznik++;
        }
        if(name=="E")
        {
            int y=rand()%3;
            if(y==0) name+="v";
            licznik++;
        }
        if(name=="C")
        {
            int y=rand()%4;
            if(y==0) name+="h";
            licznik++;
        }
        if(name=="F")
        {
            int y=rand()%3;
            if(y==0) name+="r";
            licznik++;
        }

    }
    else
    {
        Wsamogloska(name);
        Mspolgloska(litera);
        name += litera;
        licznik++;
    }
    licznik++;
    if(licznik==1) x++;
    x-=2;
    for(int i=0; i<x/2; i++)
    {
        Msamogloska(litera);
        name += litera;
        if(litera=="e")
        {
            int y=rand()%7;
            if(y==0)
            {
            name+="e";
            }
        }
        else if(litera=="o")
        {
            int y=rand()%6;
            if(y==0) name+="o";
        }
        else if(litera=="a")
        {
            int y=rand()%8;
            if(y==0) name+="o";
        }
        Mspolgloska(litera);
        name += litera;
        if(litera=="l")
        {
            int y=rand()%5;
            if(y==0) name+="l";
        }
        else if(litera=="h")
        {
            int y=rand()%9;
            if(y==0) name+="n";
        }
        else if(litera=="c")
        {
            int y=rand()%7;
            if(y==0) name+="h";
            if(y==1) name+="k";
        }
        else if(litera=="n")
        {
            int y=rand()%6;
            if(y==0) name+="n";
        }
    }
    int y=rand()%4;
    if(y==0) name+="a";
    return name;
}
*/
//koniec
