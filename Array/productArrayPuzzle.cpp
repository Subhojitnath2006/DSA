#include <bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int> &arr)
{
    // code here
    int n = arr.size();
    vector<int> res(n);
    int prodExcept0 = 1;
    int cnt0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            prodExcept0 *= arr[i];
        if (arr[i] == 0)
            cnt0++;
    }
    if (cnt0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            res[i] = prodExcept0 / arr[i];
        }
    }
    else if (cnt0 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                res[i] = prodExcept0;
            else
                res[i] = 0;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            res[i] = 0;
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> res = productExceptSelf(arr);
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
}