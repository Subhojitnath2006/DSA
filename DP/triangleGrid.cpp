#include <bits/stdc++.h>
using namespace std;
// Memoization method
int func(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return triangle[n - 1][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = triangle[i][j] + func(i + 1, j, n, triangle, dp);
    int diagonal = triangle[i][j] + func(i + 1, j + 1, n, triangle, dp);
    return dp[i][j] = min(down, diagonal);
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return func(0, 0, n, triangle, dp);
}

// space optimized
int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> front(n);
    for (int j = 0; j < n; j++)
    {
        front[j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> cur(i + 1);
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + front[j];
            int diag = triangle[i][j] + front[j + 1];
            cur[j] = min(down, diag);
        }
        front = cur;
    }
    return front[0];
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> triangle(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> triangle[i][j];
        }
    }
    cout << minimumPathSum(triangle, n);
    cout<<minimumTotal(triangle);
    return 0;
}