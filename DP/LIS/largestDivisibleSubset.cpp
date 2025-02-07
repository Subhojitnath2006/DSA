#include<bits/stdc++.h>
using namespace std;
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {}; // Edge case

    sort(nums.begin(), nums.end()); // Sorting is necessary
    vector<int> dp(n, 1), lis(n);
    int lastIndex = 0, maxi = 1;

    for (int i = 0; i < n; i++) lis[i] = i;

    for (int i = 1; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]) {
                dp[i] = dp[prev] + 1;
                lis[i] = prev;
            }
        }
        if (dp[i] > maxi) {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> ans;
    while (lis[lastIndex] != lastIndex) {
        ans.push_back(nums[lastIndex]);
        lastIndex = lis[lastIndex];
    }
    ans.push_back(nums[lastIndex]);

    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<int> ans=largestDivisibleSubset(nums);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}