#include<bits/stdc++.h>
using namespace std;
bool func(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
   //base case
   if(i<0 && j<0) return true;
   if(i<0 && j>=0) return false;
   if(j<0 && i>=0){
      for(int ind=0;ind<=i;ind++){
         if(s1[ind]!='*') return false;
      }
      return true;
   }
   if(dp[i][j]!=-1) return dp[i][j];
   if(s1[i]==s2[j] || s1[i]=='?'){
      return dp[i][j]=func(i-1,j-1,s1,s2,dp);
   }
   else if(s1[i]=='*'){
      return dp[i][j]=func(i-1,j,s1,s2,dp) || func(i,j-1,s1,s2,dp);
   }
   else return false;
}
bool wildcardMatching(string pattern, string text)
{
   int n=pattern.size();
   int m=text.size();
   vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
   return func(n-1,m-1,pattern,text,dp);
}
int main(){
   string s1,s2;
   cin>>s1>>s2;
   cout<<wildcardMatching(s1,s2);
}