#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <stdexcept>

template <typename T>
class Stack
{
private:
    int capacity;
    int top;
    T * items;
public:
    Stack(int size = 1);
    Stack(const Stack & stack);
    ~Stack();
    
    Stack<T>& operator=(const Stack& stack) = delete;

    void Push(const T& item);
    void Pop();
    const T& Top();
    bool IsFull() const;
    bool IsEmpty() const;
    int Size() const {return top;}

    void Print() const;
};

template <typename T>
Stack<T>::Stack(int size)
{
    if(size <= 0) size = 1;

    capacity = size;
    top = 0;
    items = new T[capacity];
}

template <typename T>
Stack<T>::Stack(const Stack & stack)
{
    capacity = stack.capacity;
    top = stack.top;
    items = new T[capacity];
    for(int i = 0; i < top; i++) 
        items[i] = stack.items[i];
}

template <typename T>
Stack<T>::~Stack()
{
    delete [] items;
}

template <typename T>
void Stack<T>::Push(const T& item)
{
    if(!IsFull()) items[top++] = item;
}

template <typename T>
void Stack<T>::Pop()
{
    if(!IsEmpty()) top--;
}

template <typename T>
const T& Stack<T>::Top()
{
    if(IsEmpty()) throw std::out_of_range("스택이 비어있습니다.");

    return items[top - 1];
}

template <typename T>
bool Stack<T>::IsFull() const
{
    return top >= capacity;
}

template <typename T>
bool Stack<T>::IsEmpty() const
{
    return top <= 0;
}

template <typename T>
void Stack<T>::Print() const
{
    for(int i = top - 1; i >= 0; i--)
        std::cout << items[i] << " ";
    
    std::cout << std::endl;
}

#endif