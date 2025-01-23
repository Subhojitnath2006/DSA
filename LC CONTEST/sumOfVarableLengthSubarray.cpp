#include<bits/stdc++.h>
using namespace std;
int subarraySum(vector<int>& nums) {
        int n=nums.size();
        int totSum=0;
        for(int i=0;i<n;i++){
            int start=max(0,i-nums[i]);
            if(i>=start){
                for(int j=start;j<=i;j++) totSum+=nums[j];
            }else{
                for(int j=i;j>start;j--) totSum+=nums[j];
            }
        }
        return totSum;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<subarraySum(nums);
}
