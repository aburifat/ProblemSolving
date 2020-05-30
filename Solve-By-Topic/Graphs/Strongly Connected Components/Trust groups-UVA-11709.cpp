#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node, edge;
vector<vector<ll> >adj,revAdj;
vector<bool>visited;
vector<ll>order;
map<string,ll>ppl;
map<ll,string>revPpl;
ll grpCt;

void addEdge(ll u, ll v) {
    adj[u].push_back(v);
    revAdj[v].push_back(u);
}

void inis() {
    adj.assign(node+1,vector<ll>());
    revAdj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    order.clear();
    ppl.clear();
    revPpl.clear();
    grpCt=0;
}

void orderDfs(ll v) {
    visited[v]=true;
    for(auto u:adj[v]) {
        if(!visited[u])
            orderDfs(u);
    }
    order.push_back(v);
}

void sccDfs(ll v) {
    visited[v]=true;
    for(auto u:revAdj[v]) {
        if(!visited[u])
            sccDfs(u);
    }
}

int main() {
    while(cin>>node) {
        cin>>edge;
        if(node==0&&edge==0)
            break;
        inis();
        string a,b;
        ll manct=1;
        for(ll i=0; i<node; i++) {
            cin>>a>>b;
            a+=b;
            ppl[a]=manct++;
            revPpl[ppl[a]]=a;
            //dbg(a,ppl[a]);
        }
        string s,m;
        ll u,v;
        for(ll i=0; i<edge; i++) {
            cin>>a>>b;
            s=a+b;
            cin>>a>>b;
            m=a+b;
            u=ppl[s];
            v=ppl[m];
            u--;
            v--;
            //dbg(u,v);
            addEdge(u,v);
        }
        for(ll i=0; i<node; i++) {
            if(!visited[i])
                orderDfs(i);
        }
        visited.assign(node+1,false);
        ll ct=0;
        for(ll i=0; i<node; i++) {
            u=order[node-1-i];
            if(!visited[u]) {
                sccDfs(u);
                ct++;
            }
        }
        cout<<ct<<endl;
    }
}

/**

input::
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
Smith, Peter
Brown, Anna
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
McBride, John
Smith, Peter
0 0


**/
