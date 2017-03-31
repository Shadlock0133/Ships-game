
#include "test.h"
#include "Player.h"

void testAll()
{
    test1();
    test2();
    test3();
}

void test1()
{
    Ship s1("Nebula", 600, 600, 3, 1);
    Ship s2("Omega", 500, 500, 4, 1);
    Player p("Adam");
    p.AddShip(s1);
    p.AddShip(s2);
    CrewMember c1, c2, c3, c4;
    cout<<"c3: "<<c3<<endl;
    p.ships[0].AddCrewMember(c1);
    p.ships[0].AddCrewMember(c2);
    p.ships[0].AddCrewMember(c3);
    p.ships[1].AddCrewMember(c4);
    cout<<"c3: "<<p.ships[0].crews[2]<<endl;
}

void test2()
{
    Player p("Adam");
    Ship s1("Nebula", 600, 800, 3, 1);
    p.AddShip(s1);
    cout<<"brak hp wynosi: "<<p.ships[0].getHPMax()-p.ships[0].getHP()<<endl;
    p.ships[0].Repair();
    cout<<"brak hp wynosi: "<<p.ships[0].getHPMax()-p.ships[0].getHP()<<endl;
}

void test3()
{
    Player p("Adam");
    Ship s1("Nebula");
    p.AddShip(s1);
    CrewMember c1;
    p.ships[0].AddCrewMember(c1);
    cout<<"Zadowolenie: "<<p.ships[0].crews[0].getSatisfaction()<<endl;
    CrewMember::setSatisfaction(60);
    cout<<"Zadowolenie: "<<c1.getSatisfaction()<<endl;
}

//koniec
