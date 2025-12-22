#ifndef QUEUEWITHSTACK_H_
#define QUEUEWITHSTACK_H_

#include "Stack.h"
#include <stdexcept>

template <typename T>
class QueueWithStack
{
private:
    Stack<T> pushStack;
    Stack<T> popStack;

    int capacity;
    int count;
public:
    QueueWithStack(int size = 1);
    QueueWithStack(const QueueWithStack& queue);
    ~QueueWithStack();

    QueueWithStack<T>& operator=(const QueueWithStack& queue) = delete;

    void Enqueue(const T& item);
    void Dequeue();
    const T& Peek();
    bool IsEmpty() const;
    bool IsFull() const;
    int Size() const {return count;}
};

template <typename T>
QueueWithStack<T>::QueueWithStack(int size)
    : pushStack(size), popStack(size)
{
    if(size <= 0) size = 1;
    capacity = size;
    count = 0;
}

template <typename T>
QueueWithStack<T>::QueueWithStack(const QueueWithStack & queue)
    : pushStack(queue.pushStack), popStack(queue.popStack)
{
    capacity = queue.capacity;
    count = queue.count;
}

template <typename T>
QueueWithStack<T>::~QueueWithStack()
{
}

template <typename T>
void QueueWithStack<T>::Enqueue(const T& item)
{
    if(IsFull()) return;

    pushStack.Push(item);
    count++;
}

template <typename T>
void QueueWithStack<T>::Dequeue()
{
    if(IsEmpty()) return;

    if(popStack.IsEmpty()) 
    {
        while(!pushStack.IsEmpty())
        {
            popStack.Push(pushStack.Top());
            pushStack.Pop();
        }
    }
    popStack.Pop();
    count--;
}

template <typename T>
const T& QueueWithStack<T>::Peek()
{
    if(IsEmpty()) throw std::out_of_range("큐가 비어있습니다");

    if(popStack.IsEmpty())
    {
        while(!pushStack.IsEmpty())
        {
            popStack.Push(pushStack.Top());
            pushStack.Pop();
        }
    }
    return popStack.Top();
}

template <typename T>
bool QueueWithStack<T>::IsEmpty() const
{
    return count == 0;
}

template <typename T>
bool QueueWithStack<T>::IsFull() const
{
    return count == capacity;
}

#endif