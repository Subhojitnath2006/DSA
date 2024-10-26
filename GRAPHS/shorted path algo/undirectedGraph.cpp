// shorted path in undirected graph with unit weights

#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    // code here
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dist[N];
    for (int i = 0; i < N; i++)
        dist[i] = INT_MAX;

    queue<pair<int, int>> q;
    q.push({src, 0});
    dist[src] = 0;
    while (!q.empty())
    {
        int node = q.front().first;
        int d = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (d + 1 < dist[it])
            {
                dist[it] = 1 + d;
                q.push({it, d + 1});
            }
        }
    }
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i++)
    {
        if (dist[i] != INT_MAX)
        {
            ans[i] = dist[i];
        }
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    int src;
    cin >> src;
    vector<int> ans = shortestPath(edges, n, m, src);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}