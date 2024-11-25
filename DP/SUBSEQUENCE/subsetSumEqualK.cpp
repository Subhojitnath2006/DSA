#include <bits/stdc++.h>
using namespace std;
// recursion and memoization
bool func(int ind, vector<int> &arr, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return (arr[0] == target);
    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool take = false;
    if (target >= arr[ind])
    {
        take = func(ind - 1, arr, target - arr[ind], dp);
    }
    bool notTake = func(ind - 1, arr, target, dp);
    return dp[ind][target] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(1e3 + 1, vector<int>(1e3 + 1, -1));
    return func(n - 1, arr, k, dp);
}

// tabulation technique
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

//space optimization

bool isSubsetSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<bool>prev(target + 1, false), curr(target + 1, false);

    prev[0] = curr[0]=true;
    if (arr[0] <= target)
        prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int k = 1; k <= target; k++)
        {
            bool notTake = prev[k];
            bool take = false;
            if (arr[ind] <= k)
                take = prev[k - arr[ind]];
            curr[k] = take || notTake;
        }
        prev=curr;
    }

    return prev[target];
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
    cout << subsetSumToK(n, k, arr) << endl;
}