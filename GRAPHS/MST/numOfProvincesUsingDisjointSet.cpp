#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    // find the ultimate parent
    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    // check wheather 2 nodes belongs from same component or not
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        // if both are already in same component
        if (ulp_u == ulp_v)
        {
            return;
        }
        // if both are not in same component
        // rank of  up of v is greater than that of up of u
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        // rank of  up of u is greater than that of up of v
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        // both have same rank
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        // if both are already in same component
        if (ulp_u == ulp_v)
        {
            return;
        }
        // if both are not in same component
        // size of  up of v is greater than that of up of u
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        // size of  up of u is greater than that of up of v
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int numProvinces(vector<vector<int>> adj, int V)
{
    // code here
    DisjointSet ds(V);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1)
                ds.unionByRank(i, j);
        }
    }
    int cnt = 0;
    for (int i = 0; i < V; i++)
    {
        if (ds.findUPar(i) == i)
            cnt++;
    }
    return cnt;
}
int main()
{
    int v;
    cin >> v;
    vector<vector<int>> adj(v, vector<int>(v, 0));
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> adj[i][j];
        }
    }
    cout << numProvinces(adj, v);
}