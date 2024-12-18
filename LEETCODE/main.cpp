#include<bits/stdc++.h>
using namespace std;
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();

    if (n < k) return -1; // Not enough elements to form a subarray of size divisible by k

    long long sum = 0;
    long long maxSum = LLONG_MIN;

    // Initialize the first subarray of size k
    for (int i = 0; i < k; i++) sum += nums[i];
    maxSum = sum;

    int l = 0;
    for (int r = k; r < n; r++) {
        sum += nums[r]; // Extend the window to include nums[r]

        // Check if the window size is divisible by k
        if ((r - l + 1) % k == 0) {
            maxSum = max(maxSum, sum);
        } else {
            // If not divisible, shrink the window from the left
            while (l <= r && (r - l + 1) % k != 0) {
                sum -= nums[l];
                l++;
            }

            // Check again after shrinking
            if ((r - l + 1) % k == 0) {
                maxSum = max(maxSum, sum);
            }
        }
    }

    return maxSum;
}

    int main(){
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        cout<<maxSubarraySum(nums,k);
    }
// #include<bits/stdc++.h>
// using namespace std;

// long long maxSubarraySum(vector<int>& nums, int k) {
//     int n = nums.size();

//     if (n < k) return -1; // Not enough elements for a subarray of size divisible by k

//     long long sum = 0;
//     long long maxSum = LLONG_MIN;

//     int l = 0;
//     for (int r = 0; r < n; r++) {
//         sum += nums[r]; // Add the current element to the sum

//         // Check if the current window size is divisible by k
//         if ((r - l + 1) % k == 0) {
//             maxSum = max(maxSum, sum);
//         }

//         // Shrink the window from the left if the size is not divisible by k
//         while (l <= r && (r - l + 1) % k != 0) {
//             sum -= nums[l];
//             l++;
//         }
//     }

//     return maxSum;
// }

// int main() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> nums(n);
//     for (int i = 0; i < n; i++) cin >> nums[i];
//     cout << maxSubarraySum(nums, k) << endl;
//     return 0;
// }