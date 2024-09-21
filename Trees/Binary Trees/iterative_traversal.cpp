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
vector<int> preOrderIterative(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
        ans.push_back(temp->data);
        st.pop();
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }
    return ans;
}
vector<int> postOrderIterative(Node *root)
{
    // code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
        ans.push_back(temp->data);
        st.pop();

        if (temp->left)
            st.push(temp->left);
        if (temp->right)
            st.push(temp->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// construct a tree from inorder ans pre order traversal
int findPos(int in[], int target, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == target)
            return i;
    }
    return -1;
}
Node *Tree(int in[], int pre[], int Instart, int Inend, int index)
{
    if (Instart > Inend)
        return NULL;
    Node *root = new Node(pre[index]);
    int pos = findPos(in, pre[index], Instart, Inend);
    root->left = Tree(in, pre, Instart, pos - 1, index + 1);
    root->right = Tree(in, pre, pos + 1, Inend, index + (pos - Instart) + 1);
    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    // Code here
    return Tree(in, pre, 0, n - 1, 0);
}

// construct a tree from inorder and post order traversal
int findPos(int in[], int target, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == target)
            return i;
    }
    return -1;
}
Node *Tree(int in[], int post[], int Instart, int Inend, int index)
{
    if (Instart > Inend)
        return NULL;
    Node *root = new Node(post[index]);
    int pos = findPos(in, post[index], Instart, Inend);
    root->right = Tree(in, post, pos + 1, Inend, index - 1);
    root->left = Tree(in, post, Instart, pos - 1, index - (Inend - pos) - 1);

    return root;
}
// Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int n, int in[], int post[])
{
    // Your code here
    return Tree(in, post, 0, n - 1, n - 1);
}
int main()
{
    cout << "Enter the root node: ";
    Node *root;

    root = create();

    cout << "Pre Order Iterative Traversal: ";
    vector<int> ans1 = preOrderIterative(root);
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " ";
    }

    cout << endl;
    cout << "Post Order Iterative Traversal: ";
    vector<int> ans2 = postOrderIterative(root);

    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }

    int n;
    cout << "Enter size:";
    cin >> n;
    int in[n], pre[n];
    cout << "Enter elements of inorder traversal:";

    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    cout << "Enter elements of preorder traversal:";

    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    Node *root1 = buildTree(in, pre, n);
}