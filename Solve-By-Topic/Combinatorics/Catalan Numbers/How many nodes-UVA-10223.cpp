
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=20;

vector<ll>catNum(MX+1);
map<ll,ll>m;

void catCt(ll n)
{
    catNum[0]=catNum[1]=1;
    m[1]=1;
    for(ll i=2;i<=n;i++){
        catNum[i]=0;
        for(ll j=0; j<i; j++){
            catNum[i]+=(catNum[j]*catNum[i-j-1]);
        }
        m[catNum[i]]=i;
    }
}


int main()
{
    catCt(MX);
    ll n;
    while(cin>>n){
        if(m[n])cout<<m[n]<<endl;
        else{
            ll ans=lower_bound(catNum.begin(),catNum.end(),n)-catNum.begin();
            ans--;
            cout<<ans<<endl;
        }
    }
    return 0;
}

