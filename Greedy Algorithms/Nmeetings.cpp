#include <bits/stdc++.h>
using namespace std;
struct data
{
    int start, end, pos;
};
static bool comp(data val1, data val2)
{
    return val1.end < val2.end;
}
int maxMeetings(vector<int> start, vector<int> end)
{
    // Your code here
    int n = start.size();
    data arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i + 1;
    }
    sort(arr, arr + n, comp);
    int cnt = 1;
    int freeTime = arr[0].end;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].start > freeTime)
        {
            cnt++;
            freeTime = arr[i].end;
        }
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++)
        cin >> start[i];
    for (int i = 0; i < n; i++)
        cin >> end[i];
    cout << maxMeetings(start, end);
    return 0;
}