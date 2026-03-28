#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[11][2][2];
ll go(string str,ll pos = 0,ll tight  = 1,ll flag = 0){
    if(pos == str.size()){
        if(flag == 1) return 1;
        else return 0;
    }
    else if(dp[pos][tight][flag] != -1) return dp[pos][tight][flag];
    else if(tight == 1){
        ll res = 0;
        for(ll i=0;i<=str[pos] - '0';i++){
            ll flg = flag;
            if(i == 3) flg = 1;
            if(i == str[pos]-'0'){
                res += go(str,pos+1,1,flg);
            }
            else{
                res += go(str,pos+1,0,flg);
            }
        }
        dp[pos][tight][flag] = res;
        return res;
    }
    else{
        ll res = 0;
        for(int i=0;i<=9;i++){
            ll flg = flag;
            if(i == 3) flg = 1;
            res += go(str,pos+1,0,flg);
        }
        dp[pos][tight][flag] = res;
        return res;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str = to_string(n);
        memset(dp,-1,sizeof(dp));
        cout<<n-go(str)<<endl;
    }
}