#include <bits/stdc++.h>
using namespace std;
int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
{
    // code here
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> dist(rows, vector<int>(columns, 1e9));
    dist[0][0] = 0;
    pq.push({0, {0, 0}});

    int dr[] = {0, -1, 0, 1};
    int dc[] = {-1, 0, 1, 0};
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;

        if (r == rows - 1 && c == columns - 1)
            return dis;
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + dr[i];
            int ncol = c + dc[i];

            if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < columns)
            {
                int newEffort = max(abs(heights[r][c] - heights[nrow][ncol]), dis);
                if (newEffort < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = newEffort;
                    pq.push({newEffort, {nrow, ncol}});
                }
            }
        }
    }
    return 0;
}
int main()
{
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<int>> heights(rows, vector<int>(columns));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> heights[i][j];
        }
    }
    cout << MinimumEffort(rows, columns, heights);
    return 0;
}