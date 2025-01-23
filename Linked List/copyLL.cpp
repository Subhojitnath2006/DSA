#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *random;
    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};
// brute force approach
Node *cloneLinkedList(Node *head)
{
    // Write your code here
    Node *temp = head;
    map<Node *, Node *> mpp;
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        Node *copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp - temp->next;
    }
    return mpp[head];
}

// optimal approach
Node *cloneLinkedList(Node *head)
{
    // Write your code here
    // insert copy node in between
    Node *temp = head;
    Node *copyNode = NULL;
    while (temp != NULL)
    {
        copyNode = new Node(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
    copyNode->next = NULL;
    // connect rendom pinters
    temp = head;
    while (temp != NULL)
    {
        if (temp->random)
            temp->next->random = temp->random->next;
        else
            temp->next->random = NULL;
        temp = temp->next->next;
    }
    // connect next pointers
    temp = head;
    Node *dNode = new Node(-1);
    Node *res = dNode;
    while (temp != NULL)
    {
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }
    return dNode->next;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next->next->next->next->next;
    head->random = head->next->next->next->next;
    Node *ans = cloneLinkedList(head);
    while (ans != NULL)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
}