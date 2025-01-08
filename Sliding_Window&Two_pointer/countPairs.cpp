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

    //the array contains duplicate elements
    int countPairsDuplicate(vector<int> &arr, int target) {
        // Complete the function
        int n=arr.size();
        int cnt=0;
        int start=0,end=n-1;
        while(start<end){
            int sum=arr[start]+arr[end];
            if(sum==target) {
                int countStart = 1, countEnd = 1;
                while (start < end && arr[start] == arr[start + 1]) {
                    countStart++;
                    start++;
                }
                while (start < end && arr[end] == arr[end - 1]) {
                    countEnd++;
                    end--;
                }
                if (start == end) {
                    cnt += (countStart * (countStart - 1)) / 2;
                } else {
                    cnt += countStart * countEnd;
                }
                start++;
                end--;
            }
            else if(sum>target) end--;
            else start++;
        }
        return cnt;
    }
    int main(){
        int n;
        cin>>n;
        vector<int>arr;
        for(int i=0;i<n;i++) cin>>arr[i];
        int target;
        cin>>target;
        cout<<countPairs(arr,target);

        cout<<endl;
        cout<<countPairsDuplicate(arr,target);
    }