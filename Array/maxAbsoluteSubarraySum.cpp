#include<bits/stdc++.h>
using namespace std;
int maxSubarraySum(vector<int>&arr){
    int n=arr.size();
    int res = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < n; i++) {
        if(maxEnding+arr[i]>arr[i]){
            maxEnding+=arr[i];
        }
        else maxEnding=arr[i];
        res=max(res,maxEnding);
    }
    return res;
}
int minSubarraySum(vector<int>&arr){
    int n=arr.size();
    int minEnding = INT_MAX;
    int res = INT_MAX;
    for (int i=0; i<n; i++)
    {
        if (minEnding > 0)
            minEnding = arr[i];   
        else
            minEnding += arr[i];
        res = min(res, minEnding);            
    }
    return res;
}
int maxAbsoluteSum(vector<int>& nums) {
    return max(maxSubarraySum(nums),abs(minSubarraySum(nums)));
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<maxAbsoluteSum(arr);
}