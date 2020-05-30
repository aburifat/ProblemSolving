#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node, edge;
vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>order;

void addEdge(ll v, ll u)
{
    adj[v].push_back(u);
}

void inis()
{
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    order.clear();
}

void orderDfs(ll v)
{
    visited[v]=true;
    for(auto u:adj[v]){
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

int main()
{
    while(cin>>node){
        cin>>edge;
        node++;
        inis();
        ll a, b;
        for(ll i=0; i<edge; i++){
            cin>>a>>b;
            if(b==0)continue;
            addEdge(a,b);
        }
        for(ll i=0; i<node;i++)
        {
            if(!visited[i]){
                orderDfs(i);
            }
        }
        visited.assign(node+1,false);
        ll ct=0;
        for(ll i=0; i<node; i++){
            ll s=order[node-1-i];
            if(!visited[s]){
                dfs(s);
                ct++;
            }
        }
        ct--;
        cout<<ct<<endl;
    }
    return 0;
}
