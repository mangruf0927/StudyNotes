#include "HashTable.h"
#include <iostream>

HashTable::HashTable(int initSize)
{
    if(initSize <= 0) initSize = 1;

    size = initSize;
    hash = new SinglyLinkedListT<HashData>[size];
}

HashTable::~HashTable()
{
    delete [] hash;
}

int HashTable::Hash(int key)
{
    return key % size;
}

void HashTable::Add(int key, int value)
{
    int idx = Hash(key);
    hash[idx].Add({key, value});
}

void HashTable::Remove(int key, int value)
{
    int idx = Hash(key);
    hash[idx].Remove({key, value});
}

bool HashTable::Find(int key, int value)
{
    int idx = Hash(key);

    if(hash[idx].Find({key, value}) != -1) return true;
    else return false;
}

void HashTable::Show() const
{
    using namespace std;

    for(int i = 0; i < size; i++)
    {
        cout << "[" << i << "] : ";
        hash[i].Show();
    }
}

void HashTable::Clear() const
{
    for(int i = 0; i < size; i++)
    {
        hash[i].Clear();
    }
}