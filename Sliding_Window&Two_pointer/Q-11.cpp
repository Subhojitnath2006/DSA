//Minimum window substring

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cout<<"Enter a string:";
    getline(cin,str);
    string t;
    cout<<"Enter the substring:";
    getline(cin,t);
    
    int l=0,r=0,minLen=INT_MAX,sIndex=-1,cnt=0;
    int hash[256]={0};

    for(int i=0;i<t.size();i++){
        hash[t[i]]++;
    }
    while(r<str.size()){
        if(hash[str[r]]>0) {
            cnt=cnt+1;
            hash[str[r]]--;
        }
        while(cnt==t.size()){
            if((r-l+1)<minLen){
                minLen=r-l+1;
                sIndex=l;
            }
            hash[str[l]]--;
            if(hash[str[l]]>0) cnt=cnt+1;
        }
        r=r+1;
    }
    if(sIndex==-1) cout<<"No substring found!!!";
    else cout<<"The minimum window substring is:"<<str.substr(sIndex,minLen);
}