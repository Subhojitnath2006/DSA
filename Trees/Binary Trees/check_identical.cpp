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
    { 
        return NULL;
    }
    Node *temp = new Node(num);
    cout << "Enter the left child of:" << num << " :";
    temp->left = create(); // enter at the left side
    cout << "Enter the right child of:" << num << " :";
    temp->right = create(); // enter at the right side
    return temp;
}
//check if two trees are identical
bool isSameTree(Node* p, Node* q) {
        if (p == NULL && q == NULL) {
        return true;
        }
        
        if (p == NULL || q == NULL) {
            return false;
        }
        
        if (p->data != q->data) {
            return false;
        }
        return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
}
//find the mirror image of a tree
void mirror(Node* node){
        if(node==NULL) return;
        
        Node* temp=node->right;
        node->right=node->left;
        node->left=temp;
        
        mirror(node->left);
        mirror(node->right);
}
//check if tree is balanced or not
 int height(Node* root,bool &valid){
        if(root==NULL){
            return 0;
        }
        int l=height(root->left,valid);
        int r=height(root->right,valid);
        if(abs(l-r)>1){
            valid=0;
        }
        return 1+max(l,r);
    }
    
    bool isBalanced(Node *root)
    {
        bool valid = 1;
        height(root,valid);
        return valid;
    }
int main()
{
    cout << "Enter the root node of 1st tree: ";
    Node *p;
    p = create();
    cout << "Enter the root node of 1st tree: ";
    Node *q;
    q = create();

    if (isSameTree(p, q))
    {
        cout << "Both trees are identical." << endl;
    }
    else
    {
        cout << "Both trees are not identical." << endl;
    }

    mirror(q);
    int valid=isBalanced(q);
    if(valid){
        cout<<"Tree is balanced."<<endl;
    }
    else{
        cout<<"Tree is not balanced."<<endl;
    }
    
    return 0;
}