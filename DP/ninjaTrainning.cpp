#include <bits/stdc++.h>
using namespace std;
// tabulation technique
int maximumPoints(vector<vector<int>> &arr, int n)
{
    // Code here
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);
    dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = arr[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n - 1][3];
}
// space optimization
int maximumPoints(vector<vector<int>> &arr, int n)
{
    // Code here
    vector<int> dp(4, -1);
    dp[0] = max(arr[0][1], arr[0][2]);
    dp[1] = max(arr[0][0], arr[0][2]);
    dp[2] = max(arr[0][0], arr[0][1]);
    dp[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, -1);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = arr[day][task] + dp[task];
                    temp[last] = max(temp[last], point);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << maximumPoints(arr, n);
}