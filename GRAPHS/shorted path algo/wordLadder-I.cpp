#include <bits/stdc++.h>
using namespace std;
int ladderLength(string startWord, string targetWord, vector<string> &wordList)
{
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == targetWord)
            return steps;

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                // word exists in set or not
                if (st.find(word) != st.end())
                {
                    q.push({word, steps + 1});
                    st.erase(word);
                }
            }
            word[i] = original;
        }
    }
    return 0;
}
int main()
{
    string startWord, targetWord;
    cin >> startWord >> targetWord;
    int n;
    cin >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++)
        cin >> wordList[i];
    cout << ladderLength(startWord, targetWord, wordList);
}