#include <bits/stdc++.h>
using namespace std;
vector<int> countDistinct(vector<int> &arr, int k)
{
    // code here.
    int n = arr.size();
    map<int, int> mpp;
    for (int i = 0; i < k; i++)
    {
        mpp[arr[i]]++;
    }
    vector<int> ans;
    ans.push_back(mpp.size());
    int first = 0, second = k;
    while (second < n)
    {
        mpp[arr[second]]++;
        mpp[arr[first]]--;
        if (mpp[arr[first]] == 0)
            mpp.erase(arr[first]);
        ans.push_back(mpp.size());
        first++, second++;
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
    vector<int> ans = countDistinct(arr, k);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}