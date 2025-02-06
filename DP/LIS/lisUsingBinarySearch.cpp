#include<bits/stdc++.h>
using namespace std;
int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>temp;
        temp.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>temp.back()){
                temp.push_back(arr[i]);
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
                temp[ind]=arr[i];
            }
        }
        return temp.size();
    }
    int main(){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<lis(arr)<<endl;
    }