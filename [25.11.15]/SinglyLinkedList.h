#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

struct Node
{
    int data;
    Node * next;
};

class SinglyLinkedList
{
private:
    Node * head;
    Node * tail;
    int size;
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    SinglyLinkedList(const SinglyLinkedList &) = delete;
    SinglyLinkedList & operator=(const SinglyLinkedList &) = delete;

    void Add(int data);
    void Remove(int data);
    void Insert(int data, int num);
    int Find(int data) const;
    void Clear();
    void Show() const;

    int Size() const {return size;}
};

#endif