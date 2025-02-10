#include<bits/stdc++.h>
using namespace std;
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}Node;
int countPaths(Node* root, int targetSum, int currSum, unordered_map<int, int>& prefixSum) {
    if (root == NULL) return 0;
    
    currSum += root->val;
    int count = prefixSum[currSum - targetSum];
    prefixSum[currSum]++;
    
    count += countPaths(root->left, targetSum, currSum, prefixSum);
    count += countPaths(root->right, targetSum, currSum, prefixSum);
    
    prefixSum[currSum]--;
    
    return count;
}

int sumK(Node* root, int k) {
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;
    return countPaths(root, k, 0, prefixSum);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);
    root->right->right->left = new Node(10);
    root->right->right->right = new Node(11);
    cout<<sumK(root, 12);
    return 0;
}