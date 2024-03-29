#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
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
    std::cin >> x;
    if (x < 0)
        return NULL;
    root = new binaryTree(x);
    std::cout << "Currently at node value: " << root->data << std::endl;
    std::cout << "Enter the left data to " << x;
    root->left = initTree(root->left);
    std::cout << "Enter the right data to " << x;
    root->right = (initTree(root->right));
    return root;
}

void levelOrderTraversal(binaryTree *node)
{
    std::queue<binaryTree *> q;
    q.push(node);
    q.push(NULL);

    while (!q.empty())
    {
        binaryTree *front = q.front();
        if (front != NULL)
            std::cout << " " << front->data << " ";
        q.pop();

        if (front->left != NULL)
        {
            q.push(front->left);
            q.push(NULL);
        }
        if (front->right != NULL)
        {
            q.push(front->right);
            q.push(NULL);
        }
    }
}

std::vector<std::vector<int>> levelOrder(binaryTree *node)
{
    std::vector<std::vector<int>> result;

    std::queue<binaryTree *> q;
    q.push(node);

    while (!q.empty())
    {
        std::vector<int> level;
        int levelsize = q.size();

        for (int i = 0; i < levelsize; i++)
        {
            binaryTree *local = q.front();
            q.pop();
            level.push_back(local->data);

            if (local->left != NULL)
            {
                q.push(local->left);
            }
            if (local->right != NULL)
            {
                q.push(local->right);
            }
            result.push_back(level);
        }
    }
}

std::vector<int> preOrderTraversal(binaryTree *node)
{
    std::vector<int> result;

    if (node == NULL)
        return result;

    std::queue<binaryTree *> q;
    q.push(node);

    while (!q.empty())
    {
        binaryTree *local = q.front();
        q.pop();
        result.push_back(local->data);
        if (local->left)
        {
            q.push(local->left);
        }
        if (local->right)
        {
            q.push(local->right);
        }
    }
}

int returnHeight(binaryTree *node, int height)
{
    if (node == NULL)
    {
        return height;
    }

    int leftHeight, rightHeight = 0;
    if (node->left)
    {
        height++;
        leftHeight = returnHeight(node->left, height);
    }
    if (node->right)
    {
        height++;
        rightHeight = returnHeight(node->right, height);
    }

    return std::max({leftHeight, rightHeight});
}

int main()
{
    binaryTree *tree = NULL;
    tree = initTree(tree);
}