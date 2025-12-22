#include "CircularQueue.h"
#include <iostream>
using namespace std;

int main()
{
    CircularQueue<int> Q(5);
    cout << Q.IsEmpty() << "\n";
    cout << Q.Size() << "\n";
    
    Q.Enqueue(5);    
    Q.Enqueue(7);    
    Q.Enqueue(58);
    Q.Print();
    try {
        cout << Q.Peek() << "\n";
    } catch(const out_of_range& e) 
    {
        cout << e.what() << "\n";
    }
    Q.Dequeue();
    Q.Print();
    
    CircularQueue<int> Q2 = Q;
    Q2.Print();
        
    Q2.Enqueue(30);
    Q2.Enqueue(47);
    Q2.Enqueue(16);
    Q2.Enqueue(18);
    Q2.Print();
    cout << Q2.IsFull() << "\n";
        
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    try {
        cout << Q.Peek() << "\n";
    } catch(const out_of_range& e) 
    {
        cout << e.what() << "\n";
    }

    return 0;
}
