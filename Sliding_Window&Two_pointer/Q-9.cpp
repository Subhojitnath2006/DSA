//count the number of subarray k no of odd numbers
#include<iostream>
using namespace std;
int countSubarray(int nums[],int goal,int size){
    int l=0,r=0,cnt=0,sum=0;
    while(r<size){
        sum+=nums[r];
        while(sum>goal){
            sum-=nums[l];
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }
    return cnt;
}
int main(){

    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int k;
    cout<<"Enter no of odd numbers: ";
    cin>>k;
    int nums[n];

    for(int i=0;i<n;i++){
        cout<<"Enter the element:";
        cin>>nums[i];
    }

    for(int i=0;i<n;i++){
        nums[i]=nums[i]%2;
    }
    int count=countSubarray(nums,k,n)-countSubarray(nums,k-1,n);
    cout<<"the number of subarray with"<<k<<" no of odd numbers is:"<<count;
}