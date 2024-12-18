#include<bits/stdc++.h>
using namespace std;
bool canWePlace(vector<int>&arr, int dist ,int cows){
        int n=arr.size();
        int cntCows=1;
        int last=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-last>=dist){
                cntCows+=1;
                last=arr[i];
            }
        }
        if(cntCows>=cows) return true;
        else return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];
        int ans=0;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(canWePlace(stalls,mid,k)){
                ans=max(ans,mid);
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
    int main(){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<aggressiveCows(arr,k)<<endl;
        return 0;
    }