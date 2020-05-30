#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=1e8;

ll minPF[MX+1];
vector<ll>primes;

void sieve(ll ub)
{
    for (ll i=2; i<=ub; ++i) {
        if (minPF[i] == 0) {
            minPF[i] = i;
            primes.push_back(i);
        }
        for (ll j=0; j<(ll)primes.size() && primes[j]<=minPF[i] && i*primes[j]<=ub; ++j)
            minPF[i * primes[j]] = primes[j];
    }
}

vector<ll>piramid;

void buildP()
{
    ll len=primes.size();
    piramid.push_back(0);
    for(ll i=1;piramid[i-1]<len;i++){
        piramid.push_back(piramid[i-1]+i);
    }
}

int main()
{
    sieve(MX);
    buildP();
    ll t;
    cin>>t;
    ll n;
    while(t--){
        cin>>n;
        if(minPF[n]==n){
            ll idx=upper_bound(primes.begin(),primes.end(),n)-primes.begin();
            ll row=upper_bound(piramid.begin(),piramid.end(),idx)-piramid.begin();
            if(idx==piramid[row-1])row--;
            ll col=idx-piramid[row-1];
            cout<<row<<" "<<col<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
    return 0;
}
