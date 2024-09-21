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

// max path sum
int maxPath(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int left = max(0, maxPath(root->left, maxi));
    int right = max(0, maxPath(root->right, maxi));

    maxi = max(maxi, left + right + root->data);
    return max(left, right) + root->data;
}
int maxPathSum(Node *root)
{
    int maxi = INT_MIN;
    maxPath(root, maxi);
    return maxi;
}

// Lowest common ancestor of two nodes

//time complexity O(n)
//space complexity O(1)
Node *lca(Node *root, int n1, int n2)
{
    // Your code here
    if (root == NULL || root->data == n1 || root->data == n2)
        return root;
    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
}
int main()
{
    cout << "Enter the root node: ";
    Node *root;
    root = create();

    cout << "Maximum path sum: " << maxPathSum(root);

    int n1, n2;
    cout << "Enter two nodes: ";
    cin >> n1 >> n2;
    cout << "Lowest common ancestor: " << lca(root, n1, n2)->data;

    return 0;
}