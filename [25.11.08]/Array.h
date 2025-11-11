#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>

template <typename T>
class Array
{
private:
    T * arr;
    int size;
    int capacity;
public:
    Array(int init_capacity = 1);
    ~Array();

    Array(const Array &) = delete;
    Array & operator=(const Array &) = delete;

    void Add(const T& data);
    void Remove(const T& data);
    void Insert(const T& data, const T& newData);
    int Find(const T& data) const;
    int Size() const {return size;}
    int Capacity() const {return capacity;}
    void Show() const;
};

template <typename T>
Array<T>::Array(int init_capacity)
{
    if(init_capacity <= 0) init_capacity = 1;

    capacity = init_capacity;
    arr = new T[init_capacity];
    size = 0;
}

template <typename T>
Array<T>::~Array()
{
    delete [] arr;
}

template <typename T>
void Array<T>::Add(const T& data)
{
    if(capacity <= size)
    {
        capacity *= 2;
        T * newArr = new T[capacity];
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

template <typename T>
void Array<T>::Remove(const T& data)
{
    int idx = Find(data);
    if(idx == -1) return;

    for(int i = idx; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

template <typename T>
void Array<T>::Insert(const T& data, const T& num)
{
    int idx = Find(data);
    if(idx == -1) return;

    if(capacity <= size)
    {
        capacity *= 2;
        T * newArr = new T[capacity];
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

template <typename T>
int Array<T>::Find(const T& data) const
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

template <typename T>
void Array<T>::Show() const
{
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

#endif