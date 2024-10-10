// a binary tree is given find the maximum bst
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
        left = right = NULL;
    }
};
class Box
{
public:
    bool BST;
    int size;
    int max, min;

    Box()
    {
        BST = 1;
        size = 0;
        max = INT_MIN;
        min = INT_MAX;
    }
};
Box *find(Node *root, int &totalSize)
{
    if (!root)
    {
        return new Box();
    }
    Box *lHead = find(root->left, totalSize);
    Box *rHead = find(root->right, totalSize);
    if (lHead->BST && rHead->BST && lHead->max < root->data && rHead->min > root->data)
    {
        Box *head = new Box();
        head->size = 1 + lHead->size + rHead->size;
        head->min = min(root->data, lHead->min);
        head->max = max(root->data, rHead->max);
        totalSize = max(totalSize, head->size);
        return head;
    }
    else
    {
        lHead->BST = 0;
        return lHead;
    }
}
int largestBst(Node *root)
{
    // Your code here
    int totalSize = 0;
    find(root, totalSize);
    return totalSize;
}

//find largest sum of bst in a binary tree
// class Box{
//         public:
//             bool BST;
//             int sum;
//             int max,min;
            
//             Box(){
//                 BST=1;
//                 sum=0;
//                 max=INT_MIN;
//                 min=INT_MAX;
//             }
//     };
// Box* find(Node* root,int &totalSum){
//         if(!root){
//             return new Box();
//         }
//         Box* lHead=find(root->left,totalSum);
//         Box* rHead=find(root->right,totalSum);
//         if(lHead->BST && rHead->BST && lHead->max<root->val && rHead->min> root->val){
//             Box* head=new Box();
//             head->sum=root->data+lHead->data+rHead->sum;
//             head->min=min(root->data,lHead->min);
//             head->max=max(root->data,rHead->max);
//             totalSum=max(totalSum,head->sum);
//             return head;
//         }
//         else{
//             lHead->BST=0;
//             return lHead;
//         }    
//     }
//     int maxSumBST(Node* root) {
//         int totalSum=0;
//         find(root,totalSum);
//         return totalSum;
//     }
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    cout << largestBst(root);
    return 0;
}