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
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
{
    // Initialize Disjoint Set for n*m cells
    DisjointSet ds(n * m);
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<int> ans;
    int cnt = 0;

    // Direction arrays for navigating neighbors
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (auto it : operators)
    {
        int row = it[0];
        int col = it[1];

        // If the cell is already an island, just record the current count
        if (vis[row][col] == 1)
        {
            ans.push_back(cnt);
            continue;
        }

        // Mark cell as visited and increment the island count
        vis[row][col] = 1;
        cnt++;

        // Calculate unique node number for current cell
        int nodeNo = row * m + col;

        // Check all four possible directions for neighbors
        for (int i = 0; i < 4; i++)
        {
            int adjR = row + dr[i];
            int adjC = col + dc[i];

            // Check if the neighbor is within bounds and part of an island
            if (adjR >= 0 && adjR < n && adjC >= 0 && adjC < m && vis[adjR][adjC] == 1)
            {
                int adjNodeNo = adjR * m + adjC;

                // If the current cell and adjacent cell belong to different components, unite them
                if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo))
                {
                    cnt--; // Merging two islands reduces the count by 1
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }

        // Record the current count of islands
        ans.push_back(cnt);
    }

    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> operators(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> operators[i][0] >> operators[i][1];
    }
    vector<int> ans = numOfIslands(n, m, operators);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}