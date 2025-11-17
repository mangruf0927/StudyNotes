#include "SinglyLinkedList.h"
#include <iostream>

SinglyLinkedList::SinglyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

SinglyLinkedList::~SinglyLinkedList()
{
    Clear();
}

void SinglyLinkedList::Add(int data)
{
    Node * newNode = new Node{data, nullptr};

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

void SinglyLinkedList::Remove(int data)
{
    if(head == nullptr) return;

    // head
    if(head->data == data)
    {
        Node * temp = head;
        head = head->next;
        delete temp;

        if(head == nullptr) tail = nullptr;

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

    delete target;
    size--;
}

void SinglyLinkedList::Insert(int data, int num)
{
    if(head == nullptr) return;

    Node * cur = head;
    while(cur != nullptr)
    {
        if(cur->data == data) break;
        cur = cur->next;
    }
    if(cur == nullptr) return;

    Node * newNode = new Node{num, nullptr};

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

int SinglyLinkedList::Find(int data) const
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

void SinglyLinkedList::Clear()
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

void SinglyLinkedList::Reverse()
{
    if(head == nullptr || head == tail) return;

    Node * cur = head;
    while(cur->next != nullptr)
    {
        Node * temp = cur->next;
        cur->next = temp->next;

        temp->next = head;
        head = temp;
    }
    tail = cur;
}


void SinglyLinkedList::Show() const
{
    if(head == nullptr)
    {
        std::cout << "리스트가 비어있습니다.\n";
        return;
    }

    Node * cur = head;
    while(cur != nullptr)
    {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << "\n";
}