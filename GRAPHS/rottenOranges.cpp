// calculate the minimum time required to rot all oranges using bfs traversal
#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
        }
    }
    int time = 0;
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        q.pop();

        time = max(time, t);
        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2)
            {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && grid[i][j] == 1)
                return -1;
        }
    }
    return time;
}
int main()
{
    int n, m;
    cout << "Enter the number of rows and columns : ";
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << "Minimum time required to rot all oranges : " << orangesRotting(grid);
    return 0;
}