#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node,edge;
vector<vector<ll> >adj,revAdj;
vector<bool>visited;
vector<ll>order;
ll disLike[5009][5009];

void addEdge(ll v, ll u)
{
    adj[v].push_back(u);
    revAdj[u].push_back(v);
}

void inis()
{
    adj.assign(node+1, vector<ll>());
    revAdj.assign(node+1, vector<ll>());
    visited.assign(node+1,false);
    order.clear();
    for(ll i=0; i<=node;i++){
        for(ll j=0; j<=node;j++){
            disLike[i][j]=0;
        }
    }
}

void orderDfs(ll v)
{
    visited[v]=true;
    for(auto u: adj[v]){
        if(!visited[u]){
            orderDfs(u);
        }
    }
    order.push_back(v);
}

void dfs(ll v)
{
    visited[v]=true;
    for(auto u:revAdj[v]){
        if(!visited[u]){
            dfs(u);
        }
    }
}

int main()
{
    ll val;
    ll a,b;
    while(cin>>node){
        cin>>edge;
        inis();
        for(ll i=0; i<edge; i++){
            cin>>a>>b;
            a--;b--;
            disLike[a][b]=1;
        }
        cin>>val;
        for(ll i=0; i<node;i++){
            for(ll j=0;j<node;j++){
                if(!disLike[i][j]&&(i!=j)){
                    addEdge(i,j);
                }
            }
        }
        for(ll i=0;i<node;i++){
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
        cout<<(ct*val)<<endl;
    }
    return 0;
}

