#include <bits/stdc++.h>
using namespace std;
int perfectSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    if (arr[0] <= target)
        dp[0][arr[0]] = 1;
    if (arr[0] == 0)
        dp[0][0] = 2;

    // Fill the DP table.
    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= target; sum++)
        {
            // Do not pick the current element.
            int notPick = dp[ind - 1][sum];
            // Pick the current element, if valid.
            int pick = 0;
            if (arr[ind] <= sum)
                pick = dp[ind - 1][sum - arr[ind]];

            dp[ind][sum] = (pick + notPick);
        }
    }

    return dp[n - 1][target];
}

// count partitions with difference d
int countPartitions(vector<int> &arr, int d)
{
    // Code here
    int totSum = 0;
    for (auto it : arr)
        totSum += it;
    if (totSum - d < 0 || (totSum - d) % 2)
        return 0;
    return perfectSum(arr, (totSum - d) / 2);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << perfectSum(arr, target) << endl;
    int d;
    cin >> d;
    cout << countPartitions(arr, d) << endl;
}