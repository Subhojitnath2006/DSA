#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void inorder(TreeNode *root, vector<int> &temp)
{
    if (root == NULL)
        return;

    inorder(root->left, temp);
    temp.push_back(root->val);
    inorder(root->right, temp);
}
TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = sortedArrayToBST(nums, start, mid - 1);

    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}
TreeNode *balanceBST(TreeNode *root)
{
    TreeNode *temp = root;
    vector<int> nodes;
    inorder(temp, nodes);

    TreeNode *res = sortedArrayToBST(nodes, 0, nodes.size() - 1);
    return res;
}

int main(){
    

}