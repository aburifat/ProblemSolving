#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll MX=500000;

bitset<500009>bs;
vector<ll>primes;
ll ss;

void sieve(ll ul)
{
    ss=ul+1;
    bs.set();
    bs[0]=0;
    bs[1]=0;
    for(ll i=4;i<=ss;i+=2)
    {
        bs[i]=0;
    }
    primes.push_back(2);
    for(ll i=3; i<=ss;i+=2){
        if(bs[i]){
            for(ll j=i*i;j<=ss;j+=i){
                bs[j]=0;
            }
            primes.push_back(i);
        }
    }
//    for(ll i=0;i<primes.size();i++)
//        cout<<primes[i]<<endl;
}

ll pw(ll b,ll p)
{
    if(p==0)return 1;
    if(p==1)return b;
    ll num=1;
    while(p--)num*=b;
    return num;
}

ll sumDiv(ll n) {
    ll ans=1;
    for(ll i=0;primes[i]<=n; i++) {
        if(n%primes[i]==0) {
            ll power=1;
            while(n%primes[i]==0) {
                n/=primes[i];
                power++;
            }
            ans*=(pw(primes[i],power)-1)/(primes[i]-1);
        }
    }
    return ans;
}


int main()
{
    sieve(MX);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=sumDiv(n)-n;
        cout<<ans<<endl;
    }
    return 0;
}

