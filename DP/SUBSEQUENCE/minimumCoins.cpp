#include<bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    for(int t=0;t<=amount;t++){
        if(t%coins[0]==0) dp[0][t]=t/coins[0];
        else dp[0][t]=1e8;
    }
    for(int ind=1;ind<n;ind++){
        for(int t=0;t<=amount;t++){
            int notTake=dp[ind-1][t];
            int take=INT_MAX;
            if(coins[ind]<=t){
                take=1+dp[ind][t-coins[ind]];
            }
            dp[ind][t]=min(take,notTake);
        }
    }
    if(dp[n-1][amount]>=1e8) return -1;
    else return dp[n-1][amount];
}
//space optimization
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int>prev(amount+1,0),curr(amount+1,0);
    for(int t=0;t<=amount;t++){
        if(t%coins[0]==0) prev[t]=t/coins[0];
        else prev[t]=1e8;
    }
    for(int ind=1;ind<n;ind++){
        for(int t=0;t<=amount;t++){
            int notTake=prev[t];
            int take=INT_MAX;
            if(coins[ind]<=t){
                take=1+prev[t-coins[ind]];
            }
            curr[t]=min(take,notTake);
        }
        prev=curr;
    }
    if(prev[amount]>=1e8) return -1;
    else return prev[amount];
}
int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    int amount;
    cin>>amount;
    cout<<coinChange(coins,amount);
}
