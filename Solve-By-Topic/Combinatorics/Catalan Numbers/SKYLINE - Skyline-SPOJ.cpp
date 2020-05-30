#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD=1000000;
const ll MX=1010;

ll catNum[MX];

void catCt(ll n)
{
    catNum[0]=catNum[1]=1;
    for(ll i=2;i<=n;i++){
        catNum[i]=0;
        for(ll j=0; j<i; j++){
            catNum[i]+=(catNum[j]*catNum[i-j-1])%MOD;
            if(catNum[i]>=MOD)
                catNum[i]-=MOD;
        }
    }
}


int main()
{
    catCt(MX);
    ll n;
    while(cin>>n){
        if(n==0)break;
        cout<<catNum[n]<<endl;
    }
    return 0;
}
