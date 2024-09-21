//Longest Substring With At Most K Distinct Characters
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cout<<"Enter a string:";
    getline(cin,str);
    int  k;
    cout << "No of distinct characters: ";
    cin >> k;

    int l=0,r=0,maxLen=0;
    map<char,int>mpp;
    while(r<str.size()){
        mpp[str[r]]++;
        if(mpp.size()>k){
            mpp[str[l]]--;
            if(mpp[str[l]]==0) mpp.erase(str[l]);
            l++;
        }
        if(mpp.size()<=k){
            maxLen=max(maxLen,r-l+1);
        }
        r++;
    }
    cout<<"Length of Longest Substring With At Most K Distinct Characters:"<<maxLen;
    
    }