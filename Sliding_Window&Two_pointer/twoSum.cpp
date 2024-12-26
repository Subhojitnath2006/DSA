#include <bits/stdc++.h>
using namespace std;
bool twoSum(vector<int> &arr, int target)
{
    // code here
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1;

    while (i < j)
    {
        if (arr[i] + arr[j] == target)
            return true;
        else if (arr[i] + arr[j] < target)
        {
            i++;
        }
        else
            j--;
    }
    return false;
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
    int target;
    cin >> target;
    cout << twoSum(arr, target);
}