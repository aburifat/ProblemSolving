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
    ll a,b;
    double ans;
    while(cin>>a){
        cin>>b;
        if(a==0&&b==0)break;
        if(a>b)ans=0.0;
        else
        ans=(double)(b-a+1.0)/(double)(b+1.0);
        printf("%.6f\n",ans);
    }
    return 0;
}
