#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            }
            else
            {
                if (ind + 2 < n)
                {
                    dp[ind][buy] = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
                }
                else
                    dp[ind][buy] = max(prices[ind], dp[ind + 1][0]);
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
    cout << maxProfit(prices) << endl;
}