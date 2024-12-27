#include<bits/stdc++.h>
using namespace std;
int countPairs(vector<int>& arr, int target) {
        unordered_map<int, int> freq;
        int count = 0;
    
        for (int num : arr) {
            int complement = target - num;
            if (freq[complement] > 0) {
                count += freq[complement];
            }
            freq[num]++;
        }
    
        return count;
    }
    int main(){
        int n;
        cin>>n;
        vector<int>arr;
        for(int i=0;i<n;i++) cin>>arr[i];
        int target;
        cin>>target;
        cout<<countPairs(arr,target);
    }