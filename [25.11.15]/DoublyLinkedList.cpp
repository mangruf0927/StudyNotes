#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
    Clear();
}

void DoublyLinkedList::Add(int data)
{
    Node * newNode = new Node{data, nullptr, nullptr};

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

void DoublyLinkedList::Remove(int data)
{
    if(head == nullptr) return;

    // head
    if(head->data == data)
    {
        Node * temp = head;
        head = head->next;
        delete temp;

        if(head == nullptr) tail = nullptr;
        else head->prev = nullptr;

        size--;
        return;
    }

    // 중간 / 마지막
    Node * cur = head;
    while(cur->next != nullptr)
    {
        if(cur->next->data == data) break;
        cur = cur->next;
    }
    if(cur->next == nullptr) return;

    Node * target = cur->next;
    cur->next = target->next;
    
    if(target == tail) tail = cur;
    else target->next->prev = cur;
    
    delete target;
    size--;
}

void DoublyLinkedList::Insert(int data, int num)
{
    if(head == nullptr) return;

    Node * cur = head;
    while(cur != nullptr)
    {
        if(cur->data == data) break;
        cur = cur->next;
    }
    if(cur == nullptr) return;

    Node * newNode = new Node{num, nullptr, nullptr};

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

int DoublyLinkedList::Find(int data) const
{
    Node * cur = head;
    int idx = 0;
    while(cur != nullptr)
    {
        if(cur->data == data) return idx;
        
        idx++;
        cur = cur->next;
    }

    return -1;
}

void DoublyLinkedList::Clear()
{
    Node * cur = head;
    while(cur != nullptr)
    {
        Node * temp = cur;
        cur = cur->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}

void DoublyLinkedList::Show() const
{
    if(head == nullptr) return;

    Node * cur = head;
    while(cur != nullptr)
    {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << "\n";
}

void DoublyLinkedList::ShowReverse() const
{
    if(head == nullptr) return;

    Node * cur = tail;
    while(cur != nullptr)
    {
        std::cout << cur->data << " ";
        cur = cur->prev;
    }
    std::cout << "\n";
}