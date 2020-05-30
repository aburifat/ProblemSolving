#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node,edge;
vector<ll>parent,siz;

void make_set(ll v)
{
    parent[v]=v;
    siz[v]=1;
}

void inis()
{
    parent.resize(node+1);
    siz.resize(node+1);
    for(ll i=0;i<=node;i++){
        make_set(i);
    }
}

ll find_set(ll v)
{
    if(v==parent[v])return v;
    return parent[v]=find_set(parent[v]);
}

void union_sets(ll a, ll b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(siz[a]<siz[b])
            swap(a,b);
        parent[b]=a;
        siz[a]+=siz[b];
    }
}

int main()
{
    ll t;
    cin>>t;
    bool pe=false;
    while(t--)
    {
        if(pe)cout<<"\n";
        else pe=true;
        char ch;
        set<char>sub;
        cin>>ch;
        node=ch-'A';
        node++;
        inis();
        string s;
        getchar();
        while(1){
            getline(cin,s);
            if(s=="")break;
            union_sets((s[0]-'A'),(s[1]-'A'));
        }
        ll st;
        for(ll i=0;i<node;i++){
            st=find_set(i);
            sub.insert(st);
        }
        cout<<sub.size()<<endl;
    }
    return 0;
}
