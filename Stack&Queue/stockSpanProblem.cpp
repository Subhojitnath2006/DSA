#include<bits/stdc++.h>
using namespace std;
vector<int> calculateSpan(vector<int>& arr) {
    int n=arr.size();
    stack<int>st;
    st.push(0);
    vector<int>ans(n,0);
    ans[0]=1;
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[i]>=arr[st.top()]){
            st.pop();
        }
        if(st.empty()) ans[i]=i+1;
        else ans[i]=i-st.top();
        st.push(i);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>ans=calculateSpan(arr);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}