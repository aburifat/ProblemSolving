#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD=1e7+7;

ll binExp(ll base, ll power)
{
    base%=MOD;
    ll result=1;
    while(power>0)
    {
        if(power&1)result=(result*base)%MOD;
        base=(base*base)%MOD;
        power>>=1;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n, k;
    while(cin>>n>>k)
    {
        if(n==0&&k==0)break;
        ll res1=binExp(n-1,k);
        ll res2=binExp(n,k);
        ll res3=binExp(n-1,n-1);
        ll res4=binExp(n,n);
        ll res=((2*res1)%MOD+res2+(2*res3)%MOD+res4)%MOD;
        cout<<res<<"\n";
    }
    return 0;
}
