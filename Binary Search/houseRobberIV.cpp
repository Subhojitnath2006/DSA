#include <bits/stdc++.h>
using namespace std;
bool canRob(int cap, vector<int> &nums, int k)
{
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= cap)
        {
            cnt++;
            i++;
        }
        if (cnt >= k)
            return true;
    }
    return false;
}

int minCapability(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = 1, high = INT_MIN;

    for (int num : nums)
        high = max(high, num);

    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canRob(mid, nums, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << minCapability(nums, k) << endl;
    return 0;
}