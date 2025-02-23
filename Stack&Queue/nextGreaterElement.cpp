#include<bits/stdc++.h>
using namespace std;
vector<int> nextLargerElement(vector<int>& arr) {
    // code here
    int n=arr.size();
    stack<int>st;
    vector<int>ans;
    ans.push_back(-1);
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>ans=nextLargerElement(arr);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}