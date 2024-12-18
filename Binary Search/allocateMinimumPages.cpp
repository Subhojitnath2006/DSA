#include <bits/stdc++.h>
using namespace std;
bool canDistribute(vector<int> &arr, int pages, int students)
{
    int n = arr.size();
    int cntStudents = 1;
    int curPages = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > pages)
        {
            return false;
        }
        if (curPages + arr[i] > pages)
        {
            cntStudents++;
            curPages = arr[i];
            if (cntStudents > students)
            {
                return false;
            }
        }
        else
        {
            curPages += arr[i];
        }
    }
    return true;
}

int findPages(vector<int> &arr, int k)
{
    int n = arr.size();
    if (k > n)
        return -1;

    int sum = 0;
    int maxPages = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxPages = max(maxPages, arr[i]);
    }

    int low = maxPages;
    int high = sum;
    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canDistribute(arr, mid, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findPages(arr, k) << endl;
    return 0;
}