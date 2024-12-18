#include <bits/stdc++.h>
using namespace std;
void mergeArrays(vector<int> &a, vector<int> &b)
{

    int n = a.size();
    int m = b.size();

    int i = n - 1, j = 0;
    while (i >= 0 && j < m)
    {
        if (a[i] > b[j])
        {
            swap(a[i], b[j]);
            i--, j++;
        }
        else
            break;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

void swapIfGreater(vector<int> &a, vector<int> &b, int ind1, int ind2)
{
    if (a[ind1] > b[ind2])
    {
        swap(a[ind1], b[ind2]);
    }
}
void mergeArraysUsingGapMethod(vector<int> &a, vector<int> &b)
{

    int n = a.size();
    int m = b.size();

    int len = (n + m);
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        int left = 0, right = left + gap;
        while (right < len)
        {
            // arr1 and arr2
            if (left < n && right >= n)
            {
                swapIfGreater(a, b, left, right - n);
            }
            // arr2 and arr2
            else if (left >= n)
            {
                swapIfGreater(b, b, left - n, right - n);
            }
            // arr1 and arr1
            else
            {
                swapIfGreater(a, a, left, right);
            }
            left++, right++;
        }
        if (gap == 1)
            break;
        else
            gap = (gap / 2) + (gap % 2);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    mergeArrays(a, b);
    cout << "Array after merging: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << " ";
    }
    mergeArraysUsingGapMethod(a, b);
    cout << "Array after merging: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << " ";
    }
}