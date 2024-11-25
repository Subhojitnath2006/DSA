// maximum sum of subarray with distinct integers of length k
#include <bits/stdc++.h>
using namespace std;
long long maximumSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n < k)
        return 0;

    unordered_set<int> window;
    long long sum = 0, maxSum = 0;
    int l = 0;

    for (int r = 0; r < n; r++)
    {
        while (window.count(nums[r]))
        {
            window.erase(nums[l]);
            sum -= nums[l];
            l++;
        }

        window.insert(nums[r]);
        sum += nums[r];

        if (r - l + 1 == k)
        {
            maxSum = max(maxSum, sum);
            window.erase(nums[l]);
            sum -= nums[l];
            l++;
        }
    }

    return maxSum;
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
    int k;
    cin >> k;
    cout << maximumSubarraySum(nums, k);
}