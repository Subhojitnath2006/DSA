#include <bits/stdc++.h>
using namespace std;
long long solve(vector<int> &bt)
{
    // code here
    int n = bt.size();
    sort(bt.begin(), bt.end());
    vector<int> time(n, 0);

    for (int i = 1; i < n; i++)
    {
        time[i] = time[i - 1] + bt[i - 1];
    }

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += time[i];
    }
    return sum / (long long)n;
}
int main()
{
    int n;
    cin >> n;
    vector<int> bt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bt[i];
    }
    cout << solve(bt) << endl;
    return 0;
}