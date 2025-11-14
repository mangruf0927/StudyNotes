#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
    // bool형 배열
    cout << "bool형 배열\n";
    Array<bool> arr(10);

    cout << "capacity : " << arr.Capacity() << ", ";
    cout << "size : " << arr.Size() << "\n";

    cout << "\n[Add]\n";
    arr.Add(true);   
    arr.Add(false);  
    arr.Add(true);   
    arr.Add(true);   
    arr.Add(false);  
    arr.Show();      

    cout << "capacity : " << arr.Capacity() << ", ";
    cout << "size : " << arr.Size() << "\n";

    cout << "\n[Find]\n";
    cout << "true idx : " << arr.Find(true) << "\n";
    cout << "false idx : " << arr.Find(false) << "\n";

    cout << "\n[Insert]\n";
    arr.Insert(true, false);
    arr.Insert(false, true);
    arr.Show();

    cout << "\n[Remove]\n";
    arr.Remove(true);
    arr.Remove(false);
    arr.Show();

    cout << "\n[Add]\n";
    for (int i = 0; i < 32; ++i) arr.Add((i % 2) == 0);
    arr.Show();
    cout << "\ncapacity : " << arr.Capacity() << ", ";
    cout << "size : " << arr.Size() << "\n";
    
    // int형 배열
    cout << "--------------------\n";
    cout << "int형 배열\n";
    Array<int> intArr(3);

    cout << "capacity : " << intArr.Capacity() << ", ";
    cout << "size : " << intArr.Size() << "\n";

    cout << "\n[Add]\n";
    intArr.Add(1);
    intArr.Add(2);
    intArr.Add(3);
    intArr.Show();
    cout << "capacity : " << intArr.Capacity() << ", ";
    cout << "size : " << intArr.Size() << "\n";

    cout << "\n[Add]\n";
    intArr.Add(4);
    intArr.Show();
    cout << "capacity : " << intArr.Capacity() << ", ";
    cout << "size : " << intArr.Size() << "\n";

    cout << "\n[Insert(2, 5)]\n";
    intArr.Insert(2, 5);
    intArr.Show();

    cout << "\n[Insert(8, 5)]\n";
    intArr.Insert(8, 5);
    intArr.Show();

    cout << "\n[Remove(27)]\n";
    intArr.Remove(27);
    intArr.Show();

    cout << "\n[Remove(4)]\n";
    intArr.Remove(4);
    intArr.Show();

    cout << "\n[Find(3)]\n" << intArr.Find(3) << "\n";
    cout << "\n[Find(7)]\n" << intArr.Find(7) << "\n";

    return 0;
}