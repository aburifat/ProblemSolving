#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll phi(ll n)
{
    ll result=n;
    for(ll i=2;(i*i)<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            result-=(result/i);
        }
    }
    if(n>1)
        result-=(result/n);
    return result;
}

int main()
{
    ll n;
    while(cin>>n){
        if(n==0)break;
        if(n==1){
            cout<<"0"<<endl;
            continue;
        }
        ll ans=phi(n);
        cout<<ans<<endl;
    }
    return 0;
}
