#ifndef INTARRAY_H_
#define INTARRAY_H_

class IntArray
{
private:
    int * arr;
    int size;
    int capacity;
public:
    IntArray(int init_capacity = 1);
    ~IntArray();

    IntArray(const IntArray &) = delete;
    IntArray & operator=(const IntArray &) = delete;

    void Add(int data);
    void Remove(int data);
    void Insert(int data, int num);
    int Find(int data) const;
    int Size() const {return size;}
    int Capacity() const {return capacity;}
    void Show() const;
};

#endif
