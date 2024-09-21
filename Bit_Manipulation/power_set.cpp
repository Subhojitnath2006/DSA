//generate and print all the subsets of an array
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element: ";
        cin>>arr[i];
    }

    int subsets=(1<<n);
    vector<vector<int>>ans;
    
    for(int num=0;num<subsets;num++){
        vector<int>list;
        for(int i=0;i<n;i++){
            //check if the ith bit is set or not
            //if it is set the push the arr[i] into list
            if((num&(1<<i))!=0) list.push_back(arr[i]);
        }
        ans.push_back(list);
    }

    //printing the ans 
    cout<<"All the subsets are:\n";
    for(int i=0;i<ans.size();i++){
        cout<<"[ ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}