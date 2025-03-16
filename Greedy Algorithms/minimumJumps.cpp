#include<bits/stdc++.h>
using namespace std;
int minJumps(vector<int> &arr) {
    int n = arr.size();
    if(n==1) return 0;
    if(arr[0]==0) return -1;
    int jumps=1,jumpsEnd=arr[0],maxReach=arr[0];
    for(int i=1;i<n;i++){
        if(i==n-1) return jumps;
        maxReach=max(maxReach,i+arr[i]);
        if(jumpsEnd==i){
            if(i==maxReach) return -1;
            jumps++;
            jumpsEnd=maxReach;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<minJumps(arr);
}