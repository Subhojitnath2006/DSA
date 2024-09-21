//Number of Substrings Containing All Three Characters
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
    int lastSeen[3]={-1,-1,-1};
    
    int cnt=0;
    for(int i=0;i<str.size();i++){
        lastSeen[str[i]-'a']=i;
        cnt = cnt + (1 + std::min(std::min(lastSeen[0], lastSeen[1]), lastSeen[2]));
    }
    cout<<"Number of Substrings Containing All Three Characters: "<<cnt;
}