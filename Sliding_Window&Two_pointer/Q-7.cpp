//Longest Repeating Character Replacement 
//Number of Substrings Containing All Three Characters
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cout<<"Enter a string:";
    getline(cin,str);
    int  k;
    cout << "No of characters allowed to change: ";
    cin >> k;
    int l=0,r=0,maxLen=0,maxf=0;
    int hash[26]={0};

    maxf=max(maxf,hash[str[r]-'A']);

    while((l+r-1)-maxf>k){
        hash[str[l]-'A']++;
        maxf=0;
        for(int i=0;i<26;i++){
            maxf=max(maxf,hash[i]);
        }
        l++;
    }
    if((l+r-1)<=maxf){
        maxLen=max(maxLen,(r-l+1));
    }
    cout<<"Longest Repeating Character Replacement :"<<maxLen;
}