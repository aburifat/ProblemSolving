#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node,edge;
vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>order;

void inis() {
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    order.clear();
}

void addEdge(ll v, ll u) {
    adj[v].push_back(u);
}

void orderDfs(ll v)
{
    visited[v]=true;
    for(auto u:adj[v])
    {
        if(!visited[u]){
            orderDfs(u);
        }
    }
    order.push_back(v);
}

void dfs(ll v)
{
    visited[v]=true;
    for(auto u:adj[v]){
        if(!visited[u]){
            dfs(u);
        }
    }
}

int main() {
    ll t;
    cin>>t;
    for(ll T=1; T<=t; T++) {
        cin>>node>>edge;
        inis();
        ll a, b;
        for(ll i=0; i<edge; i++) {
            cin>>a>>b;
            a--;b--;
            addEdge(a,b);
        }
        for(ll i=0; i<node; i++){
            if(!visited[i]){
                orderDfs(i);
            }
        }
        visited.assign(node+1,false);
        ll ct=0;
        for(ll i=0;i<node;i++){
            ll s=order[node-1-i];
            if(!visited[s]){
                dfs(s);
                ct++;
            }
        }
        cout<<"Case "<<T<<": "<<ct<<endl;
    }
}

/**

input::
2
13 15
1 2
1 4
2 3
3 4
3 5
6 5
6 7
7 8
8 9
9 6
9 10
10 11
12 13
12 11
13 11

7 8
2 1
3 1
4 2
4 3
5 4
5 6
7 5
6 7

Output::
Case 1: 3
Case 2: 1

**/
