#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


map<ll,ll>Store;
const ll MOD=1e9+7;
ll binExp(ll base, ll power)
{
    base%=MOD;
    power%=(MOD-1);
    ll result=1;
    while(power>0){
        if(power&1)result=(result*base)%MOD;
        base=(base*base)%MOD;
        power>>=1;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    ll n;
    while(t--){
        ll ans=1;
        cin>>n;
        ll num=n;
        if(Store[num]){
            cout<<Store[num]<<"\n";
        }
        if(num<4){
            cout<<n<<"\n";
            Store[num]=num;
            continue;
        }
        if(n%3==1){
            ans=4;
            n-=4;
        }else if(n%3==2){
            ans=2;
            n-=2;
        }
        ans=ans*binExp(3,n/3);
        ans%=MOD;
        Store[num]=ans;
        cout<<ans<<"\n";
    }
}
