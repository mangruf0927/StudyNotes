#include "HashTable.h"
#include <iostream>

HashTable::HashTable(int initSize)
{
    if(initSize <= 0) initSize = 1;

    nums = 0;
    size = initSize;
    hash = new SinglyLinkedListT<HashData>[size];
}

HashTable::~HashTable()
{
    delete [] hash;
}

int HashTable::Hash(int key) const
{
    return key % size;
}

double HashTable::LoadFactor() const
{
    return (double)nums / size;
}

void HashTable::Resize(int newSize)
{
    SinglyLinkedListT<HashData> * newHash = new SinglyLinkedListT<HashData>[newSize];

    for(int i = 0; i < size; i++)
    {
        Node<HashData> * cur = hash[i].GetList();
        while(cur != nullptr)
        {
            int newIdx = cur->data.key % newSize;
            newHash[newIdx].Add({cur->data.key, cur->data.value});
            cur = cur->next;
        }
    }

    delete [] hash;
    hash = newHash;
    size = newSize;
}

void HashTable::Add(int key, int value)
{
    if(LoadFactor() >= 0.75) Resize(size * 2);

    int idx = Hash(key);
    hash[idx].Add({key, value});
    nums++;
}

void HashTable::Remove(int key, int value)
{
    int idx = Hash(key);
    if (!hash[idx].Remove({key, value})) return;
    
    nums--;
    if(LoadFactor() < 0.25 && size > 1) Resize(size / 2);
}

bool HashTable::Find(int key, int value) const
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

void HashTable::Clear()
{
    for(int i = 0; i < size; i++)
    {
        hash[i].Clear();
    }
    nums = 0;
}