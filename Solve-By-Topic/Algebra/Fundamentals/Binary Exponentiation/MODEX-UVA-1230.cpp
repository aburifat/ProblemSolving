#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=32768;
bitset<100000>bs;
vector<ll>primes;
ll ss;

void sieve(ll ub)
{
    ss=ub+1;
    bs.set();
    bs[0]=bs[1]=0;
    primes.push_back(2);
    for(ll i=4;i<=ss;i+=2)bs[i]=0;
    for(ll i=3;i<=ss;i+=2){
        if(bs[i]){
            for(ll j=i*i;j<=ss;j+=i){
                bs[j]=0;
            }
            primes.push_back(i);
        }
    }
}

ll binExp(ll base, ll power, ll mod)
{
    base%=mod;
    if(bs[mod])power%=(mod-1);
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
    sieve(MX);
    ll t;
    cin>>t;
    ll base, power, mod;
    while(t--){
        cin>>base>>power>>mod;
        ll ans=binExp(base,power,mod);
        cout<<ans<<endl;
    }
    cin>>base;
    return 0;
}
