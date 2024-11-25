// leetcode-->3254
#include <bits/stdc++.h>
using namespace std;
vector<int> resultsArray(vector<int> &arr, int k)
{
    vector<int> ans;
    int n = arr.size();

    for (int i = 0; i <= n - k; i++)
    {
        int maxi = arr[i];
        bool valid = true;
        for (int j = i; j < i + k - 1; j++)
        {
            if (j + 1 >= n || arr[j] >= arr[j + 1] || abs(arr[j] - arr[j + 1]) > 1)
            {
                valid = false;
                break;
            }
            maxi = max(maxi, arr[j + 1]);
        }
        if (valid)
        {
            ans.push_back(maxi);
        }
        else
        {
            ans.push_back(-1);
        }
    }

    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = resultsArray(arr, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}