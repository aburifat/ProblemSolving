#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=10;

ll catNum[MX];

void ctCatNum(ll n)
{
    catNum[0]=catNum[1]=1;
    for(ll i=2;i<=n;i++){
        catNum[i]=0;
        for(ll j=0;j<i;j++){
            catNum[i]+=(catNum[j]*catNum[i-j-1]);
        }
    }
}

int main()
{
    ctCatNum(MX);
    ll n;
    ll ck=0;
    while(cin>>n){
        if(ck)cout<<"\n";
        else ck++;
        cout<<catNum[n]<<"\n";
    }
    return 0;
}
