#include <bits/stdc++.h>
using namespace std;
// recursive method
int func(int ind, vector<int> &nums)
{
    if (ind == 0)
    {
        return nums[0];
    }
    if (ind < 0)
    {
        return 0;
    }
    int pick = nums[ind] + func(ind - 2, nums);
    int notPick = 0 + func(ind - 1, nums);
    return max(pick, notPick);
}

// memoization
int func2(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
    {
        return nums[0];
    }
    if (ind < 0)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int pick = nums[ind] + func2(ind - 2, nums, dp);
    int notPick = 0 + func2(ind - 1, nums, dp);
    return dp[ind] = max(pick, notPick);
}
// tabulation and space optimization
int f(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
        {
            pick += prev2;
        }
        int notPick = prev;
        int curi = max(pick, notPick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
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
    cout << func(n - 1, nums) << endl;
    vector<int> dp(n, -1);
    cout << func2(n - 1, nums, dp) << endl;

    cout << f(nums) << endl;
}