#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll numDiv(ll n) {
    ll ans=1;
    for(ll i=2; i*i<=n; i++) {
        if(n%i==0) {
            ll pow=0;
            while(n%i==0) {
                n/=i;
                pow++;
            }
            ans*=(pow+1);
        }
    }
    if(n>1)
        ans*=2;
    return ans;
}

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll a, b;
        scanf("%lld%lld",&a,&b);
        ll val=__gcd(a,b);
        val=numDiv(val);
        printf("%lld\n",val);
    }
    return 0;
}
