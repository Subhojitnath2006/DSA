#include <bits/stdc++.h>
using namespace std;
bool canConstruct(string s, int k)
{
    if (s.size() < k)
        return false;
    map<char, int> mpp;
    for (int i = 0; i < s.size(); i++)
        mpp[s[i]]++;
    int oddCount = 0;
    for (auto it : mpp)
    {
        if (it.second % 2 == 1)
            oddCount++;
    }
    if (oddCount > k)
        return false;
    else
        return true;
}
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << canConstruct(s, k);
}