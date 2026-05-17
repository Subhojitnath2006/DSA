// rolling hash in an array
//
#include <bits/stdc++.h>
using namespace std;
vector<long long> rollingHashArray(const vector<int> &arr, int k)
{
    if (arr.size() < k)
        return {};

    long long base = 257;
    long long mod = 1000000007;

    long long highest_pow = 1;
    for (int i = 0; i < k - 1; ++i)
    {
        highest_pow = (highest_pow * base) % mod;
    }

    vector<long long> hashes;
    long long current_hash = 0;

    for (int i = 0; i < k; ++i)
    {
        current_hash = (current_hash * base + arr[i]) % mod;
    }
    hashes.push_back(current_hash);

    for (size_t i = k; i < arr.size(); ++i)
    {
        int leaving_element = arr[i - k];
        int entering_element = arr[i];

        current_hash =
            (current_hash - (leaving_element * highest_pow) % mod + mod) %
            mod;
        current_hash = (current_hash * base + entering_element) % mod;

        hashes.push_back(current_hash);
    }

    return hashes;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<long long> result = rollingHashArray(arr, k);
    for (long long hash : result)
    {
        cout << hash << " ";
    }
    cout << endl;

    return 0;
}