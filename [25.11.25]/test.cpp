#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree bsTree;
    
    bsTree.Insert(8);
    bsTree.Insert(3);
    bsTree.Insert(10);
    bsTree.Insert(1);
    bsTree.Insert(6);
    bsTree.Insert(14);
    bsTree.Insert(4);
    bsTree.Insert(7);
    bsTree.Insert(13);
    
    cout << "[bsTree]\n";
    bsTree.Print();
    
    cout << "[bsTree2]\n";
    BinarySearchTree bsTree2(bsTree);
    bsTree2.Print();

    bsTree.Remove(8);
    bsTree.Remove(3);
    bsTree.Remove(13);
    bsTree.Remove(10);

    cout << "[bsTree]\n";
    bsTree.Print();

    bsTree2 = bsTree;
    cout << "[bsTree2]\n";
    bsTree2.Print();
 
    return 0;
}