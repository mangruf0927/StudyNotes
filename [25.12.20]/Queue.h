#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdexcept>
#include <iostream>

template <typename T>
class Queue
{
private:
    int capacity;
    int front;
    int rear;
    int count;      
    T * items;
public:
    Queue(int size = 1);
    Queue(const Queue & queue);
    ~Queue();

    Queue<T>& operator=(const Queue& queue) = delete;

    void Enqueue(const T& item);
    void Dequeue();
    const T& Peek();
    bool IsEmpty() const;
    bool IsFull() const;
    int Size() const {return count;}

    void Print() const;
};

template <typename T>
Queue<T>::Queue(int size)
{
    if(size <= 0) size = 1;
    capacity = size;
    front = 0;
    rear = 0;
    count = 0;
    items = new T[capacity];
}

template <typename T>
Queue<T>::Queue(const Queue & queue)
{
    capacity = queue.capacity;
    front = 0;
    rear = queue.count;
    count = queue.count;
    items = new T[capacity];
    for(int i = 0; i < count; i++)
    {
        items[i] = queue.items[(front + i) % capacity];
    }
}

template <typename T>
Queue<T>::~Queue()
{
    delete [] items;
}

template <typename T>
void Queue<T>::Enqueue(const T& item)
{
    if(IsFull()) return;

    items[rear] = item;
    rear = (rear + 1) % capacity;
    count++;
}

template <typename T>
void Queue<T>::Dequeue()
{
    if(IsEmpty()) return;

    front = (front + 1) % capacity;
    count--;
}

template <typename T>
const T& Queue<T>::Peek()
{
    if(IsEmpty()) throw std::out_of_range("큐가 비어있습니다.");
    return items[rear];
}

template <typename T>
bool Queue<T>::IsEmpty() const
{
    return count == 0;
}

template <typename T>
bool Queue<T>::IsFull() const
{
    return count == capacity;
}

template <typename T>
void Queue<T>::Print() const
{
    if(IsEmpty()) return;
    
    for(int i = 0; i < count; i++)
    {
        std::cout << items[(front + i) % capacity] << " ";
    }
    std::cout << std::endl;
}

#endif