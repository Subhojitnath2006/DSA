#include <bits/stdc++.h>
using namespace std;
bool possible(int height, vector<int> &arr, int k, int w)
{
    int n = arr.size();
    vector<long long> temp(n);
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];

    vector<long long> diff(n + 1, 0);
    long long operations = 0;
    long long currAdd = 0;

    for (int i = 0; i < n; i++)
    {
        currAdd += diff[i];

        if (temp[i] + currAdd < height)
        {
            long long need = height - (temp[i] + currAdd);
            operations += need;

            if (operations > k)
                return false;

            currAdd += need;
            if (i + w < n)
                diff[i + w] -= need;
        }
    }

    return true;
}

int maxMinHeight(vector<int> &arr, int k, int w)
{
    int n = arr.size();

    int low = 1;
    int high = *max_element(arr.begin(), arr.end()) + k;

    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (possible(mid, arr, k, w))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}
int main()
{
    int n, k, w;
    cin >> n >> k >> w;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxMinHeight(arr, k, w);
}