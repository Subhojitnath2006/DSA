#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<vector>
using namespace std;
int main(){
    //input some data and store them in a file

    vector<int>arr;
    cout<<"Enter the data:";
    for(int i=0;i<5;i++){
        
        cin>>arr[i];
    }

    //open the file
    ofstream fout;
    fout.open("hello.txt");
    fout<<"Original data\n";
    for(int i=0;i<5;i++){
        fout<<arr[i]<<" ";
    }

    fout<<"\nSorted data\n";

    sort(arr.begin(),arr.end());

    for(int i=0;i<5;i++){
        fout<<arr[i]<<" ";
    }
    fout.close();
}