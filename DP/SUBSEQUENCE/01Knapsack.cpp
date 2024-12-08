#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));

	for(int i=weight[0];i<=maxWeight;i++) dp[0][i]=value[0];
	for(int ind=1;ind<n;ind++){
		for(int w=0;w<maxWeight+1;w++){
			int notTake=dp[ind-1][w];
			int take=INT_MIN;
			if(weight[ind]<=w) take=value[ind]+dp[ind-1][w-weight[ind]];
			dp[ind][w]=max(notTake,take);
		}
	}
	return dp[n-1][maxWeight];
}
//space optimization
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<int>prev(maxWeight+1,0),curr(maxWeight+1,0);

	for(int i=weight[0];i<=maxWeight;i++) prev[i]=value[0];
	for(int ind=1;ind<n;ind++){
		for(int w=0;w<maxWeight+1;w++){
			int notTake=prev[w];
			int take=INT_MIN;
			if(weight[ind]<=w) take=value[ind]+prev[w-weight[ind]];
			curr[w]=max(notTake,take);
		}
        prev=curr;
	}
	return prev[maxWeight];
}
int main(){
    int n;
    cin>>n;
    vector<int> weight(n);
    vector<int> value(n);
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    int maxWeight;
    cin>>maxWeight;
    cout<<knapsack(weight,value,n,maxWeight);
}