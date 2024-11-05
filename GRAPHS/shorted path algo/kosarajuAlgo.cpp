#include <bits/stdc++.h>
using namespace std;
void sortGraph(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            sortGraph(it, adj, vis, st);
        }
    }
    st.push(node);
}

void dfs(int node, vector<vector<int>> &adjT, vector<int> &vis)
{
    vis[node] = 1;

    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs(it, adjT, vis);
        }
    }
}

// Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<vector<int>> &adj)
{
    // Step 1: Perform DFS and fill the stack
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
            sortGraph(i, adj, vis, st);
    }

    // Step 2: Transpose the graph
    vector<vector<int>> adjT(V); // Initialize adjT with V elements
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    // Step 3: Process nodes in reverse order
    int cntScc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cntScc++;
            dfs(node, adjT, vis);
        }
    }
    return cntScc;
}
int main()
{
    int v;
    cin >> v;
    vector<vector<int>> adj;
    for (int i = 0; i < v; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    cout << kosaraju(v, adj);
    return 0;
}