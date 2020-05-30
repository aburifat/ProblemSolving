#include<bits/stdc++.h>
using namespace std;
using ll = uint64_t;

ll ckArr[]= {2,3,5,7,11,13,17,19,23,29,31,37};

inline ll bigMul(ll a, ll b, ll mod)
{
    if(a==0)return 0;
    ll ans=(2*bigMul(a/2,b,mod))%mod;
    if(a&1)ans=(ans+(b%mod))%mod;
    return ans;
}

inline ll binpow(ll base, ll power, ll mod)
{
    base%=mod;
    // If mod is prime, power=power%(mod-1);
    ll result=1;
    while(power>0){
        if(power&1)result=bigMul(result,base,mod);
        base=bigMul(base,base,mod);
        power>>=1;
    }
    return result;
}


inline bool ckComposite(ll n, ll a, ll d, ll s) {
    ll x=binpow(a, d, n);
    if(x==1||x==n-1)
        return false;
    for(ll r=1;r<s;r++){
        x=bigMul(x,x,n);
        if(x==n-1)
            return false;
    }
    return true;
};

bool MillerRabin(ll n) {
    if(n<2)
        return false;
    ll r=0;
    ll d=n-1;
    while((d&1)==0) {
        d>>=1;
        r++;
    }
    for (int a : ckArr) {
        if(n==a)
            return true;
        if(ckComposite(n, a, d, r))
            return false;
    }
    return true;
}

unordered_map<ll,int>prime;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    ll n;
    while(t--)
    {
        cin>>n;
        if(!prime[n]){
            prime[n]=(int)MillerRabin(n)+1;
        }
        if(prime[n]-1)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
