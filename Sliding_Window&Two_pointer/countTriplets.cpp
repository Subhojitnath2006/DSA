#include <bits/stdc++.h>
using namespace std;
int countTriplets(vector<int> &arr, int target)
{
    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == target)
            {
                cnt++;
                int temp = j + 1;
                while (temp < k && arr[temp] == arr[temp - 1])
                {
                    cnt++;
                    temp++;
                }
                k--;
            }
            else if (sum > target)
                k--;
            else
                j++;
        }
    }

    return cnt;
}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countTriplets(arr, target);
}