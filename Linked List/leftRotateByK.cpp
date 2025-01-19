#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    Node *next;
} Node;
Node *rotate(Node *head, int k)
{
    // Your code here
    Node *temp = head;
    int cnt = 1;
    while (temp->next != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    Node *front = head;
    k = k % cnt;
    while (k > 0)
    {
        Node *t = front;
        front = front->next;
        t->next = NULL;
        temp->next = t;
        temp = temp->next;
        k--;
    }
    return front;
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
    int k;
    cin >> k;
    head = rotate(head, k);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}