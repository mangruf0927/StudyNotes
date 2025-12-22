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
    int Size() const {return rear - front;}

    void Print() const;
};

template <typename T>
Queue<T>::Queue(int size)
{
    if(size <= 1) size = 1;
    capacity = size;
    front = 0;
    rear = 0;
    items = new T[capacity];
}

template <typename T>
Queue<T>::Queue(const Queue & queue)
{
    capacity = queue.capacity;
    front = 0;
    rear = queue.rear - queue.front;
    items = new T[capacity];
    for(int i = 0; i < rear; i++)
        items[i] = queue.items[queue.front + i];
}

template <typename T>
Queue<T>::~Queue()
{
    delete [] items;
}

template <typename T>
void Queue<T>::Enqueue(const T& item)
{
    if(!IsFull()) items[rear++] = item; 
}

template <typename T>
void Queue<T>::Dequeue()
{
    if(!IsEmpty()) front++;
}

template <typename T>
const T& Queue<T>::Peek()
{
    if(IsEmpty()) throw std::out_of_range("큐가 비어있습니다.");
    return items[front];
}

template <typename T>
bool Queue<T>::IsEmpty() const
{
    return front == rear;
}

template <typename T>
bool Queue<T>::IsFull() const
{
    return rear == capacity;
}

template <typename T>
void Queue<T>::Print() const
{
    if(IsEmpty()) return;
    
    for(int i = front; i < rear; i++)
    {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}

#endif