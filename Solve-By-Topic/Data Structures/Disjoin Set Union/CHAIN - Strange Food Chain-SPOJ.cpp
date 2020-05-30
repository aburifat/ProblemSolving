#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node,edge,ans,type;
vector<ll>par,rnk;

void inis() {
    par.resize(node+1);
    rnk.assign(node+1,0);
    ans=0;
    for(ll i=0; i<=node; i++) {
        par[i]=i;
    }
}

ll Find(ll v) {
    if(v==par[v])return v;
    rnk[par[v]]-=;
    return par[v]=Find(par[v]);
}

void Join(ll a, ll b) {
    ll pa=Find(a);
    ll pb=Find(b);
    if(pa==pb){
        ll tmp=(rnk[b]-rnk[a])%3;
        if(tmp<0)tmp+=3;
        if(tmp!=(type-1)){
            ans++;
            cout<<"Check :: "<<type<<" "<<a<<" "<<b<<endl;
            cout<<"Ranks : "<<rnk[b]<<" "<<rnk[a]<<endl;
        }
    }else{
        ll tmp=(rnk[a]+rnk[b]+(type-1));
        par[pa]=pb;
        rnk[b]=tmp;
    }
}

int main() {
    ll t;
    cin>>t;
    while(t--) {
        cin>>node>>edge;
        inis();
        ll x,y;
        while(edge--) {
            cin>>type>>x>>y;
            if(x>node||y>node) {
                ans++;
                continue;
            }
            Join(x,y);
        }
        cout<<ans<<endl;
    }
    return 0;
}

/**
Input::

1
5 6
2 1 2
2 2 3
2 4 5
2 2 5
1 2 4
2 1 4

Output::
0

**/
