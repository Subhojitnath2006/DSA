#include <bits/stdc++.h>
using namespace std;
int maxAscendingSum(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    int sum = nums[0];
    int maxSum = nums[0];
    int i = 0, j = 1;
    while (j < n)
    {
        if (nums[j] > nums[j - 1])
        {
            sum += nums[j];
        }
        else
        {
            i = j;
            sum = nums[i];
        }
        maxSum = max(maxSum, sum);
        j++;
    }
    return max(maxSum, sum);
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << maxAscendingSum(nums);
}