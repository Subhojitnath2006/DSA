// number of subarray witk k different integers

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int countSubarray(int nums[],int n,int k){
    int l=0,r=0,count=0;
    map<int,int>mpp;
    while(r<n){
        mpp[nums[r]]++;
        while(mpp.size()>k){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0) mpp.erase(nums[l]);
            l++;
        }
        if(mpp.size()<=k){
            count+=(r-l+1);
        }
        r++;
    }
    return count;
}
int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int k;
    cout<<"Enter no of distinct integers: ";
    cin>>k;
    int nums[n];

    for(int i=0;i<n;i++){
        cout<<"Enter the element:";
        cin>>nums[i];
    }

    int cnt=countSubarray(nums,n,k)-countSubarray(nums,n,k-1);
    cout<<"Number of subarray witk "<<k<<" different integers is:"<<cnt;
}