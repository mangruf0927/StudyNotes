#ifndef DOUBLYLINKEDLISTT_H_
#define DOUBLYLINKEDLISTT_H_

#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T> * prev;
    Node<T> * next;
};

template <typename T>
class DoublyLinkedListT
{
private:
    Node<T> * head;
    Node<T> * tail;
    int size;
public:
    DoublyLinkedListT();
    ~DoublyLinkedListT();

    DoublyLinkedListT(const DoublyLinkedListT &) = delete;
    DoublyLinkedListT & operator=(const DoublyLinkedListT &) = delete;

    void Add(const T & data);
    void Remove(const T & data);
    void Insert(const T & data, const T & nextData);
    int Find(const T & data) const;
    void Clear();
    void Reverse();
    void Show() const;
    void ShowReverse() const;

    int Size() const {return size;}
};

template <typename T>
DoublyLinkedListT<T>::DoublyLinkedListT()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
DoublyLinkedListT<T>::~DoublyLinkedListT()
{
    Clear();
}

template <typename T>
void DoublyLinkedListT<T>::Add(const T & data)
{
    Node<T> * newNode = new Node<T>{data, nullptr, nullptr};

    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedListT<T>::Remove(const T & data)
{
    if(head == nullptr) return;

    // head
    if(head->data == data)
    {
        Node<T> * temp = head;
        head = head->next;
        delete temp;

        if(head == nullptr) tail = nullptr;
        else head->prev = nullptr;

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
    else target->next->prev = cur;
    
    delete target;
    size--;
}

template <typename T>
void DoublyLinkedListT<T>::Insert(const T & data, const T & newData)
{
    if(head == nullptr) return;

    Node<T> * cur = head;
    while(cur != nullptr)
    {
        if(cur->data == data) break;
        cur = cur->next;
    }
    if(cur == nullptr) return;

    Node<T> * newNode = new Node<T>{newData, nullptr, nullptr};

    if(cur == tail)
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = cur;
        newNode->next = cur->next;
        cur->next->prev = newNode;
        cur->next = newNode;
    }
    size++;
}

template <typename T>
int DoublyLinkedListT<T>::Find(const T & data) const
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
void DoublyLinkedListT<T>::Clear()
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
void DoublyLinkedListT<T>::Reverse()
{
    if(head == nullptr || head == tail) return;

    Node<T> * cur = head;
    while(cur->next != nullptr)
    {
        Node<T> * temp = cur->next;
        cur->next = temp->next;

        temp->next = head;
        head->prev = temp;
        head = temp;
        head->prev = nullptr;
    }
    tail = cur;
}

template <typename T>
void DoublyLinkedListT<T>::Show() const
{
    if(head == nullptr) return;

    Node<T> * cur = head;
    while(cur != nullptr)
    {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << "\n";
}

template <typename T>
void DoublyLinkedListT<T>::ShowReverse() const
{
    if(head == nullptr) return;

    Node<T> * cur = tail;
    while(cur != nullptr)
    {
        std::cout << cur->data << " ";
        cur = cur->prev;
    }
    std::cout << "\n";
}

#endif