#include <bits/stdc++.h>
using namespace std;
//time complexity-->O(ElogE)
//space complexity-->O(E)  where E is the no of edges
int spanningTree(int V, vector<vector<int>> adj[])
{
    // Priority queue to store the edges based on their weights in ascending order
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Visited array to keep track of included nodes
    vector<int> vis(V, 0);

    // Starting with node 0 and edge weight 0
    pq.push({0, 0}); //(edgeWeight, adjacentNode)

    // Initialize the visited state of the starting node
    vis[0] = 0;

    // Sum to store the total weight of the minimum spanning tree
    int sum = 0;

    // Loop until the priority queue is empty
    while (!pq.empty())
    {
        // Get the edge with the minimum weight
        auto it = pq.top();
        pq.pop();

        int node = it.second; // The adjacent node
        int wt = it.first;    // The weight of the edge

        // If the node is already visited, skip to the next iteration
        if (vis[node] == 1)
            continue;

        // Mark the node as visited
        vis[node] = 1;

        // Add the weight to the total sum
        sum += wt;

        // Iterate over the adjacent nodes of the current node
        for (auto it : adj[node])
        {
            int adjNode = it[0]; // The adjacent node
            int edW = it[1];     // The weight of the edge

            // If the adjacent node is not visited, add it to the priority queue
            if (!vis[adjNode])
            {
                pq.push({edW, adjNode});
            }
        }
    }

    // Return the total weight of the minimum spanning tree
    return sum;
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << spanningTree(V, adj);
    return 0;
}