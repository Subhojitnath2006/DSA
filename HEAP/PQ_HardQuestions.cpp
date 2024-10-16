#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class solution
{
public:
    priority_queue<int> leftMaxHeap;                             // Max-heap for the lower half of numbers
    priority_queue<int, vector<int>, greater<int>> rightMinHeap; // Min-heap for the upper half of numbers

    // Function to insert an element into the heaps
    void insertHeap(int x)
    {
        if (leftMaxHeap.empty())
        {
            leftMaxHeap.push(x);
            return;
        }
        if (x <= leftMaxHeap.top())
            leftMaxHeap.push(x);
        else
            rightMinHeap.push(x);
        balanceHeaps(); // Ensure both heaps are balanced after insertion
    }

    // Function to balance the heaps
    void balanceHeaps()
    {
        if (rightMinHeap.size() > leftMaxHeap.size())
        {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
        else if (leftMaxHeap.size() > rightMinHeap.size() + 1)
        {
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }
    }

    // Function to return the median
    double getMedian()
    {
        if (leftMaxHeap.size() > rightMinHeap.size())
            return leftMaxHeap.top();
        return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0; // Fixed integer division by 2.0
    }
};

// merge k sorted lists using priority queue
class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
Node *mergeKLists(vector<Node *> &arr)
{
    // Your code here
    priority_queue<Node *, vector<Node *>, Compare> p(arr.begin(), arr.end());

    Node *root = new Node(0);
    Node *tail = root;
    Node *temp;

    while (!p.empty())
    {
        temp = p.top();
        p.pop();
        tail->next = temp;
        tail = tail->next;
        if (temp->next)
            p.push(temp->next);
    }
    return root->next;
}

// print top k frequent elements in an array using priority queue
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }
    priority_queue<pair<int, int>> p;
    pair<int, int> Element;

    for (auto &x : mpp)
    {
        p.push({x.second, x.first});
    }
    vector<int> ans;
    while (k--)
    {
        Element = p.top();
        p.pop();
        ans.push_back(Element.second);
    }
    return ans;
}

// smallest range covering at least one element from each list using priority queue
// leet code-->632
vector<int> smallestRange(vector<vector<int>> &nums)
{

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
    int minimum;
    int maximum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        p.push(make_pair(nums[i][0], make_pair(i, 0)));
        maximum = max(maximum, nums[i][0]);
    }
    minimum = p.top().first;
    vector<int> ans(2);
    ans[0] = minimum;
    ans[1] = maximum;
    pair<int, pair<int, int>> temp;
    int row, col, el;

    while (p.size() == nums.size())
    {
        temp = p.top();
        p.pop();
        row = temp.second.first;
        col = temp.second.second;
        if (col + 1 < nums[row].size())
        {
            col++;
            p.push(make_pair(nums[row][col], make_pair(row, col)));
            maximum = max(maximum, nums[row][col]);
            minimum = p.top().first;
            if (maximum - minimum < ans[1] - ans[0])
            {
                ans[0] = minimum;
                ans[1] = maximum;
            }
        }
    }
    return ans;
}
int main()
{
    solution s;
    s.insertHeap(5);
    s.insertHeap(15);
    s.insertHeap(10);
    s.insertHeap(20);
    cout << s.getMedian() << endl; // Output the median after inserting the first set of numbers
    s.insertHeap(25);
    cout << s.getMedian() << endl; // Output the median after inserting 25
    s.insertHeap(30);
    cout << s.getMedian() << endl; // Output the median after inserting 30
}
