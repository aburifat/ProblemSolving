#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node, edge;
vector<vector<ll> >adj,revAdj;
vector<bool>visited;
vector<ll>order,component;

void addEdgeD(ll u, ll v)
{
    adj[u].push_back(v);
    revAdj[v].push_back(u);
}
void addEdge(ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    revAdj[u].push_back(v);
    revAdj[v].push_back(u);
}

void dfs1(ll s)
{
    visited[s]=true;
    for(auto u:adj[s]){
        if(!visited[u]){
            dfs1(u);
        }
    }
    order.push_back(s);
}

void dfs2(ll s)
{
    visited[s]=true;
    component.push_back(s);
    for(auto u:revAdj[s]){
        if(!visited[u]){
            dfs2(u);
        }
    }
}

void useComponent()
{

}

void inis()
{
    adj.assign(node+1,vector<ll>());
    revAdj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    order.clear();
    component.clear();
}


int main()
{
    while(cin>>node){
        cin>>edge;
        if(node==0&&edge==0)break;
        inis();
        ll a, b, r;
        for(ll i=0;i<edge;i++){
            cin>>a>>b>>r;
            a--;b--;
            if(r==1)addEdgeD(a,b);
            else addEdge(a,b);
        }
        for(ll i=0;i<node;i++)
        {
            if(!visited[i])
                dfs1(i);
        }
        visited.assign(node+1,false);
        ll ct=0;
        for(ll i=0;i<node;i++){
            ll s=order[node-1-i];
            if(!visited[s]){
                dfs2(s);
                ct++;
            }
        }
        if(ct>1)cout<<"0"<<endl;
        else cout<<"1"<<endl;
    }
    return 0;
}
