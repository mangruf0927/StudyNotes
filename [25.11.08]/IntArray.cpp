#include "IntArray.h"
#include <iostream>

IntArray::IntArray(int init_capacity)
{
    if(init_capacity <= 0) init_capacity = 1;

    capacity = init_capacity;
    arr = new int[init_capacity];
    size = 0;
}

IntArray::~IntArray()
{
    delete [] arr;
}

void IntArray::Add(int data)
{
    if(capacity <= size)
    {
        capacity *= 2;
        int * newArr = new int[capacity];
        for(int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        delete [] arr;
        arr= newArr;
    }

    arr[size] = data;
    size++;
}

void IntArray::Remove(int data)
{
    int idx = Find(data);
    if(idx == -1) return;

    for(int i = idx; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

void IntArray::Insert(int data, int num)
{
    int idx = Find(data);
    if(idx == -1) return;

    if(capacity <= size)
    {
        capacity *= 2;
        int * newArr = new int[capacity];
        for(int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        delete [] arr;
        arr= newArr;
    }

    for(int i = size; i > idx; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[idx + 1] = num;
    size++;
}

int IntArray::Find(int data) const
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

void IntArray::Show() const
{
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}