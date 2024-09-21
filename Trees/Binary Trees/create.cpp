#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
//another method to create binary tree
//Time complexity O(no of nodes)
//space complexity O(n) in worst case otherwise o(height of tree)
Node* create(){
    int num;
    cin>>num;

    if(num==-1){ //stopping condition
        return NULL;
    }
    Node* temp = new Node(num);
    cout<<"Enter the left child of:"<<num<<" :";
    temp->left=create(); //enter at the left side
    cout<<"Enter the right child of:"<<num<<" :";
    temp->right=create(); //enter at the right side
    return temp;
}
int main(){
    // int rootEl;
    // cout<<"Enter the root node: ";
    // cin>>rootEl;
    // queue<Node*>q;
    // Node* root= new Node(rootEl);
    // q.push(root);
    // while(!q.empty()){
    //     Node* temp = q.front();
    //     q.pop();

    //     int leftEl, rightEl;
    //     cout<<"Enter the left node of "<<temp->data<<" : ";
    //     cin>>leftEl;
    //     //create the left node
    //     if(leftEl!=-1){
    //         Node* left = new Node(leftEl);
    //         temp->left = left;
    //         q.push(left);
    //     }
    //     cout<<"Enter the right node of "<<temp->data<<" : ";
    //     cin>>rightEl;
    //     //create the right node
    //     if(rightEl!=-1){
    //         Node* right = new Node(rightEl);
    //         temp->right = right;
    //         q.push(right);
    //     }
    // }



//Another method to create binary tree
    cout<<"Enter the root node: ";
    Node* root;

    root=create();

    return 0;
}