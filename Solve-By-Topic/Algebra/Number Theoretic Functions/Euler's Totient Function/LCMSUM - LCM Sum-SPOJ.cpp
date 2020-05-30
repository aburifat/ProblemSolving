#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=1000000;

vector<ll>phi;
vector<ll>cal;

void phiAll(ll n)
{
    phi.resize(n+1);
    phi[0]=0;
    phi[1]=1;
    for(ll i=2; i<=n; i++){
        phi[i]=i;
    }
    for(ll i=2; i<=n; i++){
        if(phi[i]==i){
            for(ll j=i; j<=n; j+=i){
                phi[j]-=(phi[j]/i);
            }
        }
    }
}

void div_mul_phiDiv_sum_all_n(ll n)
{
    cal.resize(n+1);
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j+=i){
            cal[j]+=(i*phi[i]);
        }
    }
}


int main()
{
    phiAll(MX);
    div_mul_phiDiv_sum_all_n(MX);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=cal[n]+1;
        ans*=n;
        ans/=2;
        cout<<ans<<endl;
    }
}
