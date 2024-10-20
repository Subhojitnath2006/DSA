// check wheather a cycle is present in a directed graph or not using dfs traversal

#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, vis, pathVis, adj) == true)
                return true;
        }
        else if (pathVis[it])
            return true;
    }
    pathVis[node] = 0;
    return false;
}
bool isCyclic(int V, vector<vector<int>> adj)
{
    // code here
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            if (dfs(i, vis, pathVis, adj) == true)
                return true;
        }
    }
    return false;
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
    }
    cout << isCyclic(n, adj);
    return 0;
}