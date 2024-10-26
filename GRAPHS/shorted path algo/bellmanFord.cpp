#include <bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    // Code here
    vector<int> dist(V, 1e8);
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // do the nth iteration to check wheather the garph has negative cycle or not
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
        {
            return {-1};
        }
    }
    return dist;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(wt);
        edges.push_back(temp);
    }
    int src;
    cin >> src;
    vector<int> ans = bellmanFord(n, edges, src);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}