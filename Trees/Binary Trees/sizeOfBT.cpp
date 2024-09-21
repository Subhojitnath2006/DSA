#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node *create()
{
    int num;
    cin >> num;

    if (num == -1)
    { // stopping condition
        return NULL;
    }
    Node *temp = new Node(num);
    cout << "Enter the left child of:" << num << " :";
    temp->left = create(); // enter at the left side
    cout << "Enter the right child of:" << num << " :";
    temp->right = create(); // enter at the right side
    return temp;
}
int sizeOfBT(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    return 1 + sizeOfBT(root->left) + sizeOfBT(root->right);
}
int sumofBT(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->data + sumofBT(root->left) + sumofBT(root->right);
}
int countLeafNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return countLeafNode(root->left) + countLeafNode(root->right);
}
int heightofBT(Node* root){
    if(root==NULL) return 0;
    return 1+max(heightofBT(root->left),heightofBT(root->right));
}
int main()
{
    cout << "Enter the root node: ";
    Node *root;
    root = create();

    
    int size = sizeOfBT(root);
    cout << "Size of the binary tree is: " << size << endl;

    int sum = sumofBT(root);
    cout << "Sum of the binary tree is: " << sum << endl;

    int count = countLeafNode(root);
    cout << "Count of leaf nodes in the binary tree is: " << count << endl;


    int height=heightofBT(root);
    cout<<"Height of the binary tree is: "<<height<<endl;
    return 0;
}