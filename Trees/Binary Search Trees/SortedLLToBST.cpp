//convert a sorted linked list into BST

#include <bits/stdc++.h>
using namespace std;
struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
};
class Solution {
  public:
  vector<int> LLtoVector(LNode* head) {
    vector<int> ans;
    LNode* temp = head;
    while (temp) {
        ans.push_back(temp->data);
        temp = temp->next;
    }
    return ans;
}

TNode* createBST(vector<int>& ans, int low, int high) {
    if (low > high) {
        return nullptr;
    }
    int mid;
    if((low+high+1)%2==0) mid = ((low+high)/2)+1;
    else mid = ((low+high)/2);
    
    TNode* root = new TNode(ans[mid]);

    root->left = createBST(ans, low, mid - 1);
    root->right = createBST(ans, mid + 1, high);

    return root;
}

TNode* sortedListToBST(LNode* head) {
    vector<int> ans = LLtoVector(head);
    return createBST(ans, 0, ans.size() - 1);
}
};

int main(){
    
}