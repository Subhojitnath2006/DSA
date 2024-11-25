#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &arr)
{
    // Your Code Here
    int n = arr.size();
    int maxProduct = INT_MIN;

    int prefix = 1, suffix = 1;

    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n - i - 1];
        maxProduct = max(maxProduct, max(prefix, suffix));
    }
    return maxProduct;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxProduct(arr) << endl;
}