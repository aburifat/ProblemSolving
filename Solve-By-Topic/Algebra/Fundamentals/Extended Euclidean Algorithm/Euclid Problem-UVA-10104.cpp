#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exGCD(ll a, ll b, ll &x, ll &y)
{
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll d=exGCD(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll a, b,x,y;
    while(cin>>a>>b){
        ll ans=exGCD(a,b,x,y);
        cout<<x<<" "<<y<<" "<<ans<<"\n";
    }
    return 0;
}
