#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *LCA(Node *root, Node *n1, Node *n2)
{
    // code here
    if (root == NULL)
        return NULL;
    if (root->data > n1->data && root->data > n2->data)
    {
        return LCA(root->left, n1, n2);
    }
    else if (root->data < n1->data && root->data < n2->data)
    {
        return LCA(root->right, n1, n2);
    }
    else
        return root;
}
int main()
{
    Node *root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(3);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(10);
    root->right->left->left = new Node(11);
    root->right->left->right = new Node(12);
    root->right->right->left = new Node(13);
    Node *n1 = new Node(3);
    Node *n2 = new Node(12);
    Node *ans = LCA(root, n1, n2);
    cout << ans->data;
}