#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

struct Node
{
    int data;
    Node * prev;
    Node * next;
};

class DoublyLinkedList
{
private:
    Node * head;
    Node * tail;
    int size;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    DoublyLinkedList(const DoublyLinkedList &) = delete;
    DoublyLinkedList & operator=(const DoublyLinkedList &) = delete;

    void Add(int data);
    void Remove(int data);
    void Insert(int data, int num);
    int Find(int data) const;
    void Clear();
    void Show() const;
    void ShowReverse() const;

    int Size() const {return size;}
};

#endif