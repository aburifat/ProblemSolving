#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=2000000;
vector<ll>phi;
vector<ll>sumPhiTour;

void phi_1_to_n(ll n)
{
    phi.resize(n+1);
    sumPhiTour.resize(n+1);
    phi[1]=1;
    for(ll i=2;i<=n;i++){
        phi[i]=i;
    }
    for(ll i=2;i<=n;i++){
        if(phi[i]==i){
            for(ll j=i;j<=n;j+=i)
                phi[j]-=(phi[j]/i);
        }
    }
}

ll SODF(ll n)
{
    if(n==1)return 0;
    else if(sumPhiTour[n])return sumPhiTour[n];
    else return sumPhiTour[n]=SODF(phi[n])+1;
}


int main()
{
    phi_1_to_n(MX);
    ll t;
    cin>>t;
    while(t--){
        ll m, n;
        cin>>m>>n;
        ll ans=0;
        for(ll i=m;i<=n;i++){
            ans+=SODF(i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
