#include <bits/stdc++.h>
using namespace std;
int minimumSumSubarray(vector<int> &arr, int l, int r)
{
    int n = arr.size();
    int minSum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if ((j - i + 1) >= l && (j - i + 1) <= r && sum > 0)
            {
                minSum = min(minSum, sum);
            }
        }
    }
    if (minSum == INT_MAX)
        return -1;
    else
        return minSum;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int l, r;
    cin >> l >> r;
    cout << minimumSumSubarray(nums, l, r);
}