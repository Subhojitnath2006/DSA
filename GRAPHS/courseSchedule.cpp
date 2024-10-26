#include <bits/stdc++.h>
using namespace std;
bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
{
    // Code here
    vector<vector<int>> adj(N);

    for (auto it : prerequisites)
    {
        adj[it.first].push_back(it.second);
    }

    int indegree[N] = {0};
    for (int i = 0; i < N; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if (topo.size() == N)
        return true;
    else
        return false;
}

vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites)
{
    // code here
    vector<vector<int>> adj(N);

    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }

    int indegree[N] = {0};
    for (int i = 0; i < N; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if (topo.size() == N)
        return topo;
    else
        return {};
}

int main()
{
    int n;
    cout << "Enter no of tasks:";
    cin >> n;
    int m;
    cout << "Enter array size:";
    cin >> m;

    vector<vector<int>> prerequisites(m, vector<int>(2));

    for (int i = 0; i < m; i++)
    {
        cin >> prerequisites[i][0];
        cin >> prerequisites[i][1];
    }
    vector<int> ans = findOrder(n, m, prerequisites);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}