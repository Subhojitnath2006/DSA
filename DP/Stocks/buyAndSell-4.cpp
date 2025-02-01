#include<bits/stdc++.h>
using namespace std;
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int cnt=2*k-1;cnt>=0;cnt--){
            if(cnt%2==0){
                dp[ind][cnt]=max(-prices[ind]+dp[ind+1][cnt+1],dp[ind+1][cnt]);
            }
            else dp[ind][cnt]=max(prices[ind]+dp[ind+1][cnt+1],dp[ind+1][cnt]);
        }
    }
    return dp[0][0];
}
//space optimization
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<int>prev(2*k+1,0);
    vector<int>curr(2*k+1,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int cnt=2*k-1;cnt>=0;cnt--){
            if(cnt%2==0){
                curr[cnt]=max(-prices[ind]+prev[cnt+1],prev[cnt]);
            }
            else curr[cnt]=max(prices[ind]+prev[cnt+1],prev[cnt]);
        }
        prev=curr;
    }
    return prev[0];
}

int main(){
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++) cin>>prices[i];
    int k;
    cin>>k;
    cout<<maximumProfit(prices,n,k)<<endl;
}