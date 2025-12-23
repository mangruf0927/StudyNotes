#include "Queue.h"
#include "CircularQueue.h"
#include "QueueWithStack.h"
#include "StackWithQueue.h"
#include <iostream>
using namespace std;

int main()
{
    // 큐
    cout << "[Queue]\n";
    Queue<int> Q(5);
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

    Queue<int> Q2 = Q;
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
    cout << "\n";

    // 원형 큐
    cout << "[CircularQueue]\n";
    CircularQueue<int> CQ(5);
    cout << CQ.IsEmpty() << "\n";
    cout << CQ.Size() << "\n";

    CQ.Enqueue(5);    
    CQ.Enqueue(7);    
    CQ.Enqueue(58);
    CQ.Print();
    try {
        cout << CQ.Peek() << "\n";
    } catch(const out_of_range& e) 
    {
        cout << e.what() << "\n";
    }
    CQ.Dequeue();
    CQ.Print();

    CircularQueue<int> CQ2 = CQ;
    CQ2.Print();

    CQ2.Enqueue(30);
    CQ2.Enqueue(47);
    CQ2.Enqueue(16);
    CQ2.Enqueue(18);
    CQ2.Print();
    cout << CQ2.IsFull() << "\n";

    CQ.Dequeue();
    CQ.Dequeue();
    CQ.Dequeue();
    try {
        cout << CQ.Peek() << "\n";
    } catch(const out_of_range& e) 
    {
        cout << e.what() << "\n";
    }   
    
    // 스택을 이용한 큐 구현
    cout << "\n[QueueWithStack]\n";
    QueueWithStack<int> q(5);
    q.Enqueue(0);
    q.Enqueue(3);
    q.Enqueue(5);

    cout << q.Size() << "\n";

    try{
        cout << q.Peek() << "\n";
    }
    catch(const std::out_of_range& e)
    {
        cout << e.what() << "\n";
    }

    q.Dequeue();
    cout << q.Peek() << "\n";
    q.Dequeue();
    cout << q.Peek() << "\n";

    q.Enqueue(7);
    q.Enqueue(16);

    while(!q.IsEmpty())
    {
        std::cout << q.Peek() << " ";
        q.Dequeue();
    }
    cout << "\n";

    // 큐를 이용한 스택 구현
    cout << "\n[StackWithQueue]\n";
    StackWithQueue<int> st(5);
    st.Push(9);
    st.Push(27);
    st.Push(2);
    st.Push(1);
    st.Push(14);
    st.Push(19);

    cout << st.Size() << " " << st.IsFull() << "\n";

    cout << st.Top() << "\n";
    st.Pop();
    st.Pop();
    cout << st.Top() << "\n";
    st.Push(6);
    cout << st.Top() << "\n";

    while(!st.IsEmpty())
    {
        cout << st.Top() << " ";
        st.Pop();
    }
    cout << "\n";
    
    try{
        st.Top();
    }
    catch(const std::out_of_range& e)
    {
        cout << e.what() << "\n";
    }

    return 0;
}