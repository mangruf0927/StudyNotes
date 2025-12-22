#ifndef CIRCULARQUEUE_H_
#define CIRCULARQUEUE_H_

#include <stdexcept>
#include <iostream>

template <typename T>
class CircularQueue
{
private:
    int capacity;
    int front;
    int rear;
    int count;      
    T * items;
public:
    CircularQueue(int size = 1);
    CircularQueue(const CircularQueue & queue);
    ~CircularQueue();

    CircularQueue<T>& operator=(const CircularQueue& queue) = delete;

    void Enqueue(const T& item);
    void Dequeue();
    const T& Peek();
    bool IsEmpty() const;
    bool IsFull() const;
    int Size() const {return count;}

    void Print() const;
};

template <typename T>
CircularQueue<T>::CircularQueue(int size)
{
    if(size <= 0) size = 1;
    capacity = size;
    front = 0;
    rear = 0;
    count = 0;
    items = new T[capacity];
}

template <typename T>
CircularQueue<T>::CircularQueue(const CircularQueue & queue)
{
    capacity = queue.capacity;
    front = 0;
    rear = queue.count;
    count = queue.count;
    items = new T[capacity];
    for(int i = 0; i < queue.count; i++)
    {
        items[i] = queue.items[(queue.front + i) % queue.capacity];
    }
}

template <typename T>
CircularQueue<T>::~CircularQueue()
{
    delete [] items;
}

template <typename T>
void CircularQueue<T>::Enqueue(const T& item)
{
    if(IsFull()) return;

    items[rear] = item;
    rear = (rear + 1) % capacity;
    count++;
}

template <typename T>
void CircularQueue<T>::Dequeue()
{
    if(IsEmpty()) return;

    front = (front + 1) % capacity;
    count--;
}

template <typename T>
const T& CircularQueue<T>::Peek()
{
    if(IsEmpty()) throw std::out_of_range("큐가 비어있습니다.");
    return items[front];
}

template <typename T>
bool CircularQueue<T>::IsEmpty() const
{
    return count == 0;
}

template <typename T>
bool CircularQueue<T>::IsFull() const
{
    return count == capacity;
}

template <typename T>
void CircularQueue<T>::Print() const
{
    if(IsEmpty()) return;
    
    for(int i = 0; i < count; i++)
    {
        std::cout << items[(front + i) % capacity] << " ";
    }
    std::cout << std::endl;
}

#endif
