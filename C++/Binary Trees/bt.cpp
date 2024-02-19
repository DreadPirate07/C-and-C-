#include <iostream>
#include <bits/stdc++.h>

class binaryTree
{
public:
    int data;
    binaryTree *left;
    binaryTree *right;

    binaryTree(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

binaryTree *initTree(binaryTree *root)
{
    int x;

    std::cout << "Enter the value: ";
    std::cin >> x;
    if (x < 0)
        return NULL;
    root = new binaryTree(x);
    std::cout << "Currently at node value:" << root->data << std::endl;
    root->left = initTree(root->left);
    root->right = (initTree(root->right));
    return root;
}

int main()
{
    binaryTree *tree = NULL;
    tree = initTree(tree);
}