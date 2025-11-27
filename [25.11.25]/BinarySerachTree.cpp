#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{

}

bool BinarySearchTree::Search(const int num) const
{
    if(root == nullptr) return false;

    Node * cur = root;
    while(cur != nullptr)
    {
        if(cur->data == num) return true;
        else if(cur->data > num) cur = cur->left;
        else cur = cur->right;
    }
    return false;
}

void BinarySearchTree::Insert(const int num)
{
    if(root == nullptr) 
    {
        root = new Node{nullptr, num, nullptr};;
        return;
    }

    Node * cur = root;
    while(true)
    {
        if(cur->data == num) return;        // 중복된 키 허용 안 함
        else if(cur->data > num)           
        {
            if(cur->left != nullptr) cur = cur->left;
            else
            {
                cur->left = new Node{nullptr, num, nullptr};;
                return;
            }
        }  
        else                                
        {
            if(cur->right != nullptr) cur = cur->right;
            else
            {
                cur->right = new Node{nullptr, num, nullptr};;
                return;
            }
        }
    }
}

void BinarySearchTree::Remove(const int num)
{
    if(root == nullptr) return;

    Node * cur = root;
    Node * curParent = nullptr;

    // 삭제할 노드 찾기
    while(cur != nullptr)
    {
        if(cur->data == num) break;

        curParent = cur;
        if(cur->data > num) cur = cur->left;
        else cur = cur->right;
    }
    // 못 찾은 경우
    if(cur == nullptr) return;  

  
    if(cur->left == nullptr && cur->right == nullptr)           // 1. 리프 노드인 경우
    {
        if(curParent == nullptr) root = nullptr;
        else
        {
            if(curParent->left == cur) curParent->left = nullptr;
            else curParent->right = nullptr;
        }

        delete cur;
    }
    else if(cur->left == nullptr || cur->right == nullptr)      // 2. 자식이 하나인 경우
    {
        Node * child;

        if(cur->left == nullptr) child = cur->right;
        else child = cur->left;

        if(curParent == nullptr) root = child;
        else 
        {
            if(curParent->left == cur) curParent->left = child;
            else curParent->right = child;
        }

        delete cur;
    }
    else                                                        // 3. 자식이 두 개인 경우
    {
        Node * targetParent = cur;
        Node * target = cur->right;

        while(target->left != nullptr)
        {
            targetParent = target;
            target = target->left;
        }

        cur->data = target->data;

        if(targetParent->left == target) targetParent->left = target->right;
        else targetParent->right = target->right;

        delete target;
    }
}

void BinarySearchTree::PreOrder() const
{

}   

void BinarySearchTree::InOrder() const
{

}   

void BinarySearchTree::PostOrder() const
{

}