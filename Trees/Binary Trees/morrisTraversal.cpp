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
//morris inorder traversal
//time complexity O(n)
//space complexity O(1)
vector<int>morrisInOrdrer(Node *root)
{
    vector<int>inorder;
    Node *curr = root;
    while (curr != NULL)
    {
        //left subtree doesn't exist
        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        //left subtree exists
        else
        {
            Node *temp = curr->left;
            while (temp->right != NULL && temp->right != curr)
            {
                temp = temp->right;
            }
            // if the right of the left node is null means left subtree is not visited
            if (temp->right == NULL)
            {
                temp->right = curr;
                curr = curr->left;
            }
            // if the right of the left node is not null means left subtree is visited
            else
            {
                temp->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }   
    }
    return inorder;
}

//morris preorder traversal
//time complexity O(n)
//space complexity O(1)
vector<int>morrisPreOrder(Node *root)
{
    vector<int>preorder;
    Node *curr = root;
    while (curr != NULL)
    {
        //left subtree doesn't exist
        if (curr->left == NULL)
        {
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        //left subtree exists
        else
        {
            Node *temp = curr->left;
            while (temp->right != NULL && temp->right != curr)
            {
                temp = temp->right;
            }
            // if the right of the left node is null means left subtree is not visited
            if (temp->right == NULL)
            {

                temp->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }
            // if the right of the left node is not null means left subtree is visited
            else
            {
                temp->right = NULL;
                
                curr = curr->right;
            }
        }   
    }
    return preorder;
}

vector<int>morrisPostOrder(Node* root){
    vector<int> ans;
    Node* current = root;

    while (current) {
        if (current->right == NULL) {
            // If no right child, visit the current node and move to the left
            ans.push_back(current->data);
            current = current->left;
        } else {
            // Find the inorder predecessor (leftmost node in the right subtree)
            Node* predecessor = current->right;
            while (predecessor->left != NULL && predecessor->left != current) {
                predecessor = predecessor->left;
            }

            if (predecessor->left == NULL) {
                // If left child of predecessor is NULL, update it and move right
                ans.push_back(current->data);
                predecessor->left = current;
                current = current->right;
            } else {
                // Left child of predecessor already points to the current node
                predecessor->left = NULL; // Restore the original tree structure
                current = current->left;
            }
        }
    }
    
    return ans;
}
int main(){
    cout << "Enter the root node: ";
    Node* root=create();

    // cout<<"Inorder Traversal: ";
    // vector<int>inorder=morrisInOrdrer(root);
    // for(int i=0;i<inorder.size();i++){
    //     cout<<inorder[i]<<" ";
    // }
    // cout<<endl;

    // cout<<"Morris Preorder Traversal: ";
    // vector<int>preorder=morrisPreOrder(root);
    // for(int i=0;i<preorder.size();i++){
    //     cout<<preorder[i]<<" ";
    // }
    // cout<<endl;

    cout<<"Morris Postorder Traversal: ";
    vector<int>postorder=morrisPostOrder(root);
    reverse(postorder.begin(),postorder.end());
    for(int i=0;i<postorder.size();i++){
        cout<<postorder[i]<<" ";
    }
    cout<<endl;
}