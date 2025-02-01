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

//tabulation technique
int maxProfit(vector<int>& prices)
{
    // Write your code here.
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cnt=1;cnt<=2;cnt++){
                if(buy){
                    dp[ind][buy][cnt]=max(-prices[ind]+dp[ind+1][0][cnt],dp[ind+1][1][cnt]);
                }
                else dp[ind][buy][cnt]=max(prices[ind]+dp[ind+1][1][cnt-1],dp[ind+1][0][cnt]);
            }
        }
    }
    return dp[0][1][2];
}

//space optimization
int maxProfit(vector<int>& prices)
{
    // Write your code here.
    int n=prices.size();
    vector<vector<int>>prev(2,vector<int>(3,0));
    vector<vector<int>>cur(2,vector<int>(3,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cnt=1;cnt<=2;cnt++){
                if(buy){
                    cur[buy][cnt]=max(-prices[ind]+prev[0][cnt],prev[1][cnt]);
                }
                else cur[buy][cnt]=max(prices[ind]+prev[1][cnt-1],prev[0][cnt]);
            }
            prev=cur;
        }
    }
    return prev[1][2];
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