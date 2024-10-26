#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}
// Function to return list containing vertices in Topological order.
vector<int> topologicalSort(vector<vector<int>> &adj)
{
    // Your code here
    int n = adj.size();

    vector<int> vis(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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
    }
    vector<int> ans = topologicalSort(adj);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}