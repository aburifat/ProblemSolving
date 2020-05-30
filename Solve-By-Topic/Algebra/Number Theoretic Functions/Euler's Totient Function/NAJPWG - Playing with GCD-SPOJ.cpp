#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=100000;

vector<ll>phi,sumPhi,qSum;

void phiAll(ll n)
{
    phi.resize(n+1);
    phi[0]=0;
    phi[1]=1;
    for(ll i=2;i<=n;i++)
        phi[i]=i;
    for(ll i=2;i<=n;i++)
        if(phi[i]==i)
            for(ll j=i;j<=n;j+=i)
                phi[j]-=(phi[j]/i);
}

void sum(ll n)
{
    sumPhi.resize(n+1);
    qSum.resize(n+1);
    sumPhi[0]=phi[0];
    qSum[0]=0;
    for(ll i=1;i<=n;i++)
    {
        sumPhi[i]=sumPhi[i-1]+phi[i];
        qSum[i]=qSum[i-1]+i;
    }
}

int main()
{
    phiAll(MX);
    sum(MX);
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        ll n;
        cin>>n;
        ll ans=qSum[n]-sumPhi[n];
        cout<<"Case "<<T<<": "<<ans<<endl;
    }
}
