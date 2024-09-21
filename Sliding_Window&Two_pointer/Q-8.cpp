//Binary subarrays with sum/count subarrays sum equals k
//no of subarray==goal--->(no of subarray<=goal)-(no of subarray<=goal-1)
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
    int goal;
    cout<<"Enter goal to achieve: ";
    cin>>goal;
    int nums[n];

    for(int i=0;i<n;i++){
        cout<<"Enter the element:";
        cin>>nums[i];
    }

    int count=countSubarray(nums,goal,n)-countSubarray(nums,goal-1,n);
    cout<<"No of subarray with sum equals to "<<goal<<" is:"<<count;

}
