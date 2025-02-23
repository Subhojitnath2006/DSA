#include <bits/stdc++.h>
using namespace std;
int maxLength(string &s)
{
    stack<int> st; // Change stack type to int
    st.push(-1);   // Push initial index -1
    int maxLen = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (!st.empty())
            {
                maxLen = max(maxLen, i - st.top());
            }
            else
            {
                st.push(i);
            }
        }
    }
    return maxLen;
}
int main()
{
    string s; // Example input
    cin >> s;
    cout << maxLength(s) << endl;
    return 0;
}