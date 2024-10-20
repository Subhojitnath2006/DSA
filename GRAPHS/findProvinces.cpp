// calculate the no of provinces in a graph
//A province is a group of directly or indirectly connected cities and no other cities outside of the group.
//You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
#include <bits/stdc++.h>
using namespace std;
void findDFS(int node, vector<int> adjLS[], vector<int> &vis)
{
    vis[node] = 1;

    for (auto it : adjLS[node])
    {
        if (!vis[it])
        {
            findDFS(it, adjLS, vis);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    // convert adjacency matrix into adjacency list
    vector<int> adjLS[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                adjLS[i].push_back(j);
                adjLS[j].push_back(i);
            }
        }
    }

    vector<int> vis(n, 0);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            count++;
            findDFS(i, adjLS, vis);
        }
    }
    return count;
}
int main()
{
    int n;
    cout << "Enter the no of vertices:" << endl;
    cin >> n;
    vector<vector<int>> isConnected(n, vector<int>(n, 0));
    cout << "Enter the matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> isConnected[i][j];
        }
    }
    cout << "No of provinces are: " << findCircleNum(isConnected) << endl;
}