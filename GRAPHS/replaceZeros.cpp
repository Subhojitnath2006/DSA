#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, int n, int m, vector<vector<char>> &mat, vector<vector<int>> &vis)
{
    vis[row][col] = 1;
    int dr[] = {0, -1, 0, 1};
    int dc[] = {-1, 0, 1, 0};
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
        {
            dfs(nrow, ncol, n, m, mat, vis);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // First row and last row
    for (int j = 0; j < m; j++)
    {
        if (!vis[0][j] && mat[0][j] == 'O')
        {
            dfs(0, j, n, m, mat, vis);
        }
        if (!vis[n - 1][j] && mat[n - 1][j] == 'O')
        {
            dfs(n - 1, j, n, m, mat, vis);
        }
    }

    // First column and last column
    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && mat[i][0] == 'O')
        {
            dfs(i, 0, n, m, mat, vis);
        }
        if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
        {
            dfs(i, m - 1, n, m, mat, vis);
        }
    }
    vector<vector<char>> ans(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 1)
            {
                ans[i][j] = 'O';
            }
            else
            {
                ans[i][j] = 'X';
            }
        }
    }

    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<vector<char>> ans = fill(n, m, mat);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}