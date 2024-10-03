#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, int d)
{
    if (root == NULL)
    {
        Node *temp = new Node(d);
        return temp;
    }
    else if (d <= root->data)
    {
        root->left = insert(root->left, d);
    }
    else
    {
        root->right = insert(root->right, d);
    }
    return root;
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
// search a node in BST
bool search(Node *root, int x)
{
    // Your code here
    if (root == NULL)
        return 0;
    if (root->data == x)
        return 1;
    if (x < root->data)
        return search(root->left, x);
    else
        return search(root->right, x);
}

// create BST from preorder traversal
Node *createBST(vector<int> &preorder, int &index, int lower, int upper)
{
    if (index == preorder.size() || preorder[index] < lower || preorder[index] > upper)
        return NULL;
    Node *root = new Node(preorder[index++]);

    root->left = createBST(preorder, index, lower, root->data);
    root->right = createBST(preorder, index, root->data, upper);
    return root;
}
Node *bstFromPreorder(vector<int> &preorder)
{
    int index = 0;
    return createBST(preorder, index, INT_MIN, INT_MAX);
}

// construct BST from post order
// Node *constructTreefromPostorder(int post[], int size)
// {
//     // code here
//     int index = size - 1;
//     return createBST(post, index, INT_MIN, INT_MAX);
// }
// Node *createBSTfromPostorder(int post[], int &index, int lower, int upper)
// {
//     if (index < 0 || post[index] < lower || post[index] > upper)
//         return NULL;
//     Node *root = new Node(post[index--]);

//     root->right = createBST(post, index, root->data, upper);
//     root->left = createBST(post, index, lower, root->data);
//     return root;
// }
// lowest common ancestor
Node *LCA(Node *root, int n1, int n2)
{
    // code here
    if (root == NULL)
        return NULL;

    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    else if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    else
        return root;
}
//find common nodes between two BST
vector<int> findCommon(Node* root1, Node* root2) {
    vector<int> ans;
    stack<Node*> s1, s2;

    while (root1) {
        s1.push(root1);
        root1 = root1->left;
    }
    while (root2) {
        s2.push(root2);
        root2 = root2->left;
    }

    while (!s1.empty() && !s2.empty()) {
        if (s1.top()->data == s2.top()->data) {
            ans.push_back(s1.top()->data);
            root1 = s1.top()->right;
            s1.pop();
            root2 = s2.top()->right;
            s2.pop();
        } else if (s1.top()->data < s2.top()->data) {
            root1 = s1.top()->right;
            s1.pop();
        } else {
            root2 = s2.top()->right;
            s2.pop();
        }
        while (root1) {
            s1.push(root1);
            root1 = root1->left;
        }
        while (root2) {
            s2.push(root2);
            root2 = root2->left;
        }
    }

    return ans;
}

int main()
{

    Node *root = NULL;

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int arr[n];
    cout << "Enter the nodes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {

        root = insert(root, arr[i]);
    }
    cout << "Tree created successfully!" << endl;

    inorder(root);

    int target;
    cout << "Enter the target node: ";
    cin >> target;
    if (search(root, target))
        cout << "Target found in BST." << endl;
    else
        cout << "Target not found in BST." << endl;

    vector<int> preorder = {10, 5, 1, 7, 40, 50};
    Node *bst = bstFromPreorder(preorder);
    inorder(bst);

    // vector<int> postorder = {1, 5, 40, 7, 50, 10};
    // Node *bst2 = constructTreefromPostorder(postorder, postorder.size());
    // inorder(bst2);

    int n1, n2;
    cout << "Enter two nodes: ";
    cin >> n1 >> n2;
    Node *lca = LCA(bst, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;

    vector<int> common = findCommon(bst, bst);
    cout << "Common nodes between BSTs: ";
    for (int i = 0; i < common.size(); i++)
    {
        cout << common[i] << " ";
    }
    cout << endl;

    return 0;
}