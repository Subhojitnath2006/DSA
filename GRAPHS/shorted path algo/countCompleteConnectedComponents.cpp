#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &edges, vector<int> &vis, int &cntNodes, int &degreeSum)
{
    vis[node] = true;
    cntNodes++;
    degreeSum += edges[node].size();
    for (auto &it : edges[node])
    {
        if (!vis[it])
        {
            dfs(it, edges, vis, cntNodes, degreeSum);
        }
    }
}
int countCompleteComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(n);
    for (auto &it : edges)
    {
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    int ans = 0;
    vector<int> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == true)
            continue;
        int cntNodes = 0;
        int degreeSum = 0;
        dfs(i, graph, vis, cntNodes, degreeSum);
        if (cntNodes * (cntNodes - 1) == degreeSum)
            ans++;
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }
    cout << countCompleteComponents(n, edges);
}