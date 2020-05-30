#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=1000000;

vector<ll>phi;
vector<ll>S;

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

void cal(ll n)
{
    S.resize(n+1);
    for(ll i=1;i<=n;i++){
        for(ll j=2*i;j<=n;j+=i){
            S[j]+=(i*phi[j/i]);
        }
    }
    for(ll i=1;i<=n;i++)
        S[i]+=S[i-1];
}


int main()
{
    phiAll(MX);
    cal(MX);
    ll n;
    while(cin>>n){
        if(n==0)break;
        ll ans=S[n];
        cout<<ans<<endl;
    }
}
