#ifndef STACKWITHQUEUE_H_
#define STACKWITHQUEUE_H_

#include "CircularQueue.h"
#include <stdexcept>

template <typename T>
class StackWithQueue
{
private:
    CircularQueue<T> queue[2];

    int capacity;
    int count;
    int pushIdx;
    int popIdx;
public:
    StackWithQueue(int size = 1);
    StackWithQueue(const StackWithQueue& stackqueue);
    ~StackWithQueue();

    StackWithQueue<T>& operator=(const StackWithQueue& stackqueue) = delete;

    void Push(const T& item);
    void Pop();
    T Top();
    bool IsEmpty() const;
    bool IsFull() const;
    int Size() const {return count;}
};

template <typename T>
StackWithQueue<T>::StackWithQueue(int size) 
    : queue{CircularQueue<T>(size <= 0 ? 1 : size), CircularQueue<T>(size <= 0 ? 1 : size)}
{
    if(size <= 0) size = 1;
    capacity = size;
    count = 0;
    pushIdx = 0;
    popIdx = 1;
}

template <typename T>
StackWithQueue<T>::StackWithQueue(const StackWithQueue<T>& stackqueue)
    : queue{stackqueue.queue[0], stackqueue.queue[1]}
{
    capacity = stackqueue.capacity;
    count = stackqueue.count;
    pushIdx = stackqueue.pushIdx;
    popIdx = stackqueue.popIdx;
}

template <typename T>
StackWithQueue<T>::~StackWithQueue()
{
}

template <typename T>
void StackWithQueue<T>::Push(const T& item)
{
    if(IsFull()) return;

    queue[pushIdx].Enqueue(item);
    count++;
}

template <typename T>
void StackWithQueue<T>::Pop()
{
    if(IsEmpty()) return;

    if(queue[popIdx].IsEmpty())
    {
        while(queue[pushIdx].Size() > 1)
        {
            queue[popIdx].Enqueue(queue[pushIdx].Peek());
            queue[pushIdx].Dequeue();
        }
        popIdx = (popIdx + 1) % 2;
        pushIdx = (pushIdx + 1) % 2;
    }

    queue[popIdx].Dequeue();
    count--;
}

template <typename T>
T StackWithQueue<T>::Top()
{
    if(IsEmpty()) throw std::out_of_range("스택이 비어있습니다");

    if(queue[popIdx].IsEmpty())
    {
        while(queue[pushIdx].Size() > 1)
        {
            queue[popIdx].Enqueue(queue[pushIdx].Peek());
            queue[pushIdx].Dequeue();
        }
        popIdx = (popIdx + 1) % 2;
        pushIdx = (pushIdx + 1) % 2;
    }

    T top = queue[popIdx].Peek();
    queue[popIdx].Dequeue();
    queue[pushIdx].Enqueue(top);

    return top;
}

template <typename T>
bool StackWithQueue<T>::IsEmpty() const
{
    return count == 0;
}

template <typename T>
bool StackWithQueue<T>::IsFull() const
{
    return count == capacity;
}

#endif