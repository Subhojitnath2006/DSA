#include <bits/stdc++.h>
using namespace std;
void shortestDistance(vector<vector<int>> &mat)
{
    // Code here
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == -1)
                mat[i][j] = 1e9;
        }
    }
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
            }
        }
    }
    // check for negative cycle
    for (int i = 0; i < n; i++)
    {
        if (mat[i][i] < 0)
            return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1e9)
                mat[i][j] = -1;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        mat[u][v] = wt;
        mat[v][u] = wt;
    }
    shortestDistance(mat);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}