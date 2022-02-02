//same as done in c
#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
stack<node *> stackz;
void preorderTra(node *root)
{
    if (root == NULL)
    {
        cout << "TREE IS EMPTY\n";
        return;
    }
    node *ptr = root;
    stackz.push(root);
    while (!stackz.empty())
    {
        ptr = stackz.top();
        stackz.pop();
        cout << ptr->data << " ";

        if (ptr->right != NULL)
        {
            stackz.push(ptr->right);
        }
        if (ptr->left != NULL)
        {
            stackz.push(ptr->left);
        }
    }
}

void inorderTra(node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty\n";
        return;
    }
    node *ptr = root;
    while (1)
    {
        while (ptr->left != NULL)
        {
            stackz.push(ptr);
            ptr = ptr->left;
        }
        while (ptr->right == NULL)
        {
            cout << ptr->data << " ";
            if (stackz.empty())
                return;
            ptr = stackz.top();
            stackz.pop();
        }
        cout << ptr->data << " ";
        ptr = ptr->right;
    }
}

void postorderTra(node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty\n";
        return;
    }
    node *ptr = root, *prevref = NULL;
    while (1)
    {
        while (ptr->left != NULL)
        {
            stackz.push(ptr);
            ptr = ptr->left;
        }
        while (ptr->right == NULL || ptr->right == prevref)
        {
            cout << ptr->data << " ";
            if (stackz.empty())
                return;
            prevref = ptr;
            ptr = stackz.top();
            stackz.pop();
        }
        stackz.push(ptr);
        ptr = ptr->right;
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(5);
    root->left->right->left = new node(6);
    root->left->right->right = new node(7);
    root->right->left->right = new node(8);
    /*
                     1
                   /   \
                  2     3
                 / \   / \
                n   4  5  n
                   /\  /\
                  6 7  n 8
    */
    preorderTra(root);
    cout << endl;
    inorderTra(root);
    cout << endl;
    postorderTra(root);
    cout << endl;

    return 0;
}