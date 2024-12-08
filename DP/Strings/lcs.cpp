#include <bits/stdc++.h>
using namespace std;
int func(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (s[ind1] == t[ind2])
    {
        return dp[ind1][ind2] = 1 + func(ind1 - 1, ind2 - 1, s, t, dp);
    }
    return dp[ind1][ind2] = max(func(ind1 - 1, ind2, s, t, dp), func(ind1, ind2 - 1, s, t, dp));
}
int longestCommonSubsequence(string text1, string text2)
{
    int sz1 = text1.size();
    int sz2 = text2.size();
    vector<vector<int>> dp(sz1, vector<int>(sz2, -1));
    return func(sz1 - 1, sz2 - 1, text1, text2, dp);
}
//tabulation technique
int lcs(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i=0;i<=n;i++) dp[i][0]=0;
	for(int j=0;j<=m;j++) dp[0][j]=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][m];
}
//space optimization
int lcs(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<int>prev(m + 1, 0),curr(m + 1, 0);
	for(int j=0;j<=m;j++) prev[j]=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				curr[j]=1+prev[j-1];
			}
			else curr[j]=max(prev[j],curr[j-1]);
		}
        prev=curr;
	}
	return prev[m];
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << longestCommonSubsequence(s, t);
    cout<<lcs(s,t);
    return 0;
}