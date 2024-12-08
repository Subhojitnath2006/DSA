#include <bits/stdc++.h>
using namespace std;
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int t = 0; t <= amount; t++)
    {
        if (t % coins[0] == 0)
            dp[0][t] = 1;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int t = 0; t <= amount; t++)
        {
            int notPick = dp[ind - 1][t];
            int pick = 0;
            if (coins[ind] <= t)
                pick = dp[ind][t - coins[ind]];
            dp[ind][t] = pick + notPick;
        }
    }

    return dp[n - 1][amount];
}
int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    int amount;
    cin>>amount;
    cout<<change(amount,coins);
}