#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Flood fill algorithm using bfs traversal
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();
    int iniColor = image[sr][sc];

    if (iniColor == color)
        return image;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    ans = image;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    ans[sr][sc] = color;
    vis[sr][sc] = 1;
    q.push({sr, sc});

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if ((nrow >= 0 && nrow < n) && (ncol >= 0 && ncol < m) && !vis[nrow][ncol] && image[nrow][ncol] == iniColor)
            {
                ans[nrow][ncol] = color;
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
    return ans;
}

// flood fill algorithm using dfs traversal
void dfs(vector<vector<int>> &image, int row, int col, int initialColor, vector<vector<int>> &vis, vector<vector<int>> &ans, int dr[], int dc[], int color)
{
    int n = image.size();
    int m = image[0].size();
    vis[row][col] = 1;
    ans[row][col] = color;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        if ((nrow >= 0 && nrow < n) && (ncol >= 0 && ncol < m) && !vis[nrow][ncol] && image[nrow][ncol] == initialColor)
        {
            dfs(image, nrow, ncol, initialColor, vis, ans, dr, dc, color);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                              int newColor)
{
    // Code here
    int n = image.size();
    int m = image[0].size();
    int iniColor = image[sr][sc];

    if (iniColor == newColor)
        return image;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    ans = image;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int dr[] = {0, -1, 0, 1};
    int dc[] = {-1, 0, 1, 0};
    dfs(image, sr, sc, iniColor, vis, ans, dr, dc, newColor);

    return ans;
}
int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    int m;
    cout << "Enter the number of columns: ";
    cin >> m;
    vector<vector<int>> image(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> image[i][j];
        }
    }
    int sr, sc;
    cout << "Enter the source row and column: ";
    cin >> sr >> sc;
    int color;
    cout << "Enter the color: ";
    cin >> color;
    vector<vector<int>> ans = floodFill(image, sr, sc, color);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}