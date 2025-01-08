#include <bits/stdc++.h>
using namespace std;
int countTriangles(vector<int> &arr)
{
    // code here
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int cnt = 0;
    for (int i = n - 1; i >= 2; i--)
    {
        int target = arr[i];
        int start = 0, end = i - 1;
        while (start < end)
        {
            int sum = arr[start] + arr[end];
            if (sum > target)
            {
                cnt += (end - start);
                end--;
            }
            else
                start++;
        }
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countTriangles(arr) << endl;
}