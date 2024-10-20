#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;
vector<int> bfsOfGraph(vector<vector<int>> &adj)
{
    // Code here
    int maxi = INT_MIN;
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            maxi = max(maxi, adj[i][j]);
        }
    }
    vector<int> vis(maxi, 0);
    vector<int> bfs;
    queue<int> q;

    vis[0] = 1;
    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = bfsOfGraph(adj);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}