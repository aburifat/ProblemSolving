#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    ll a, b, c;
    for(ll T=1;T<=t;T++){
        cin>>a>>b>>c;
        ll g=__gcd(a,b);
        if(c%g)cout<<"Case "<<T<<": No\n";
        else cout<<"Case "<<T<<": Yes\n";
    }
    return 0;
}
