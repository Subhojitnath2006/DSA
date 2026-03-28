#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[12][12];
ll go(ll n,vector<ll>&s,ll pos = 0,ll prev = 0,string temp=""){
    ll res = 0;
    if(dp[pos][prev] != -1) return dp[pos][prev];
    if(pos == n) {
        cout<<temp<<endl;
        return 1;
    }
    for(ll j=0;j<s.size();j++){
        if(prev == 0 || abs(prev-s[j]) <= 2){
            res += go(n,s,pos+1,s[j],temp + to_string(s[j]));
        }
    }
    return dp[pos][prev] = res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<ll>s(m);
        for(int i=0;i<m;i++) cin>>s[i];
        memset(dp,-1,sizeof(dp));
        ll ans = go(n,s);
        cout<<ans<<endl;
    }
}