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

// bool 특수화
template <>
class Array<bool>
{
private:
    unsigned int * arr;
    int size;
    int capacity;
public:
    Array(int init_capacity = 1);
    ~Array();

    Array(const Array &) = delete;
    Array & operator=(const Array &) = delete;

    void Add(bool data);
    void Remove(bool data);
    void Insert(bool data, bool newData);
    int Find(bool data) const;
    int Size() const {return size;}
    int Capacity() const {return capacity;}
    void Show() const;
};

Array<bool>::Array(int init_capacity)
{
    if(init_capacity <= 0) init_capacity = 1;
    capacity = ((init_capacity + 31) / 32) * 32;    // 32의 배수로 증가
    int N = capacity / 32;                     
    arr = new unsigned int[N];
    for(int i = 0; i < N; i++) arr[i] = 0;
    size = 0;
}

Array<bool>::~Array()
{
    delete [] arr;
}

void Array<bool>::Add(bool data)
{
    if(size >= capacity) 
    {
        capacity += 32;
        int N = capacity / 32;
        unsigned int * newArr = new unsigned int[N];
        
        for(int i = 0; i < N - 1; i++) newArr[i] = arr[i];
        newArr[N - 1] = 0;
        
        delete [] arr;
        arr= newArr;
    }

    int idx = size / 32;
    int pos = size % 32;
    
    if(data) arr[idx] |= (1u << pos);
    else arr[idx] &= ~(1u << pos);
    
    size++;
}

void Array<bool>::Remove(bool data)
{
    int removeIdx = Find(data);
    if(removeIdx == -1) return;

    for(int i = removeIdx; i < size - 1; i++)
    {
        int fromIdx = (i + 1) / 32;
        int fromPos = (i + 1) % 32;

        int idx = i / 32;
        int pos = i % 32;

        bool isTrue = (arr[fromIdx] >> fromPos) & 1u;

        if(isTrue) arr[idx] |= (1u << pos);
        else arr[idx] &= ~(1u << pos);
    }
    size--;
}

void Array<bool>::Insert(bool data, bool newData)
{
    int findIdx = Find(data);
    if(findIdx == -1) return;

    if(size >= capacity) 
    {
        capacity += 32;
        int N = capacity / 32;
        unsigned int * newArr = new unsigned int[N];
        
        for(int i = 0; i < N - 1; i++) newArr[i] = arr[i];
        newArr[N - 1] = 0;
        
        delete [] arr;
        arr= newArr;
    }

    for(int i = size; i > findIdx + 1; i--)
    {
        int fromIdx = (i - 1) / 32;
        int fromPos = (i - 1) % 32;

        int idx = i / 32;
        int pos = i % 32;

        bool isTrue = (arr[fromIdx] >> fromPos) & 1u;

        if(isTrue) arr[idx] |= (1u << pos);
        else arr[idx] &= ~(1u << pos);
    }
    
    int insertIdx = (findIdx + 1) / 32;
    int insertPos = (findIdx + 1) % 32;

    if(newData) arr[insertIdx] |= (1u << (insertPos));
    else arr[insertIdx] &= ~(1u << (insertPos));

    size++;
}

int Array<bool>::Find(bool data) const
{
    for(int i = 0; i < size; i++)
    {
        int idx = i / 32;
        int pos = i % 32;

        if(((arr[idx] >> pos) & 1u) == data) return i;
    }
    return -1;
}

void Array<bool>::Show() const
{
    for(int i = 0; i < size; i++)
    {
        int idx = i / 32;
        int pos = i % 32;

        std::cout << ((arr[idx] >> pos) & 1u) << " ";

        if((pos + 1) % 32 == 0) std::cout << "\n";
    }
    std::cout << "\n";
}

#endif
