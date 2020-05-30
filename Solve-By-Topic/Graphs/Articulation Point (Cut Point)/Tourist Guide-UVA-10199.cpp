#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node, edge;
vector<vector<ll> >adj;
map<string,ll>citys;
map<ll,string>revCitys;
vector<bool>visited;
vector<ll>timeIn,low;
set<string>cutPoints;
ll timer;

void addEdge(ll u, ll v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void inis() {
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    timeIn.assign(node+1,-1);
    low.assign(node+1,-1);
    cutPoints.clear();
    citys.clear();
    revCitys.clear();
    timer=0;
}

void isCutPoint(ll v) {
    string s=revCitys[v];
    cutPoints.insert(s);
}

void dfs(ll v, ll p=-1) {
    visited[v]=true;
    timeIn[v]=low[v]=timer++;
    ll child=0;
    for(auto to:adj[v]) {
        if(to==p)
            continue;
        if(visited[to]) {
            low[v]=min(low[v],timeIn[to]);
        } else {
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>=timeIn[v]&&p!=-1) {
                isCutPoint(v);
            }
            child++;
        }
    }
    if(p==-1&&child>1) {
        isCutPoint(v);
    }
}

int main() {
    ll T=1;
    while(cin>>node) {
        if(node==0)
            break;
        inis();
        if(T>1)
            cout<<endl;
        string s;
        ll num=0;
        for(ll i=0; i<node; i++) {
            cin>>s;
            if(!citys[s]) {
                num++;
                citys[s]=num;
                revCitys[num]=s;
            }
        }
        cin>>edge;
        string a,b;
        for(ll i=0; i<edge; i++) {
            cin>>a>>b;
            addEdge(citys[a],citys[b]);
        }
        for(ll i=1; i<=node; i++) {
            if(!visited[i]) {
                dfs(i);
            }
        }
        ll len=cutPoints.size();
        cout<<"City map #"<<T<<": "<<len<<" camera(s) found\n";
        T++;
        if(len) {
            for(auto s:cutPoints) {
                cout<<s<<endl;
            }
        }
    }
    return 0;
}


/**
input::

6
sugarloaf
maracana
copacabana
ipanema
corcovado
lapa
7
ipanema copacabana
copacabana sugarloaf
ipanema sugarloaf
maracana lapa
sugarloaf maracana
corcovado sugarloaf
lapa corcovado



**/
