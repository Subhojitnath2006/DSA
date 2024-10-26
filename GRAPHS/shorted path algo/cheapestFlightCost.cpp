// find the cheapest flight cost from source to destination with at most k stops
#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;
        if (stops > k)
            continue;

        for (auto iter : adj[node])
        {
            int adjNode = iter.first;
            int edW = iter.second;

            if (cost + edW < dist[adjNode] && stops <= k)
            {
                dist[adjNode] = cost + edW;
                q.push({stops + 1, {adjNode, cost + edW}});
            }
        }
    }
    if (dist[dst] == 1e9)
        return -1;
    else
        return dist[dst];
}
int main()
{
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;
    int m;
    cout << "Enter number of edges : ";
    cin >> m;
    vector<vector<int>> flights(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }
    int src, dst, k;
    cout << "Enter source : ";
    cin >> src;
    cout << "Enter destination : ";
    cin >> dst;
    cout << "Enter number of stops : ";
    cin >> k;
    cout << findCheapestPrice(n, flights, src, dst, k);
    return 0;
}