#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

using namespace std;

template<typename T>
class MyVector
{
    T* store;
    int Size;
    int Capacity;
    static const int INITIAL_CAPACITY = 30;
public:
    MyVector(int initialcapacity = INITIAL_CAPACITY)
    :Size(0),Capacity(initialcapacity)
    {
        store = new T[initialcapacity];
    }
    void Push_back(T element)
    {
        if(++Size>Capacity)
            MallocMemory();
        store[Size] = element;
    }
    void MallocMemory()
    {
        Capacity *= 2;
        T *temp = new T[Capacity];
        for(int i=0;i<Capacity;i++)
        {
            temp[i] = store[i];
        }
        delete[] store;
        store = temp;
    }
    T& operator[](int i)
    {
        return store[i];
    }
    int Sizevec()
    {
        return Size;
    }
    void Clear()
    {
        delete[] store;
        Capacity = 30;
        Size = 0;
    }
    void Pop_back()
    {

    }
};

#endif // MYVECTOR_H

//koniec
