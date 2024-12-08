#include<bits/stdc++.h>
using namespace std;
int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=0;
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi;
    }
    int main(){
        string s,t;
        cin>>s>>t;
        cout<<longestCommonSubstr(s,t)<<endl;
        return 0;
    }