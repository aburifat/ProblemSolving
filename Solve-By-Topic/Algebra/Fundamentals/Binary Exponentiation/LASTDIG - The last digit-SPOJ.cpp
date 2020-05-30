#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binExp(ll base, ll power, ll mod)
{
    base%=mod;
    ll result=1;
    while(power>0){
        if(power&1)result=(result*base)%mod;
        base=(base*base)%mod;
        power>>=1;
    }
    return result;
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    ll base, power;
    while(t--){
        cin>>base>>power;
        ll ans=binExp(base,power,10);
        cout<<ans<<"\n";
    }
    return 0;
}
