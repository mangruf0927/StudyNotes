#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T> * next;
};

template <typename T>
class SinglyLinkedListT
{
private:
    Node<T> * head;
    Node<T> * tail;
    int size;
public:
    SinglyLinkedListT();
    ~SinglyLinkedListT();

    SinglyLinkedListT(const SinglyLinkedListT &) = delete;
    SinglyLinkedListT & operator=(const SinglyLinkedListT &) = delete;

    void Add(const T & data);
    void Remove(const T & data);
    void Insert(const T & data, const T & newData);
    int Find(const T & data) const;
    void Clear();
    void Reverse();
    void Show() const;

    int Size() const {return size;}
};

template <typename T>
SinglyLinkedListT<T>::SinglyLinkedListT()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
SinglyLinkedListT<T>::~SinglyLinkedListT()
{
    Clear();
}

template <typename T>
void SinglyLinkedListT<T>::Add(const T& data)
{
    Node<T> * newNode = new Node<T>{data, nullptr};

    if(head == nullptr) 
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
void SinglyLinkedListT<T>::Remove(const T & data)
{
    if(head == nullptr) return;

    // head
    if(head->data == data)
    {
        Node<T> * temp = head;
        head = head->next;
        delete temp;

        if(head == nullptr) tail = nullptr;

        size--;
        return;
    }

    // 중간 / 마지막
    Node<T> * cur = head;
    while(cur->next != nullptr)
    {
        if(cur->next->data == data) break;
        cur = cur->next;
    }

    if(cur->next == nullptr) return;

    Node<T> * target = cur->next;
    cur->next = target->next;
    if(target == tail) tail = cur;

    delete target;
    size--;
}

template <typename T>
void SinglyLinkedListT<T>::Insert(const T& data, const T& newData)
{
    if(head == nullptr) return;

    Node<T> * cur = head;
    while(cur != nullptr)
    {
        if(cur->data == data) break;
        cur = cur->next;
    }
    if(cur == nullptr) return;

    Node<T> * newNode = new Node<T>{newData, nullptr};

    if(cur == tail)
    {
        cur->next = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = cur->next;
        cur->next = newNode;
    }

    size++;
}

template <typename T>
int SinglyLinkedListT<T>::Find(const T& data) const
{
    Node<T> * cur = head;
    int idx = 0;
    while(cur != nullptr)
    {
        if(cur->data == data) return idx;

        idx++; 
        cur = cur->next;
    }
    return -1;
}

template <typename T>
void SinglyLinkedListT<T>::Clear()
{
    Node<T> * cur = head;
    while(cur != nullptr)
    {
        Node<T> * temp = cur;
        cur = cur->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
void SinglyLinkedListT<T>::Reverse()
{
    if(head == nullptr || head == tail) return;

    Node<T> * cur = head;
    while(cur->next != nullptr)
    {
        Node<T> * temp = cur->next;
        cur->next = temp->next;

        temp->next = head;
        head = temp;
    }
    tail = cur;
}

template <typename T>
void SinglyLinkedListT<T>::Show() const
{
    if(head == nullptr)
    {
        std::cout << "리스트가 비어있습니다.\n";
        return;
    }

    Node<T> * cur = head;
    while(cur != nullptr)
    {
        std::cout << cur->data << " ";
        cur = cur->next;
    }

    std::cout << "\n";
}

#endif