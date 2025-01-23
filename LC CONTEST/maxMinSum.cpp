#include<bits/stdc++.h>
using namespace std;

long long minMaxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) return 0; // If the array size is smaller than k, no valid subarray exists.

    deque<int> maxDeque, minDeque;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        // Remove elements outside the current window
        if (!maxDeque.empty() && maxDeque.front() < i - k + 1)
            maxDeque.pop_front();
        if (!minDeque.empty() && minDeque.front() < i - k + 1)
            minDeque.pop_front();

        // Add the current element to the deques
        while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[i])
            maxDeque.pop_back();
        maxDeque.push_back(i);

        while (!minDeque.empty() && nums[minDeque.back()] >= nums[i])
            minDeque.pop_back();
        minDeque.push_back(i);

        // Add the sum of max and min values when the window is valid
        if (i >= k - 1) {
            sum += nums[maxDeque.front()] + nums[minDeque.front()];
        }
    }

    return sum;
}
    int main(){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        int k;
        cin>>k;
        cout<<minMaxSubarraySum(nums,k);
    }