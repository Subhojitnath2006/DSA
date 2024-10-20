#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
const int N=1000001;
int a[N];
signed main()
{
  ll n,q;
  cin >> n >> q;
  
  for(int i=1;i<=n;i++)
  {
    cin >>a[i];
  }
  ll p[n+1];
  p[0]=0;
  for(int i=1;i<=n;i++)
  {
    p[i]=a[i]+p[i-1];
    if(p[i]<0)
    {
      p[i]+=mod;
    }
    if(p[i]>=mod)
    {
      p[i]-=mod;
    }
  }
  while(q--)
  {
    ll l,r;
    cin >> l >> r;
    ll tot=p[r]-p[l-1];
    if(tot<0)
    {
      tot+=mod;
    }
    if(tot>=mod)
    {
      tot-=mod;
    }
    cout << tot <<'\n';
  }
}