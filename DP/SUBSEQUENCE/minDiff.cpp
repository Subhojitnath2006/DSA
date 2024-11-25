#include<bits/stdc++.h>
using namespace std;
void isSubsetSum(vector<int>& arr, int target, vector<vector<bool>>& dp) {
    int n = arr.size();
    
    // Initialize dp for base cases
    for (int i = 0; i < n; i++) dp[i][0] = true;  // Sum 0 is always achievable
    if (arr[0] <= target) dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++) {
        for (int k = 1; k <= target; k++) {
            bool notTake = dp[ind - 1][k];  // Exclude current element
            bool take = false;
            if (arr[ind] <= k) take = dp[ind - 1][k - arr[ind]];  // Include current element
            dp[ind][k] = take || notTake;  // Final decision
        }
    }
}
int minSubsetSumDifference(vector<int>& nums, int n)
{
    if (n == 0) return 0;  // Handle empty array edge case

    int totSum = 0;
    for (int i = 0; i < n; i++) totSum += nums[i];

    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));
    isSubsetSum(nums, totSum, dp);

    int diff = 1e9;
    for (int i = 0; i <= totSum / 2; i++) {
        if (dp[n - 1][i] == true) {  // Check if sum `i` is achievable
            int s1 = i;
            int s2 = totSum - i;
            diff = min(diff, abs(s2 - s1));  // Minimize difference
        }
    }
    return diff;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<minSubsetSumDifference(nums,n);
}
