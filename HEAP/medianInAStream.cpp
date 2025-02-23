#include <bits/stdc++.h>
using namespace std;
vector<double> getMedian(vector<int> &arr)
{
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
    vector<double> median;

    for (int i = 0; i < arr.size(); i++)
    {
        leftMaxHeap.push(arr[i]);
        rightMinHeap.push(leftMaxHeap.top());
        leftMaxHeap.pop();

        if (leftMaxHeap.size() < rightMinHeap.size())
        {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
        if (leftMaxHeap.size() == rightMinHeap.size())
        {
            median.push_back((leftMaxHeap.top() + rightMinHeap.top()) / 2.0);
        }
        else
        {
            median.push_back(leftMaxHeap.top());
        }
    }

    return median;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<double> ans = getMedian(arr);
    for (auto it : ans)
        cout << it << " ";
}
