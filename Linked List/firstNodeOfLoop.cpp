#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node *findFirstNode(Node *head)
{
    // your code here
    Node *temp = head;
    map<Node *, int> mpp;
    Node *ans = NULL;
    while (temp != NULL)
    {
        if (mpp[temp] == 0)
        {
            mpp[temp] = 1;
        }
        else
        {
            ans = temp;
            break;
        }
        temp = temp->next;
    }
    return ans;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;
    cout << findFirstNode(head)->data;
}