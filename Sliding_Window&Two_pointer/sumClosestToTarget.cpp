#include <bits/stdc++.h>
using namespace std;
vector<int> sumClosest(vector<int> &arr, int target)
{
    // code here
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<int> ans;
    if (n == 0)
        return ans;
    int start = 0, end = n - 1;
    int diff = INT_MAX;
    while (start < end)
    {
        int sum = arr[start] + arr[end];
        if (abs(target - sum) < diff)
        {
            diff = min(diff, abs(target - sum));
            ans = {arr[start], arr[end]};
        }
        if (sum < target)
            start++;
        else if (sum > target)
            end--;
        else
            break;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cin >> target;
    vector<int> ans = sumClosest(arr, target);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}