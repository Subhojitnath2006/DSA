#include<bits/stdc++.h>
using namespace std;
void lcs(string s, string t,int n,int m,vector<vector<int>> &dp) {
    
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
}
string printLCS(string s,string t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    lcs(s,t,n,m,dp);
    int i=n,j=m;
    string ans = "";
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans.push_back(s[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<printLCS(s,t)<<endl;
    return 0;
}