#include <bits/stdc++.h>
using namespace std;
// maximum pathsum from all the elements of the 1st row to all the elements of the last row
// memoization
int func(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp)
{
    int m = a[0].size();
    if (j < 0 || j >= m)
        return -1e8;
    if (i == 0)
        return a[0][j];

    if (dp[i][j] != -1)
        return dp[i][j];
    int up = a[i][j] + func(i - 1, j, a, dp);
    int ldg = a[i][j] + func(i - 1, j - 1, a, dp);
    int rdg = a[i][j] + func(i - 1, j + 1, a, dp);
    return dp[i][j] = max(up, max(ldg, rdg));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = -1e8;

    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, func(n - 1, j, matrix, dp));
    }
    return maxi;
}
// minimum path sum from all the elements of the 1st row to all the elements of the last row
// tabulation and space optimization
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];
            int ldg = matrix[i][j];
            if (j - 1 >= 0)
                ldg += dp[i - 1][j - 1];
            else
                ldg += 1e8;
            int rdg = matrix[i][j];
            if (j + 1 < m)
                rdg += dp[i - 1][j + 1];
            else
                rdg += 1e8;
            dp[i][j] = min(up, min(ldg, rdg));
        }
    }
    int mini = 1e8;
    for (int j = 0; j < m; j++)
    {
        mini = min(mini, dp[n - 1][j]);
    }
    return mini;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << minFallingPathSum(matrix);
    cout<<getMaxPathSum(matrix);
    return 0;
}