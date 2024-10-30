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
vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    // code here
    DisjointSet ds(n);
    unordered_map<string, int> mapMail;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            string mail = accounts[i][j];
            if (mapMail.find(mail) == mapMail.end())
            {
                mapMail[mail] = i;
            }
            else
            {
                ds.unionBySize(i, mapMail[mail]);
            }
        }
    }
    vector<vector<string>> mergedMail(n);
    for (auto it : mapMail)
    {
        string mail = it.first;
        int node = ds.findUPar(it.second);
        mergedMail[node].push_back(mail);
    }
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
        if (mergedMail[i].empty())
            continue;
        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        temp.insert(temp.end(), mergedMail[i].begin(), mergedMail[i].end());
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<string>> accounts(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            string mail;
            cin >> mail;
            accounts[i].push_back(mail);
        }
    }
    accountsMerge(accounts);
    return 0;
}