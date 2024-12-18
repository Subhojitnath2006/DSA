#include <bits/stdc++.h>
using namespace std;
int func(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{
    // base case
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];
    if (str1[i] == str2[j])
        return dp[i][j] = func(i - 1, j - 1, str1, str2, dp);
    return dp[i][j] = min(1 + func(i - 1, j, str1, str2, dp), min(1 + func(i, j - 1, str1, str2, dp), 1 + func(i - 1, j - 1, str1, str2, dp)));
}
int editDistance(string str1, string str2)
{
    // base case
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return func(n - 1, m - 1, str1, str2, dp);
}
// tabulation
int minDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 1; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(1 + dp[i - 1][j], min(1 + dp[i][j - 1], 1 + dp[i - 1][j - 1]));
        }
    }
    return dp[n][m];
}
// space optimization
int minDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (int j = 1; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        cur[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                cur[j] = prev[j - 1];
            else
                cur[j] = min(1 + prev[j], min(1 + cur[j - 1], 1 + prev[j - 1]));
        }
        prev = cur;
    }
    return prev[m];
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << editDistance(str1, str2);
    cout << endl;
    cout << minDistance(str1, str2);
}