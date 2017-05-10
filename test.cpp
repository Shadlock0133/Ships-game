#include "Test.h"
#include <cstdlib>
#include <windows.h>
#include <cstdio>

void test1()
{
    cout<<"TEST1!"<<endl;
    MyVector<CrewMember> v;
    for(int i=0;i<10;i++)
    {
        CrewMember c;
        v+(c);
    }
    cout<<v.Sizevec()<<endl;
    for(int i=0;i<v.Sizevec();i++)
    {
        string n = v[i].getName();
        int h = v[i].getHP(), a = v[i].getAttack(), l = v[i].getLevel();
        printf("->%3d. |Imie: %12s| |Zycie: %3d| |Atak: %3d| |Lvl: %2d|\n", i, n.c_str(), h, a, l);
    }
    cout<<endl;
    v.Swap(0,1);
    v.Remove(3);
    v-(3);
    for(int i=0;i<v.Sizevec();i++)
    {
        string n = v[i].getName();
        int h = v[i].getHP(), a = v[i].getAttack(), l = v[i].getLevel();
        printf("->%3d. |Imie: %12s| |Zycie: %3d| |Atak: %3d| |Lvl: %2d|\n", i, n.c_str(), h, a, l);
    }
    cout<<endl;
    v.Clear();
    /*try
    {
        v[8];
    }
    catch( out_of_range e )
    {
        cout << e.what() << endl;
    }*/
}
void test2()
{
    cout<<"TEST2!"<<endl;
    MyVector<CrewMember> v;
    for(int i=0;i<100000;i++)
    {
        CrewMember c;
        v.Push_back(c);
    }
    int i = 5000;
    string n = v[i].getName();
    int h = v[i].getHP(), a = v[i].getAttack(), l = v[i].getLevel();
    printf("->%5d. |Imie: %12s| |Zycie: %3d| |Atak: %3d| |Lvl: %2d|\n", i, n.c_str(), h, a, l);
    i = 50000;
    n = v[i].getName();
    h = v[i].getHP();
    a = v[i].getAttack();
    l = v[i].getLevel();
    printf("->%5d. |Imie: %12s| |Zycie: %3d| |Atak: %3d| |Lvl: %2d|\n", i, n.c_str(), h, a, l);
    i = 99999;
    n = v[i].getName();
    h = v[i].getHP();
    a = v[i].getAttack();
    l = v[i].getLevel();
    printf("->%5d. |Imie: %12s| |Zycie: %3d| |Atak: %3d| |Lvl: %2d|\n", i, n.c_str(), h, a, l);
    v[i].LVLUP();
    n = v[i].getName();
    h = v[i].getHP();
    a = v[i].getAttack();
    l = v[i].getLevel();
    printf("->%5d. |Imie: %12s| |Zycie: %3d| |Atak: %3d| |Lvl: %2d|\n", i, n.c_str(), h, a, l);
}
