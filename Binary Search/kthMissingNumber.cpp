#include <bits/stdc++.h>
using namespace std;
int kthMissing(vector<int> &arr, int k)
{
    // Your code goes here
    int n = arr.size();

    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] - (mid + 1) < k)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return k + low;
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
    cout << kthMissing(arr, k);
}