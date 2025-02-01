#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end()); // Sort the array to apply the sliding window approach
    long long total = 0; // Total difference within the window
    int left = 0;        // Left pointer of the sliding window
    int maxFreq = 0;     // Maximum frequency
    
    for (int right = 0; right < nums.size(); ++right) {
        total += nums[right]; // Add the current number to the total
        
        // If the current window is not valid, shrink it
        while ((long long)(nums[right] * (right - left + 1)) - total > k) {
            total -= nums[left];
            ++left;
        }
        
        // Update the maximum frequency
        maxFreq = max(maxFreq, right - left + 1);
    }
    
    return maxFreq;
}

    int main(){
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        cout<<maxFrequency(nums,k);
    }