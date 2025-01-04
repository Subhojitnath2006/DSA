#include <bits/stdc++.h>
using namespace std;
bool startEndVowel(int ind, vector<string> &words)
{
    string temp = words[ind];
    int sz = temp.size();
    if (sz > 0 && (temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u') &&
        (temp[sz - 1] == 'a' || temp[sz - 1] == 'e' || temp[sz - 1] == 'i' || temp[sz - 1] == 'o' || temp[sz - 1] == 'u'))
        return true;
    else
        return false;
}
vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
{
    int m = words.size();
    vector<int> prefixSum(m + 1, 0);
    for (int i = 0; i < m; i++)
    {
        if (startEndVowel(i, words))
        {
            prefixSum[i + 1] = prefixSum[i] + 1;
        }
        else
        {
            prefixSum[i + 1] = prefixSum[i];
        }
    }
    int n = queries.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        int start = queries[i][0];
        int end = queries[i][1];
        ans[i] = prefixSum[end + 1] - prefixSum[start];
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    int m;
    cin >> m;
    vector<vector<int>> queries(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }
    vector<int> ans = vowelStrings(words, queries);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}