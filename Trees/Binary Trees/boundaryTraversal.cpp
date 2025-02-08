#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
} Node;
void leftBoundary(Node *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
        return;
    ans.push_back(root->data);
    if (root->left)
        leftBoundary(root->left, ans);
    else
        leftBoundary(root->right, ans);
}
void leaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }
    leaf(root->left, ans);
    leaf(root->right, ans);
}
void rightBoundary(Node *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
        return;
    if (root->right)
        rightBoundary(root->right, ans);
    else
        rightBoundary(root->left, ans);
    ans.push_back(root->data);
}
vector<int> boundaryTraversal(Node *root)
{
    // code here
    vector<int> ans;
    ans.push_back(root->data);
    // insert left boundary
    leftBoundary(root->left, ans);
    // insert leaf nodes
    if (root->left || root->right)
        leaf(root, ans);
    // insert right boundary elements in reverse order
    rightBoundary(root->right, ans);
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = boundaryTraversal(root);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}