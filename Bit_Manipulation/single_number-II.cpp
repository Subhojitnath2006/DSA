#include<iostream>
#include<vector>
using namespace std;
int main(){
    // int n;
    // cout<<"Enter the size of the array:";
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cout<<"Enter the element: ";
    //     cin>>arr[i];
    // }
    // int ans=arr[n-1];
    // for(int i=1;i<n;i=i+3){
    //     if(arr[i]!=arr[i-1]){
    //         ans=arr[i-1];
    //     }
    // }

    //another method
    // int ones,twos=0;
    // for(int i=0;i<n;i++){
    //     ones=(ones^arr[i])&(~twos);
    //     twos=(twos^arr[i])&(~ones);
    // }
    //cout<<"The number which present once in the array is:"<<ones;

    int n;
    cin >> n;
    vector<int>arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i=0;i<n;i++){
        int el=arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]==el){
                cout<<el;
                break;
            }
        }
    }
    
}