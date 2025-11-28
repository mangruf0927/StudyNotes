#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

struct Node
{
    Node * left;
    int data;
    Node * right;
};

class BinarySearchTree
{
private:
    Node * root;

    void PreOrder(Node * node) const;        // 전위 순회
    void InOrder(Node * node) const;         // 중위 순회
    void PostOrder(Node * node) const;       // 후위 순회
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& bsTree);
    ~BinarySearchTree();

    bool Search(const int num) const;
    void Insert(const int num);
    void Remove(const int num);

    void PreOrder() const; 
    void InOrder() const;  
    void PostOrder() const;

};

#endif