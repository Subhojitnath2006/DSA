#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
} Node;
Node *reverseList(Node *head)
{
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *addTwoLists(Node *num1, Node *num2)
{
    // Reverse the input lists
    num1 = reverseList(num1);
    num2 = reverseList(num2);

    int carry = 0;
    Node *dummy = new Node(0); // Dummy node to simplify result list management
    Node *ans = dummy;         // Pointer to build the result list

    // Traverse both lists and add their values
    while (num1 || num2 || carry)
    {
        int sum = carry; // Start with the carry

        if (num1)
        {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2)
        {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;               // Update carry
        ans->next = new Node(sum % 10); // Create a new node for the current digit
        ans = ans->next;                // Move to the next node in the result list
    }

    // Reverse the result list to restore the original order
    Node *result = reverseList(dummy->next);

    // Free the dummy node
    delete dummy;
    while (result->data == 0)
        result = result->next;
    return result;
}
int main()
{
    Node *head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(3);

    Node *head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);
    Node *result = addTwoLists(head1, head2);
    while (result->data == 0)
        result = result->next;
    while (result != NULL)
    {
        cout << result->data << " ";
        return 0;
    }