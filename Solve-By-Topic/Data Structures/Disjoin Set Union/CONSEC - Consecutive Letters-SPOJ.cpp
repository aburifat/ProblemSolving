#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string Real,Fake;
ll node,edge;
vector<ll>par,siz;
vector<ll>Type,Index;

void inis()
{
    par.resize(node+1);
    siz.assign(node+1,1);
    Type.resize(edge+1);
    Index.resize(edge+1);
    for(ll i=0;i<=node;i++){
        par[i]=i;
    }
}

ll Find(ll v)
{
    if(v==par[v])return v;
    return par[v]=Find(par[v]);
}

void Join(ll a, ll b)
{
    a=Find(a);
    b=Find(b);
    if(a!=b){
        par[b]=a;
        siz[a]+=siz[b];
    }
}

void Change(ll idx)
{
    char ch=Real[idx];
    Fake[idx]=ch;
    if(idx>0){
        if(Fake[idx-1]==ch){
            Join(idx-1,idx);
        }
    }
    if(idx<(node-1)){
        if(Fake[idx+1]==ch){
            Join(idx,idx+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        cin>>Real;
        Fake=Real;
        node=Real.size();
        cin>>edge;
        inis();
        for(ll i=0; i<edge;i++){
            cin>>Type[i]>>Index[i];
            if(Type[i]==2){
                Fake[Index[i]]='#';
            }
        }
        for(ll i=1;i<node;i++){
            if(Fake[i]=='#')continue;
            if(Fake[i-1]==Fake[i]){
                Join(i-1,i);
            }
        }
        deque<ll>ans;
        for(ll i=edge-1;i>=0;i--){
            if(Type[i]==1){
                Index[i]=Find(Index[i]);
                ans.push_front(siz[Index[i]]);
            }else{
                Change(Index[i]);
            }
        }
        cout<<"Case "<<T<<":\n";
        for(auto A:ans){
            cout<<A<<"\n";
        }
    }
}


/**
Input::

1
AABAAA
4
1 0
1 5
2 4
1 5

Output::

Case 1:
2
3
1

**/
