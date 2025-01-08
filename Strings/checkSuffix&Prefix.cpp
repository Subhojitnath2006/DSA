#include <bits/stdc++.h>
using namespace std;
bool isPrefixAndSuffix(const string &s1, const string &s2)
{
    if (s1.size() > s2.size())
        return false;
    // Check prefix
    for (size_t i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
    }
    // Check suffix
    size_t startIndex = s2.size() - s1.size();
    for (size_t i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[startIndex + i])
        {
            return false;
        }
    }
    return true;
}
int countPrefixSuffixPairs(vector<string> &words)
{
    int n = words.size();
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isPrefixAndSuffix(words[i], words[j]) == true)
                cnt++;
        }
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    vector<string> words;
    for (int i = 0; i < n; i++)
        cin >> words[i];
    cout << countPrefixSuffixPairs(words);
}