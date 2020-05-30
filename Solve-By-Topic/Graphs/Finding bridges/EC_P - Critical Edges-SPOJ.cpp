#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll node,edge;
vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>timeIn,low;
set<pair<ll,ll> >bridges;
ll timer;

void addEdge(ll u, ll v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void useBridge(ll u, ll v) {
    if(u>v)
        swap(u,v);
    bridges.insert({u,v});
}

void dfs(ll v, ll p=-1) {
    visited[v]=true;
    timeIn[v]=low[v]=timer++;
    for(auto to:adj[v]) {
        if(to==p)
            continue;
        if(visited[to]) {
            low[v]=min(low[v],timeIn[to]);
        } else {
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>timeIn[v]) {
                useBridge(v,to);
            }
        }
    }
}

void inis() {
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    timeIn.assign(node+1,-1);
    low.assign(node+1,-1);
    bridges.clear();
    timer=0;
}

void printAns() {
    ll len=bridges.size();
    if(len) {
        cout<<len<<endl;
        for(auto e:bridges) {
            cout<<e.first<<" "<<e.second<<endl;
        }
    } else {
        cout<<"Sin bloqueos"<<endl;
    }

}

int main() {
    ll t,a,b;
    cin>>t;
    for(ll T=1; T<=t; T++) {
        cin>>node>>edge;
        inis();
        for(ll i=0; i<edge; i++) {
            cin>>a>>b;
            addEdge(a,b);
        }
        cout<<"Caso #"<<T<<endl;
        for(ll i=1; i<=node; i++) {
            if(!visited[i]) {
                dfs(i);
            }
        }
        printAns();
    }
    return 0;
}
