#include <bits/stdc++.h>
using namespace std;
// recursion and memoization
int func(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
        return N * price[0];
    if (dp[ind][N] != -1)
        return dp[ind][N];
    int notTake = func(ind - 1, N, price, dp);
    int take = -1e8;
    if (ind + 1 <= N)
        take = price[ind] + func(ind, N - (ind + 1), price, dp);

    return dp[ind][N] = max(take, notTake);
}

int cutRod(vector<int> &price)
{
    int sz = price.size();
    vector<vector<int>> dp(sz, vector<int>(sz + 1, -1));
    return func(sz - 1, sz, price, dp);
}

// tabulation technique
int cutRod(vector<int> &price, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N + 1, 0));
    for (int i = 0; i <= N; i++)
        dp[0][i] = i * price[0];

    for (int ind = 1; ind < N; ind++)
    {
        for (int l = 0; l <= N; l++)
        {
            int notTake = dp[ind - 1][l];
            int take = -1e8;
            if (ind + 1 <= l)
                take = price[ind] + dp[ind][l - (ind + 1)];
            dp[ind][l] = max(take, notTake);
        }
    }

    return dp[N - 1][N];
}
int main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    cout << cutRod(price);
    cout << cutRod(price, n);
}