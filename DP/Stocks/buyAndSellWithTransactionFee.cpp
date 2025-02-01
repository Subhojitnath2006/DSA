#include <bits/stdc++.h>
using namespace std;
int func(int ind, int buy, int n, vector<int> &prices, vector<vector<int>> &dp, int fee)
{
    if (ind == n)
        return 0;
    int profit = INT_MIN;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    if (buy)
    {
        profit = max(-prices[ind] + func(ind + 1, 0, n, prices, dp, fee), func(ind + 1, 1, n, prices, dp, fee));
    }
    else
    {
        profit = max(prices[ind] - fee + func(ind + 1, 1, n, prices, dp, fee), func(ind + 1, 0, n, prices, dp, fee));
    }
    return dp[ind][buy] = profit;
}

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return func(0, 1, n, prices, dp, fee);
}

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                dp[ind][buy] = max(-prices[ind] + dp[ind][0], dp[ind + 1][1]);
            }
            else
            {
                dp[ind][buy] = max(prices[ind] - fee + dp[ind + 1][1], dp[ind + 1][0]);
            }
        }
    }
    return dp[0][1];
}
int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    int fee;
    cin >> fee;
    cout << maxProfit(prices, fee) << endl;
}