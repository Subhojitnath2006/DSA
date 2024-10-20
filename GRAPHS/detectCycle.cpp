#include <bits/stdc++.h>
using namespace std;
bool detectCycle(int src, vector<vector<int>> adj, int vis[])
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                vis[adjNode] = 1;
                q.push({adjNode, node});
            }
            else if (parent != adjNode)
            {
                return true;
            }
        }
    }
    return false;
}
// Function to detect cycle in an undirected graph.
bool isCycle(vector<vector<int>> adj)
{
    // Code here
    int v = adj.size();

    int vis[v] = {0};
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (detectCycle(i, adj, vis))
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
        adj[v].push_back(u);
    }
    cout << isCycle(adj);
    return 0;
}