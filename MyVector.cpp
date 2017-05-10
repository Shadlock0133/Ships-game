#include "MyVector.h"
#include "CrewMember.h"

template<>
void MyVector<CrewMember>::Push_back(CrewMember element)
{
    if (element.getHP()<5)
    {
        cout<<"Za malo zycia"<<endl;
        return;
    }
    if(Size+1>Capacity)
        ReallocMemory();
    store[Size] = element;
    Size++;
}

//koniec
