#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "No of buskets you can use: ";
    cin >> k;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter the element: ";
        cin >> arr[i];
    }
    int l=0,r=0,maxLen=0;
    map<int,int>mpp;
    while(r<n){
        mpp[arr[r]]++;
        if(mpp.size()>k){
            mpp[arr[l]]--;
            if(mpp[arr[l]]==0) mpp.erase(arr[l]);
            l++;
        }
        if(mpp.size()<=k){
            maxLen=max(maxLen,r-l+1);
        }
        r++;
    }
    cout<<"Maximum fruits you can collect is:"<<maxLen;
    
    }