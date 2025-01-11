#include <bits/stdc++.h>
using namespace std;
vector<int> subarraySum(vector<int> &arr, int target)
{
    int n = arr.size();
    int i = 0, j = 0;
    int sum = 0;
    vector<int> ans;

    while (j < n)
    {
        sum += arr[j];
        while (sum > target && i <= j)
        {
            sum -= arr[i];
            i++;
        }
        if (sum == target)
        {
            ans.push_back(i + 1);
            ans.push_back(j + 1);
            return ans;
        }
        j++;
    }

    return {-1};
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cin >> target;
    vector<int> ans = subarraySum(arr, target);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}