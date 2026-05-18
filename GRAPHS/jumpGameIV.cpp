#include <bits/stdc++.h>
using namespace std;
int minJumps(vector<int> &arr)
{
    int n = arr.size();

    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]].push_back(i);
    }

    queue<int> q;
    vector<int> vis(n, 0);

    q.push(0);
    vis[0] = 1;

    int steps = 0;

    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            int node = q.front();
            q.pop();

            if (node == n - 1)
                return steps;

            if (node - 1 >= 0 && !vis[node - 1])
            {
                vis[node - 1] = 1;
                q.push(node - 1);
            }

            if (node + 1 < n && !vis[node + 1])
            {
                vis[node + 1] = 1;
                q.push(node + 1);
            }

            for (int nxt : mp[arr[node]])
            {
                if (!vis[nxt])
                {
                    vis[nxt] = 1;
                    q.push(nxt);
                }
            }
            mp[arr[node]].clear();
        }
        steps++;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minJumps(arr);
}