#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=1e9+7;
vector<ll>fib;

void inis()
{
    fib.push_back(1);
    fib.push_back(2);
    for(ll i=2;fib[i-1]<MX;i++){
        fib.push_back(fib[i-1]+fib[i-2]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inis();
    ll t;
    cin>>t;
    ll n;
    while(t--){
        cin>>n;
        ll idx=upper_bound(fib.begin(),fib.end(),n)-fib.begin();
        if(fib[idx]>n)idx--;
        for(ll i=idx;i>=0;i--){
            if(fib[i]<=n){
                cout<<"1";
                n-=fib[i];
            }else{
                cout<<"0";
            }
        }
        cout<<"\n";
    }
}
