#include <bits/stdc++.h>
using namespace std;

//next smaller element
vector<int> findnse(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
            nse[i] = st.top();
        st.push(i);
    }
    return nse;
}

//next greater element
vector<int> findnge(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nge(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
            nge[i] = st.top();
        st.push(i);
    }
    return nge;
}

//previous smaller & equal element
vector<int> findpsee(vector<int> &arr)
{
    int n = arr.size();
    vector<int> psee(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        if (!st.empty())
            psee[i] = st.top();
        st.push(i);
    }
    return psee;
}

//previous greater & equal element
vector<int> findpgee(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pgee(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            st.pop();
        }
        if (!st.empty())
            pgee[i] = st.top();
        st.push(i);
    }
    return pgee;
}

//sum of subarray minimums
int subarrayMinimum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse = findnse(arr);
    vector<int> psee = findpsee(arr);
    long long total = 0;
    int mod = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        long long left = i - psee[i];
        long long right = nse[i] - i;
        total = (total + left * right % mod * arr[i]) % mod;
    }
    return total;
}

//sum of subarray maximums
int subarrayMaximum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nge = findnge(arr);
    vector<int> pgee = findpgee(arr);
    long long total = 0;
    int mod = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        long long left = i - pgee[i];
        long long right = nge[i] - i;
        total = (total + left * right % mod * arr[i]) % mod;
    }
    return total;
}

int subarrayRanges(vector<int> &arr)
{
    int mod = 1e9 + 7;
    long long ans = subarrayMaximum(arr) - subarrayMinimum(arr);
    if (ans < 0)
        ans += mod;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << subarrayRanges(arr) << endl;
}