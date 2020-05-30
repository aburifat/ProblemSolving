#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=200009;

ll node,edge;
ll par[MX],ans[MX];
ll L[MX],R[MX],C[MX];

void inis()
{
    for(ll i=0;i<=node;i++){
        par[i]=i;
    }
}

ll Find(ll v)
{
    if(v==par[v])return v;
    return par[v]=Find(par[v]);
}

void Union(ll a, ll b)
{
    a=Find(a);
    b=Find(b);
    if(a==b)par[a]=a+1;
    else{
        par[a]=par[b]=max(a,b)+1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>node>>edge;
    node++;
    inis();
    for(ll i=0; i<edge;i++)
    {
        cin>>L[i]>>R[i]>>C[i];
    }
    for(ll i=(edge-1);i>=0;i--){
        for(ll v=Find(L[i]);v<=R[i];v=Find(v)){
            if(!ans[v]){
                ans[v]=C[i];
            }
            ll p=Find(v);
            Union(v,p);
        }
    }
    for(ll i=1;i<node;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
