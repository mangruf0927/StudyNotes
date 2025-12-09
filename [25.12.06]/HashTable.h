#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "SinglyLinkedListT.h"
#include <iostream>

struct HashData
{
    int key;
    int value;

    bool operator==(const HashData & other) const
    {
        return key == other.key && value == other.value;
    }

    friend std::ostream& operator<<(std::ostream& os, const HashData& data)
    {
        os << "(" << data.key << ", " << data.value << ")";
        return os;
    }
};

class HashTable
{
private:
    int size;           // 배열 크기
    int nums;           // 저장된 항목의 수
    SinglyLinkedListT<HashData> * hash;

    int Hash(int key) const;
    double LoadFactor() const;
    void Resize(int newSize);
public:
    HashTable(int initSize = 1);
    ~HashTable();

    void Add(int key, int value);
    void Remove(int key, int value);
    bool Find(int key, int value) const;
    void Show() const;
    void Clear();
};

#endif