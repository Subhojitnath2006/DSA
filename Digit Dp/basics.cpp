/*---------- Digit Dp ----------*/
/*
conditions:-
1) range [l,r]
2) [l,r] sum of digits of each number in the given range
3)10^18
G(x) = [1,x];
x = 3245(4)

pos = 20 digits
tight  = 0 or 1 --> tight == 0 the no restriction on digits else there in restriction on digits
sum = 9 * 20 = 180

int dp[20][2][200] = {-1};

int G(pos,tight,sum){
    if(pos == digits.size()){
        return sum;
    }
    else if(dp[pos][tight][sum] != -1){
        return dp[pos][tight][sum];
    }
    else if(tight == 1){
        for(int i=0;i<=number[pos];i++){
            if(i == number[pos]){
                return dp[pos][tight][sum] = G(pos+1,1,sum+i);
            }
        }
    }
    else{
        for(int i=0;i<=9;i++){
            return dp[pos][tight][sum] = G(pos+1,0,sum+i);
        }
    }
}
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//pos = 8, sum = 72
ll dp[10][2][100];
ll prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

bool check(ll sum){
    for(ll p : prime){
        if(p == sum) return true;
    }
    return false;
}

ll g(string str,ll pos=0,ll sum = 0,ll tight = 1){
    if(pos == str.size()){
        if(check(sum)) return 1;
        else return 0;
    }
    else if(dp[pos][sum][tight] != -1) return dp[pos][sum][tight];
    else if(tight == 1){
        ll res = 0;
        for(ll i=0;i<=str[pos]-'0';i++){
            if(i == str[pos] - '0'){
                res += g(str,pos+1,sum+i,1);
            }
            else{
                res += g(str,pos+1,sum+i,0);
            }
        }
        dp[pos][sum][tight] = res;
        return res;
    }
    else{
        ll res = 0;
        for(int i=0;i<=9;i++){
            res += g(str,pos+1,sum+i,0);
        }
        dp[pos][sum][tight] = res;
        return res;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        l=l-1;

        string a = to_string(l);
        string b = to_string(r);
        memset(dp,-1,sizeof(dp));
        ll ans1 = g(b);
        ll ans2 = g(a);
        cout<<ans1-ans2<<endl;
    }
}