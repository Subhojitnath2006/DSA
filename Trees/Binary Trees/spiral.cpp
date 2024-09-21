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
vector<int> findSpiral(Node *root)
{
    //Your code here
    stack<Node*>s1;
    stack<Node*>s2;
    vector<int>ans;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        if(!s1.empty()){
            while(!s1.empty()){
                Node* temp=s1.top();
                s1.pop();
                ans.push_back(temp->data);
                if(temp->right) s2.push(temp->right);
                if(temp->left) s2.push(temp->left);
            }
        }
        else{
            while(!s2.empty()){
                Node* temp=s2.top();
                s2.pop();
                ans.push_back(temp->data);
                if(temp->left) s1.push(temp->left);
                if(temp->right) s1.push(temp->right);
            }
        }
    }
    return ans;
}
int main()
{
    Node *root = create();
    vector<int> ans = findSpiral(root);
    cout<<"In order traversal in spiral form:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}