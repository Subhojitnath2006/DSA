#include <bits/stdc++.h>
using namespace std;

// check if a graph is bipartite or not using bfs traversal
bool check(int start, int V, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                q.push(it);
                color[it] = !color[node];
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int V, vector<int> adj[])
{
    // Code here
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (check(i, V, adj, color) == false)
                return false;
        }
    }
    return true;
}

// check if a graph is bipartite or not using dfs traversal
bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &graph)
{
    color[node] = col;
    for (auto it : graph[node])
    {
        if (color[it] == -1)
        {
            if (dfs(it, !col, color, graph) == false)
                return false;
        }
        else if (color[it] == col)
        {
            return false;
        }
    }
    return true;
}
bool isBipartiteUsingDFS(vector<vector<int>> &graph)
{
    int v = graph.size();
    vector<int> color(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            if (dfs(i, 0, color, graph) == false)
                return false;
        }
    }
    return true;
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
        adj[v].push_back(u);
    }
    cout << isBipartite(n, adj);

    int r, c;
    cout << "Enter no of rows and columns : ";
    cin >> r >> c;
    vector<vector<int>> graph(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> graph[i][j];
        }
    }
    cout << isBipartiteUsingDFS(graph);
    return 0;
}