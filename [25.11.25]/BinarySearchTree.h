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
public:
    BinarySearchTree();
    ~BinarySearchTree();

    bool Search(const int num) const;
    void Insert(const int num);
    void Remove(const int num);

    void PreOrder() const;        // 전위 순회
    void InOrder() const;         // 중위 순회
    void PostOrder() const;       // 후위 순회
};

#endif