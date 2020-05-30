#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bitset<100000009>bs;
vector<ll>primes;
void sieve(ll ub)
{
    bs.set();
    ub++;
    bs[0]=bs[1]=0;
    primes.push_back(2);
    for(ll i=4;i<=ub;i+=2)bs[i]=0;
    for(ll i=3;i<=ub;i+=2){
        if(bs[i]){
            for(ll j=i*i;j<=ub;j+=i)bs[j]=0;
            primes.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n=1e8;
    sieve(n);
    ll len=primes.size();
    for(ll i=0;i<len;i+=100){
        cout<<primes[i]<<"\n";
    }
    return 0;
}

