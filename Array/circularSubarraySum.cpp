#include<bits/stdc++.h>
using namespace std;
int maxSubarraySum(vector<int> &arr) {
    int maxSum = INT_MIN, curSum = 0;
    for (int num : arr) {
        curSum += num;
        maxSum = max(maxSum, curSum);
        if (curSum < 0) curSum = 0;
    }
    return maxSum;
}

int minSubarraySum(vector<int> &arr) {
    int minSum = INT_MAX, curSum = 0;
    for (int num : arr) {
        curSum += num;
        minSum = min(minSum, curSum);
        if (curSum > 0) curSum = 0;
    }
    return minSum;
}

int circularSubarraySum(vector<int> &arr) {
    int maxNormalSum = maxSubarraySum(arr);
    
    //if all the elements are negative   
    //return maxNormalSum
    if (maxNormalSum < 0) return maxNormalSum;
    
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int minNormalSum = minSubarraySum(arr);
    int maxCircularSum = totalSum - minNormalSum;

    return max(maxNormalSum, maxCircularSum);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<circularSubarraySum(arr);
}