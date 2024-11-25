#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &arr)
{
    // code here
    int n = arr.size();
    int pivot = -1;
    // find the pivot index
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            pivot = i;
            break;
        }
    }
    // if povot index is -1 the the given permutation is the last permutation the our required ans is the first permutation
    if (pivot == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }
    // find the rightmost elemnt greater than pivot ans swap both of them
    for (int i = n - 1; i > pivot; i--)
    {
        if (arr[i] > arr[pivot])
        {
            swap(arr[pivot], arr[i]);
            break;
        }
    }
    // reverse all the elements from pivot+1 to the end
    reverse(arr.begin() + pivot + 1, arr.end());
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
    nextPermutation(arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}