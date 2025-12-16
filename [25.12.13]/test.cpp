#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<int> S(6);
    cout << S.IsEmpty() << "\n";
    
    S.Push(10);    
    S.Push(20);    
    S.Push(30);
    S.Print();

    cout << S.Top() << "\n";

    S.Pop();
    S.Print();

    Stack<int> S2 = S;
    S2.Print();
    
    S2.Push(40);
    S2.Push(50);
    S2.Push(60);
    S2.Push(70);
    S2.Print();
    cout << S2.IsFull() << "\n";
    
    S.Pop();
    S.Pop();
    S.Pop();
    cout << S.Top() << "\n";

    return 0;
}