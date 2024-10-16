#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define nl "\n"
//#define fast ios_sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod=1e9+7;
const int N=1e7;

vector<ll> fact(N);
ll binpow(ll a, ll b, ll m)
{
    ll r=1;
    while(b>0)
    {
        if(b%2==1)r=(r%m *a%m)%m;
        a=(a%m *a%m)%m;
        b/=2;
    }
    return r;
}
ll inv(ll num, ll mod)
{
    return binpow(num,mod-2,mod);
}

void solve()
{
    int n,m;
    cin >>n >> m;
    ll ans=(((fact[n]%mod)*(inv(fact[n-m],mod)%mod))%mod * inv(fact[m],mod)%mod)%mod; 
    cout << ans <<nl;
}

int main()
{
   // fast;
    fact[0]=1;
    for(int i=1;i<=1e6;++i)
    {
        fact[i]=(i%mod *fact[i-1]%mod)%mod;
    }
    solve();
}