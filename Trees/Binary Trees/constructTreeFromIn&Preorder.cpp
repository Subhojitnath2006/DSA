#include<bits/stdc++.h>
using namespace std;
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}Node;
Node* tree(vector<int>&inorder,vector<int>&preorder,int inStart,int inEnd,int index){
        if(inStart>inEnd) return NULL;
        Node* root=new Node(preorder[index]);
        int pos=findPos(inorder,preorder[index],inStart,inEnd);
        root->left=tree(inorder,preorder,inStart,pos-1,index+1);
        root->right=tree(inorder,preorder,pos+1,inEnd,index+pos-inStart+1);
        return root;
    }
    int findPos(vector<int>&inorder,int target,int start,int end){
        for(int i=start;i<=end;i++){
            if(inorder[i]==target) return i;
        }
        return -1;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        return tree(inorder,preorder,0,inorder.size()-1,0);
    }
    void inorder(Node* root){
        if(root==NULL) return;
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
    int main(){
        int n;
        cin>>n;
        vector<int>inorder(n),preorder(n);
        for(int i=0;i<n;i++) cin>>inorder[i];
        for(int i=0;i<n;i++) cin>>preorder[i];
        Node* root=buildTree(inorder,preorder);
    }