#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX=1e5+100;

bitset<100109>bs;
vector<ll>primes;
void sieve(ll ub)
{
    bs.set();
    ub++;
    bs[0]=bs[1]=0;
    primes.push_back(-1);
    primes.push_back(2);
    for(ll i=4;i<=ub;i+=2)bs[i]=0;
    for(ll i=3;i<=ub;i+=2)
    {
        if(bs[i]){
            for(ll j=i*i;j<=ub;j+=i)bs[j]=0;
            primes.push_back(i);
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    sieve(MX);
    ll t;
    cin>>t;
    ll n,k;
    while(t--){
        cin>>n>>k;
        n=sqrt(n);
        k=sqrt(k);
        ll idx=lower_bound(primes.begin(),primes.end(),n)-primes.begin();
        if(!bs[n])idx--;
        ll idx2=lower_bound(primes.begin(),primes.end(),k)-primes.begin();
        if(!bs[k])idx2--;
        if(idx2>idx)idx2=idx;
        cout<<idx<<" "<<(idx-idx2)<<"\n";
    }
    return 0;
}
