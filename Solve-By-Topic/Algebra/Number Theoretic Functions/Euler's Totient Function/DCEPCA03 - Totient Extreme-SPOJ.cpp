#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=10000;

vector<ll>phi;
vector<ll>sumPhi;

void phiAll(ll n)
{
    phi.resize(n+1);
    phi[0]=0;
    phi[1]=1;
    for(ll i=2;i<=n; i++)
        phi[i]=i;
    for(ll i=2; i<=n; i++)
        if(phi[i]==i)
            for(ll j=i;j<=n;j+=i)
                phi[j]-=(phi[j]/i);
}

void sum(ll n)
{
    sumPhi.resize(n+1);
    sumPhi[0]=phi[0];
    for(ll i=1;i<=n;i++)
        sumPhi[i]=sumPhi[i-1]+phi[i];
}

int main()
{
    phiAll(MX);
    sum(MX);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll p=sumPhi[n];
        p*=p;
        cout<<p<<endl;
    }
}
