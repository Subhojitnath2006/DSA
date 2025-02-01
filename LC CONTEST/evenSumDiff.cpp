#include <bits/stdc++.h>
using namespace std;
int countPartitions(vector<int> &nums)
{
    int n = nums.size();
    int leftSum = 0, rightSum = 0;
    for (int i = 0; i < n; i++)
        rightSum += nums[i];
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        leftSum += nums[i];
        rightSum -= nums[i];
        if (abs(leftSum - rightSum) % 2 == 0)
            cnt++;
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << countPartitions(nums);
}