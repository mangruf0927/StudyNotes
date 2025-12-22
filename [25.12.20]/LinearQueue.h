#ifndef LINEARQUEUE_H_
#define LINEARQUEUE_H_

#include <stdexcept>
#include <iostream>

template <typename T>
class LinearQueue
{
private:
    int capacity;
    int front;
    int rear;     
    T * items;
public:
    LinearQueue(int size = 1);
    LinearQueue(const LinearQueue & queue);
    ~LinearQueue();

    LinearQueue<T>& operator=(const LinearQueue& queue) = delete;

    void Enqueue(const T& item);
    void Dequeue();
    const T& Peek();
    bool IsEmpty() const;
    bool IsFull() const;
    int Size() const {return rear - front;}

    void Print() const;
};

template <typename T>
LinearQueue<T>::LinearQueue(int size)
{
    if(size <= 0) size = 1;
    capacity = size;
    front = 0;
    rear = 0;
    items = new T[capacity];
}

template <typename T>
LinearQueue<T>::LinearQueue(const LinearQueue & queue)
{
    capacity = queue.capacity;
    front = 0;
    rear = queue.rear - queue.front;
    items = new T[capacity];
    for(int i = 0; i < rear; i++)
        items[i] = queue.items[queue.front + i];
}

template <typename T>
LinearQueue<T>::~LinearQueue()
{
    delete [] items;
}

template <typename T>
void LinearQueue<T>::Enqueue(const T& item)
{
    if(!IsFull()) items[rear++] = item; 
}

template <typename T>
void LinearQueue<T>::Dequeue()
{
    if(!IsEmpty()) front++;
}

template <typename T>
const T& LinearQueue<T>::Peek()
{
    if(IsEmpty()) throw std::out_of_range("큐가 비어있습니다.");
    return items[front];
}

template <typename T>
bool LinearQueue<T>::IsEmpty() const
{
    return front == rear;
}

template <typename T>
bool LinearQueue<T>::IsFull() const
{
    return rear == capacity;
}

template <typename T>
void LinearQueue<T>::Print() const
{
    if(IsEmpty()) return;
    
    for(int i = front; i < rear; i++)
    {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}

#endif
