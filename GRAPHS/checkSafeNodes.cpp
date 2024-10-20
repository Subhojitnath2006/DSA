// check if a node if safe node or not
// a safe node is a node which is connected to a terminal node

#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[], vector<int> &check)
{
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, vis, pathVis, adj, check) == true)
            {
                check[it] == 0;
                return true;
            }
        }
        else if (pathVis[it])
        {
            check[it] = 0;
            return true;
        }
    }
    check[node] = 1;
    pathVis[node] = 0;
    return false;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    // code here
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> check(V, 0);
    vector<int> safeNodes;

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, vis, pathVis, adj, check);
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (check[i] == 1)
        {
            safeNodes.push_back(i);
        }
    }
    return safeNodes;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> safeNodes = eventualSafeNodes(n, adj);
    for (auto it : safeNodes)
    {
        cout << it << " ";
    }
    return 0;
}