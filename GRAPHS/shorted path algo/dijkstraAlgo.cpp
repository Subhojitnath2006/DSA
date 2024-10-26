// implement dijkstra algorith using priority queue
#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    // Code here
    int v = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int dist[v];

    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    pq.push({0, src});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            int edgeWt = it.second;
            int adjNode = it.first;
            if (wt + edgeWt < dist[adjNode])
            {
                dist[adjNode] = wt + edgeWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    vector<int> ans(v, -1);
    for (int i = 0; i < v; i++)
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
    int v, e;
    cin >> v >> e;
    vector<vector<pair<int, int>>> adj(v);
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    vector<int> ans = dijkstra(adj, 0);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}