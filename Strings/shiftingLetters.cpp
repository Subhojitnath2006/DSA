#include <bits/stdc++.h>
using namespace std;
string shiftingLetters(string s, vector<vector<int>> &shifts)
{
    int n = s.size();
    vector<int> shift(n, 0);
    // line sweep algorithm
    for (auto it : shifts)
    {
        if (it[2] == 1)
        { // forward
            shift[it[0]]++;
            if (it[1] + 1 < n)
                shift[it[1] + 1]--;
        }
        else
        { // backward
            shift[it[0]]--;
            if (it[1] + 1 < n)
                shift[it[1] + 1]++;
        }
    }
    // prefix sum
    shift[0] = (shift[0] % 26 + 26) % 26;
    for (int i = 1; i < n; i++)
    {
        shift[i] = (shift[i] + shift[i - 1]) % 26;
        if (shift[i] < 0)
            shift[i] += 26;
    }
    for (int i = 0; i < n; i++)
    {
        s[i] = 'a' + (s[i] - 'a' + shift[i]) % 26;
    }
    return s;
}
int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<vector<int>> shifts(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> shifts[i][0] >> shifts[i][1] >> shifts[i][2];
    }
    cout << shiftingLetters(s, shifts);
}