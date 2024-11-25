#include <bits/stdc++.h>
using namespace std;
bool isSubsetSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // Base cases
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= target)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int k = 1; k <= target; k++)
        {
            bool notTake = dp[ind - 1][k];
            bool take = false;
            if (arr[ind] <= k)
                take = dp[ind - 1][k - arr[ind]];
            dp[ind][k] = take || notTake;
        }
    }

    return dp[n - 1][target];
}
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    if (sum % 2 == 1)
        return false;
    else
        return isSubsetSum(nums, sum / 2);
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
    cout << canPartition(nums);
}