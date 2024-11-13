#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
    int n = arr.size();
    vector<vector<int>> res;
    int i = 0;

    // Add all intervals that end before the new interval starts
    while (i < n && arr[i][1] < newInterval[0]) {
        res.push_back(arr[i]);
        i++;
    }

    // Merge all overlapping intervals with the new interval
    while (i < n && arr[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], arr[i][0]);
        newInterval[1] = max(newInterval[1], arr[i][1]);
        i++;
    }
    // Add the merged interval
    res.push_back(newInterval);

    // Add all intervals that start after the new interval ends
    while (i < n) {
        res.push_back(arr[i]);
        i++;
    }

    return res;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr[i].push_back(x);
        arr[i].push_back(y);
    }
    int x,y;
    cin>>x>>y;
    vector<int> newInterval(2);
    newInterval[0]=x;
    newInterval[1]=y;
    vector<vector<int>> res=insert(arr,newInterval);
    for(int i=0;i<res.size();i++){
        cout<<res[i][0]<<" "<<res[i][1]<<endl;
    }
}