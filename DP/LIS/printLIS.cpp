#include <bits/stdc++.h>
using namespace std;
vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
{
    vector<int> dp(n, 1);
    vector<int> hash(n);
    int maxi = 1, lastIndex = 0;

    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        for (int prev = 0; prev < ind; prev++)
        {
            if (arr[prev] < arr[ind] && dp[prev] + 1 > dp[ind])
            {
                dp[ind] = dp[prev] + 1;
                hash[ind] = prev;
            }
        }
        if (dp[ind] > maxi)
        {
            maxi = dp[ind];
            lastIndex = ind;
        }
    }
    vector<int> ans;
    while (hash[lastIndex] != lastIndex)
    {
        ans.push_back(arr[lastIndex]);
        lastIndex = hash[lastIndex];
    }
    ans.push_back(arr[lastIndex]);

    reverse(ans.begin(), ans.end());
    return ans;
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
    vector<int> ans = longestIncreasingSubsequence(n, arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}