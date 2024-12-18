#include <bits/stdc++.h>
using namespace std;
int findArea(vector<vector<int>> &vals)
{
    vector<int> bl, tl, br, tr;
    bl = vals[0];
    tl = vals[1];
    br = vals[2];
    tr = vals[3];
    if (bl[0] != tl[0] || br[0] != tr[0])
        return -1;
    if (bl[1] != br[1] || tl[1] != tr[1])
        return -1;
    return abs(bl[0] - br[0]) * abs(tl[1] - bl[1]);
}
bool hasPoints(vector<vector<int>> &points, vector<vector<int>> &vals)
{
    vector<int> bl, tl, br, tr;
    bl = vals[0];
    tl = vals[1];
    br = vals[2];
    tr = vals[3];
    for (auto it : points)
    {
        if (it == bl || it == tl || it == br || it == tr)
            continue;
        int x = it[0], y = it[1];
        if ((x >= bl[0] && x <= br[0]) && (y >= bl[1] && y <= tl[1]))
            return true;
    }
    return false;
}
int maxRectangleArea(vector<vector<int>> &points)
{
    int ans = -1;
    int n = points.size();
    if (n < 4)
        return ans;
    //generate all the four points
    //1st point
    for (int i = 0; i < n; i++)
    {
        //2nd point
        for (int j = i + 1; j < n; j++)
        {
            //3rd point
            for (int k = j + 1; k < n; k++)
            {
                //4th point
                for (int l = k + 1; l < n; l++)
                {
                    vector<vector<int>> vals = {points[i], points[j], points[k], points[l]};
                    sort(vals.begin(), vals.end());
                    int area = findArea(vals); //calculate area
                    if (area == -1)
                        continue;
                    if (hasPoints(points, vals)) //check if it has other points
                        continue;
                    ans = max(ans, area);
                }
            }
        }
    }
    return ans;
}
//time complexity O(n^5)
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }
    cout << maxRectangleArea(points);
    return 0;
}