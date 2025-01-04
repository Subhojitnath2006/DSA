#include <bits/stdc++.h>
using namespace std;
// count subarray with given sum k
int countSubarrays(vector<int> &arr, int k)
{
    // code here
    int n = arr.size();
    int sum = 0;
    int cnt = 0;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
            cnt++;
        if (mpp.find(sum - k) != mpp.end())
        {
            cnt += mpp[sum - k];
        }
        mpp[sum]++;
    }
    return cnt;
}
// count subarray with given xor k
long subarrayXor(vector<int> &arr, int k)
{
    // code here
    int n = arr.size();
    int xr = 0;
    int cnt = 0;
    unordered_map<int, int> mpp;
    mpp[xr]++;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countSubarrays(arr, k);
    cout<<endl;
    cout << subarrayXor(arr, k);
    return 0;
}