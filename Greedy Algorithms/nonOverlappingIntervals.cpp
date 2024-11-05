#include<bits/stdc++.h>
using namespace std;
struct data {
    int start, end;
};

static bool comp(data val1, data val2) {
    return val1.end < val2.end;
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n == 0) return 0;
    
    vector<data> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].start = intervals[i][0];
        arr[i].end = intervals[i][1];
    }
    
    sort(arr.begin(), arr.end(), comp);
    
    int answer = 0;
    int lastTime = arr[0].end;
    
    for (int i = 1; i < n; i++) {
        if (arr[i].start < lastTime) {
            answer++; 
        } else {
            lastTime = arr[i].end;  
        }
    }
    
    return answer;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> intervals;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<2;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        intervals.push_back(temp);
    }
    cout<<eraseOverlapIntervals(intervals);
}