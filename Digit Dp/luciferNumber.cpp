#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[12][2][60][60];
ll prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
bool isPrime(ll oddSum,ll evenSum,ll len){
    ll diff;
    if(len % 2 == 0){
        diff = evenSum - oddSum;
    }
    else{
        diff = oddSum - evenSum;
    }
    if(diff < 0) return false;
    for(ll p:prime){
        if(p == diff) return true;
    }
    return false;
}
ll go(string str,ll pos = 0,ll tight = 1,ll oddSum = 0,ll evenSum = 0){
    if(pos == str.size()){
        return isPrime(oddSum,evenSum,str.length());
    }
    else if(dp[pos][tight][oddSum][evenSum] != -1) return dp[pos][tight][oddSum][evenSum];
    else if(tight == 1){
        ll cnt = 0;
        for(ll i=0;i<=str[pos] - '0';i++){
            ll od = oddSum,ev = evenSum;
            if(pos % 2 == 1){
                od += i;
            }
            else{
                ev += i;
            }
            if(i == str[pos] - '0'){
                cnt += go(str,pos+1,1,od,ev);
            }
            else{
                cnt += go(str,pos+1,0,od,ev);
            }
        }
        return dp[pos][tight][oddSum][evenSum] = cnt;
    }
    else{
        ll cnt = 0;
        for(int i=0;i<=9;i++){
            ll od = oddSum,ev = evenSum;
            if(pos % 2 == 1){
                od += i;
            }
            else{
                ev += i;
            }
            cnt += go(str,pos+1,0,od,ev);
        }
        return dp[pos][tight][oddSum][evenSum] = cnt;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        memset(dp,-1,sizeof(dp));
        ll ans1 = go(b);
        ll ans2 = go(a);
        cout<<ans1-ans2<<endl;
    }
}