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

    Node * Copy(Node * node) const;
    void Print(Node * node) const;
    void Clean(Node * node) const;
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinarySearchTree(const BinarySearchTree& bsTree);
    BinarySearchTree& operator=(const BinarySearchTree & bsTree);

    bool Search(const int num) const;
    void Insert(const int num);
    void Remove(const int num);

    void Print() const;
};

#endif