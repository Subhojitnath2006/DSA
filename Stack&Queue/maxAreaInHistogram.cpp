#include<bits/stdc++.h>
using namespace std;
int getMaxArea(vector<int> &arr) {
    // Your code here
    stack<int>st;
    int nse,pse;
    int maxArea=0;
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            int el=st.top();
            st.pop();
            nse=i;
            pse=st.empty() ? -1:st.top();
            maxArea=max(maxArea,arr[el]*(nse-pse-1));
        }
        st.push(i);
    }
    while(!st.empty()){
        nse=arr.size();
        int element=st.top();st.pop();
        pse=st.empty() ? -1:st.top();
        maxArea=max(maxArea,arr[element]*(nse-pse-1));
    }
    return maxArea;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<getMaxArea(arr)<<endl;
}