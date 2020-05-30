#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node;
vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>timeIn,low;
vector<bool>cutPoint;
ll timer;
ll edges[109][109];

void addEdge(ll u, ll v) {
    if(edges[u][v]==0) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(ll s, ll p=-1) {
    visited[s]=true;
    timeIn[s]=low[s]=timer++;
    ll child=0;
    for(auto to:adj[s]) {
        if(to==p)
            continue;
        if(visited[to]) {
            low[s]=min(low[s],timeIn[to]);
        } else {
            dfs(to,s);
            low[s]=min(low[s],low[to]);
            if(low[to]>=timeIn[s]&&p!=-1) {
                cutPoint[s]=true;
            }
            child++;
        }
    }
    if(p==-1&&child>1) {
        cutPoint[s]=true;
    }
}


void inis() {
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    timeIn.assign(node+1,-1);
    low.assign(node+1,-1);
    cutPoint.assign(node+1,false);
    timer=0;
}

int main() {
    ll u,v;
    while(cin>>node,node!=0) {
        cin.ignore();
        inis();
        string s;
        while(getline(cin,s),s!="0") {
            stringstream ss(s);
            ss>>u;
            while(ss>>v) {
                addEdge(u,v);
            }
        }
        for(ll i=1; i<=node; i++) {
            if(!visited[i]) {
                dfs(i);
            }
        }
        cout<<count(cutPoint.begin(),cutPoint.end(),true)<<endl;
    }

    return 0;
}
