#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *reverseList(struct Node *head)
{
    // code here
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp != NULL)
    {
        struct Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
int main()
{
    Node *head = new Node();
    head->data = 1;
    head->next = NULL;
    Node *temp = head;
    for (int i = 2; i <= 10; i++)
    {
        Node *new_node = new Node();
        new_node->data = i;
        new_node->next = temp;
        temp = new_node;
    }
    head = reverseList(head);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}