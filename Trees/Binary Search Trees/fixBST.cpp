#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}
Node *first, *middle, *last, *prev;

    void inorder(Node* root) {
        if (root == NULL) return;

        inorder(root->left);

        if (prev != nullptr && root->data < prev->data) {
            if (first == nullptr) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root; // Update prev to current node

        inorder(root->right);
    }

    void correctBST(Node* root) {
        first = middle = last = prev = nullptr;

        inorder(root);

        // Swap the values to correct the BST
        if (first && last) {
            swap(first->data, last->data);
        } else if (first && middle) {
            swap(first->data, middle->data);
        }
    }
    int main(){
        Node* root = NULL;
        root = insert(root, 4);
        root = insert(root, 2);
        root = insert(root, 6);
        root = insert(root, 1);
        root = insert(root, 3);
        root = insert(root, 5);
        root = insert(root, 7);
        correctBST(root);
        return 0;
    }