#include <bits/stdc++.h>
using namespace std;
int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{
    // Your code here
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (auto it : edges)
    {
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][via] == 1e9 || dist[via][j] == 1e9)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
            }
        }
    }
    int cntMax = n + 1;
    int city = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] <= distanceThreshold)
                count++;
        }
        if (count < cntMax || (count == cntMax && i > city))
        {
            cntMax = count;
            city = i;
        }
    }
    return city;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    int distanceThreshold;
    cin >> distanceThreshold;
    cout << findCity(n, m, edges, distanceThreshold);
    return 0;
}