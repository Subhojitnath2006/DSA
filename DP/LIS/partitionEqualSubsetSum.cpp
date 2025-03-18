#include <bits/stdc++.h>
using namespace std;
bool func(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTake = func(ind - 1, target, arr, dp);
    bool take = false;
    if (arr[ind] <= target)
    {
        take = func(ind - 1, target - arr[ind], arr, dp);
    }
    return dp[ind][target] = take || notTake;
}

bool isSubsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return func(n - 1, sum, arr, dp);
}
bool equalPartition(vector<int> &arr)
{
    // code here
    int n = arr.size();
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];
    if (totSum % 2 == 1)
        return false;
    else
        return isSubsetSum(arr, totSum / 2);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << equalPartition(arr);
}