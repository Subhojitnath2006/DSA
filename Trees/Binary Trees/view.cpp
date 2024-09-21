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
// left view of a binary tree
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        ans.push_back(q.front()->data);
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}
//right view of a binary tree
vector<int> rightView(Node *root)
{
    // Your Code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        ans.push_back(q.back()->data);
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}
//top view of a binary tree
void find(Node* root,int pos,int &l,int &r){
        if(root==NULL) return;
        l=min(pos,l);
        r=max(pos,r);
        find(root->left,pos-1,l,r);
        find(root->right,pos+1,l,r);
    }
    void Tview(Node* root,int pos,vector<int>&ans,vector<int>&level,int l){
        if(root==NULL) return;
        if(level[pos]>l){
            ans[pos]=root->data;
            level[pos]=l;
        }
        Tview(root->left,pos-1,ans,level,l+1);
        Tview(root->right,pos+1,ans,level,l+1);
    }
    vector<int> topView(Node *root)
    {
        //Your code here
        int l=0,r=0;
        find(root,0,l,r);
        vector<int>ans(r-l+1);
        vector<int>level(r-l+1,INT_MAX);
        Tview(root,-1*l,ans,level,0);
        return ans;
        
    }

int main()
{
    Node *root = create();
    vector<int> ans1 = leftView(root);
    cout << "Left view of the binary tree is: ";
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " ";
    }
    cout << endl;

    vector<int>ans2=rightView(root);
    cout << "Right view of the binary tree is: ";
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }
    cout << endl;

    vector<int>ans3=topView(root);
    cout << "Top view of the binary tree is: ";
    for (int i = 0; i < ans3.size(); i++)
    {
        cout << ans3[i] << " ";
    }
    cout << endl;
    return 0;
}