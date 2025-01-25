#include <bits/stdc++.h>
using namespace std;
int func(int ind, int buy, int cnt, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    int n = prices.size();
    if (ind == n || cnt == 0)
        return 0;
    if (dp[ind][buy][cnt] != -1)
        return dp[ind][buy][cnt];
    if (buy)
    {
        return dp[ind][buy][cnt] = max(-prices[ind] + func(ind + 1, 0, cnt, prices, dp), func(ind + 1, 1, cnt, prices, dp));
    }
    return dp[ind][buy][cnt] = max(prices[ind] + func(ind + 1, 1, cnt - 1, prices, dp), func(ind + 1, 0, cnt, prices, dp));
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return func(0, 1, 2, prices, dp);
}
int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout << maxProfit(prices) << endl;
}