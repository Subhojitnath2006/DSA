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
void findInorder(Node *root, vector<int> &temp)
{

    if (root == NULL)
        return;
    findInorder(root->left, temp);
    temp.push_back(root->data);
    findInorder(root->right, temp);
}
vector<int> merge(Node *root1, Node *root2)
{
    // Your code here
    vector<int> ans;
    vector<int> r1, r2;
    findInorder(root1, r1);
    findInorder(root2, r2);

    int l = 0, r = 0;

    while (l < r1.size() && r < r2.size())
    {
        if (r1[l] == r2[r])
        {
            ans.push_back(r1[l]);
            ans.push_back(r2[r]);
            l++;
            r++;
        }
        else if (r1[l] < r2[r])
        {
            ans.push_back(r1[l]);
            l++;
        }
        else
        {
            ans.push_back(r2[r]);
            r++;
        }
    }

    while (l < r1.size())
    {
        ans.push_back(r1[l]);
        l++;
    }

    while (r < r2.size())
    {
        ans.push_back(r2[r]);
        r++;
    }

    return ans;
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    Node *root2 = new Node(6);
    root2->left = new Node(7);
    root2->right = new Node(8);
    root2->left->left = new Node(9);
    root2->left->right = new Node(10);
    vector<int> ans = merge(root1, root2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}