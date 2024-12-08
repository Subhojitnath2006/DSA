#include <bits/stdc++.h>
using namespace std;
// memoization
int func(int ind, int target, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target % wt[0] == 0)
            return val[0] * (target / wt[0]);
        else
            return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int notPick = func(ind - 1, target, val, wt, dp);
    int pick = -1e8;
    if (wt[ind] <= target)
        pick = val[ind] + func(ind, target - wt[ind], val, wt, dp);
    return dp[ind][target] = max(pick, notPick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return func(n - 1, w, profit, weight, dp);
}

// tabulation technique
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    for (int t = 0; t <= capacity; t++)
    {
        dp[0][t] = (t / wt[0]) * val[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int t = 0; t <= capacity; t++)
        {
            int notPick = dp[ind - 1][t];
            int pick = -1e8;
            if (wt[ind] <= t)
                pick = val[ind] + dp[ind][t - wt[ind]];
            dp[ind][t] = max(pick, notPick);
        }
    }
    return dp[n - 1][capacity];
}
int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> val(n), wt(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    cout << unboundedKnapsack(n, w, val, wt);
}