// distance of nearest cell having 1
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> nearest(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                vis[i][j] = 1;
                // dist[i][j]=0;
                q.push({{i, j}, 0});
            }
        }
    }
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dis = q.front().second;
        q.pop();

        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && !vis[nrow][ncol])
            {
                q.push({{nrow, ncol}, dis + 1});
                dist[nrow][ncol] = dis + 1;
                vis[nrow][ncol] = 1;
            }
        }
    }
    return dist;
}
int main()
{
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> ans = nearest(grid);
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