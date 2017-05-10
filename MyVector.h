#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "CrewMember.h"

using namespace std;

template<typename T>
class MyVector
{
    T* store;
    int Size;
    int Capacity;
    static const int INITIAL_CAPACITY = 30;
public:
    ///Konstruktor
    MyVector(int initialcapacity = INITIAL_CAPACITY)
    :Size(0),Capacity(initialcapacity)
    {
        store = new T[initialcapacity];
    }
    ~MyVector()
    {
        delete[] store;
    }

    MyVector( const MyVector& other )
    {
        Size = other.Size;
        Capacity = other.Capacity;
        store = new T[Capacity];

        for( int i = 0; i < Size; i++ )
        {
            store[i] = other.store[i];
        }
    }

    ///dodaje kolejny element do vectora
    void Push_back(T element)
    {
        if(Size+1>Capacity)
        {
            ReallocMemory();
        }
        store[Size] = element;
        Size++;
    }
    ///usuwa wybrany element z vectora
    void Remove(int i)
    {
        for (i; i<Size+1;i++)
        {
            store[i] = store[i+1];
        }
        Size--;
    }
    ///metoda do zwiekszania pojemnosci vectora
    void ReallocMemory()
    {
        Capacity *= 2;
        T *temp = new T[Capacity];
        try{temp;}
        catch(bad_alloc &bAlloc)
        {
            cout<<"Blad lokowania pamieci"<<bAlloc.what()<<endl;
            exit(2);
        }
        for(int i=0;i<Size;i++)
        {
            temp[i] = store[i];
        }
        delete[] store;
        store = temp;
    }
    ///metoda do zamiany miejsc dwoch elementow vectora
    void Swap(int a, int b)
    {
        T temp;
        temp = store[a];
        store[a] = store[b];
        store[b] = temp;
    }
    ///operator uruchamia metode Push_back()
    T& operator+ (T element)
    {
        Push_back(element);
    }
    ///operator uruchamia metode Remove()
    T& operator- (int i)
    {
        Remove(i);
    }
    typedef T* iterator;
    iterator begin()
    {
        return &store[0];
    }
    iterator end()
    {
        return &store[Size];
    }
    ///kopiujacy operator przypisania
    MyVector& operator=(const MyVector& other)
    {
        Size = other.Size;
        Capacity = other.Capacity;
        delete [] store;
        store = new T[Capacity];

        for( int i = 0; i < Size; i++ )
        {
            store[i] = other.store[i];
        }
        return *this;
    }

    ///umozliwia operowanie konkretnym elementem w vectorze
    T& operator[](int i)
    {
        if( i >= Size ) throw out_of_range{"index out of range"};
        return store[i];
    }
    ///zwraca ilosc elementow w vectorze
    int Sizevec()
    {
        return Size;
    }
    ///usuwa wszystkie obiekty w vectorze
    void Clear()
    {
        Capacity = 30;
        Size = 0;
    }
};

template<>
void MyVector<CrewMember>::Push_back(CrewMember element);

#endif // MYVECTOR_H

/*MyVector v;
MyVector v2 = MyVector(v);
MyVector v3 = v2;*/

//koniec
