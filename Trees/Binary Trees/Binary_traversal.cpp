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
// Time complexity O(no of nodes)
// space complexity O(n) in worst case otherwise o(height of tree)
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}
// Level order traversal
// Time complexity O(n)
// space complexity O(n)
vector<int> levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    vector<int> ans;
    Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return ans;
}

// vertical order traversal
// Time complexity O(n)
// space complexity O(n)
void find(Node *root, int pos, int &left, int &right)
{
    if (root == NULL)
        return;
    left = min(pos, left);
    right = max(pos, right);
    find(root->left, pos - 1, left, right);
    find(root->right, pos + 1, left, right); // Fixed the assignment here
}

vector<int> verticalOrder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    int l = 0, r = 0;
    find(root, 0, l, r);

    vector<vector<int>> positive(r + 1);
    vector<vector<int>> negative(abs(l) + 1);
    queue<Node *> q;
    queue<int> index;

    q.push(root);
    index.push(0);

    while (!q.empty())
    {
        Node *temp = q.front();
        int pos = index.front();
        q.pop();
        index.pop();

        if (pos >= 0)
            positive[pos].push_back(temp->data);
        else
            negative[abs(pos)].push_back(temp->data); // Use -pos to access negative indices

        if (temp->left)
        {
            q.push(temp->left);
            index.push(pos - 1);
        }
        if (temp->right)
        {
            q.push(temp->right);
            index.push(pos + 1);
        }
    }

    // Populate ans from negative indices to positive indices
    for (int i = negative.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < negative[i].size(); j++)
        {
            ans.push_back(negative[i][j]);
        }
    }
    for (int i = 0; i < positive.size(); i++)
    {
        for (int j = 0; j < positive[i].size(); j++)
        {
            ans.push_back(positive[i][j]);
        }
    }

    return ans;
}

// Diagonal traversal
//  This function finds the maximum diagonal position (l) in the binary tree
void findL(Node *root, int pos, int &l)
{
    if (root == NULL)
        return;

    // Update l with the maximum diagonal position encountered so far
    l = max(pos, l);

    // Recurse on left and right subtrees
    findL(root->left, pos + 1, l);
    findL(root->right, pos, l); // Note: pos remains unchanged for the right subtree
}

// This function populates a 2D vector (temp) with nodes from the same diagonal
void findDig(Node *root, int pos, vector<vector<int>> &temp)
{
    if (root == NULL)
        return;

    // Add the current node's data to the appropriate diagonal position
    temp[pos].push_back(root->data);

    // Recurse on left and right subtrees
    findDig(root->left, pos + 1, temp);
    findDig(root->right, pos, temp); // Note: pos remains unchanged for the right subtree
}

// This function returns a vector containing nodes in diagonal order
vector<int> diagonal(Node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    int l = 0; // Initialize the maximum diagonal position

    // Find the maximum diagonal position (l)
    findL(root, 0, l);

    // Create a 2D vector to store nodes by diagonal position
    vector<vector<int>> temp(l + 1);

    // Populate the temp vector with nodes from the same diagonal
    findDig(root, 0, temp);

    // Flatten the temp vector into a 1D vector (ans)
    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = 0; j < temp[i].size(); j++)
        {
            ans.push_back(temp[i][j]);
        }
    }

    return ans;
}

// Boundary traversal
// Time complexity O(n)
// space complexity O(n)
void leftBoundary(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
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

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    leaf(root->left, ans);
    leaf(root->right, ans);
}

void rightBoundary(Node *root, vector<int> &ans)
{

    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right)
    {
        rightBoundary(root->right, ans);
    }
    else
        rightBoundary(root->left, ans);

    ans.push_back(root->data);
}
vector<int> boundary(Node *root)
{
    // Your code here
    vector<int> ans;

    //insert the root node
    ans.push_back(root->data);

    //insert the left boundary nodes except leaf nodes
    leftBoundary(root->left, ans);

    //insert leaf nodes
    if (root->left || root->right)
    {
        leaf(root, ans);
    }

    //insert the right boundary nodes except leaf nodes
    rightBoundary(root->right, ans);

    return ans;
}
int main()
{
    cout << "Enter the root node: ";
    Node *root;
    root = create();
    cout << "Pre Order Traversal:";
    preorder(root);
    cout << endl;
    cout << "In Order Traversal:";
    inorder(root);
    cout << endl;
    cout << "Post Order Traversal:";
    postorder(root);
    cout << endl;
    cout << "Level order Traversal:";
    vector<int> ans = levelOrderTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
    cout << "Vertical order Traversal:";
    vector<int> ans2 = verticalOrder(root);
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }

    cout << endl;
    cout << "Diagonal Traversal:";
    vector<int> ans3 = diagonal(root);
    for (int i = 0; i < ans3.size(); i++)
    {
        cout << ans3[i] << " ";
    }

    cout << endl;
    cout << "Boundary Traversal:";
    vector<int> ans4 = boundary(root);
    for (int i = 0; i < ans4.size(); i++)
    {
        cout << ans4[i] << " ";
    }
    return 0;
}