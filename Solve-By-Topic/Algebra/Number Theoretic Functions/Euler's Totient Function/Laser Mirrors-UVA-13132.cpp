#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=100000;
vector<ll>phi;

void phi_1_to_n(ll n)
{
    phi.resize(n+1);
    phi[0]=0;
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

int main()
{
    phi_1_to_n(MX);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1)cout<<"0"<<endl;
        else
        cout<<phi[n]<<endl;
    }
    return 0;
}
