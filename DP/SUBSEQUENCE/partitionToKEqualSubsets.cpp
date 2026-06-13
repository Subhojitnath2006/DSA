// partition an array into k subsets such that subset sums are equal and each element is in one subset only once.
//TC = O(k * 2^n)
//SC = O(n)
#include <bits/stdc++.h>
using namespace std;
bool backtrack(int i, int k, int subsetSum, int target, int n,
               vector<bool> &used, vector<int> &arr)
{
    if (k == 0)
        return true;
    if (subsetSum == target)
    {
        return backtrack(0, k - 1, 0, target, n, used, arr);
    }

    for (int j = i; j < n; j++)
    {
        if (used[j] || subsetSum + arr[j] > target)
            continue;

        used[j] = true;
        if (backtrack(j + 1, k, subsetSum + arr[j], target, n, used, arr) ==
            true)
            return true;
        used[j] = false;
    }
    return false;
}
bool canPartitionKSubsets(vector<int> &arr, int k)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int maxEl = *max_element(arr.begin(), arr.end());
    if ((sum % k != 0) || (maxEl > (sum / k)))
        return false;
    int target = sum / k;

    vector<bool> used(n, false);
    return backtrack(0, k, 0, target, n, used, arr);
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
    cout << canPartitionKSubsets(arr, k) << endl;
    return 0;
}