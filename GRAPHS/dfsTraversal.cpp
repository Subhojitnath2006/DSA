#include <bits/stdc++.h>
using namespace std;
void findDFS(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            findDFS(it, adj, vis, ls);
        }
    }
}
// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(vector<vector<int>> &adj)
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
    int start = 0;
    vector<int> ls;
    findDFS(start, adj, vis, ls);
    return ls;
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
    vector<int> ans = dfsOfGraph(adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}