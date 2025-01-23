#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
} Node;
Node *sortedMerge(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    Node *dNode = new Node(-1);
    Node *temp = dNode;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            temp->next = temp1;
            temp = temp1;
            temp1 = temp1->next;
        }
        else
        {
            temp->next = temp2;
            temp = temp2;
            temp2 = temp2->next;
        }
    }
    if (temp1)
        temp->next = temp1;
    else
        temp->next = temp2;
    return dNode->next;
}
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    Node *head1 = new Node(0), *head2 = new Node(0);
    Node *temp1 = head1, *temp2 = head2;
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        temp1->next = new Node(x);
        temp1 = temp1->next;
    }
    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        temp2->next = new Node(x);
        temp2 = temp2->next;
    }
    head1 = head1->next;
    head2 = head2->next;
    Node *head3 = sortedMerge(head1, head2);
    while (head3)
    {
        cout << head3->data << " ";
        head3 = head3->next;
    }
}