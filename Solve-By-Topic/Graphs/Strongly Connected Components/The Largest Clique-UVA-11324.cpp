#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node,edge;
vector<vector<ll> >adj;
vector<bool>visited;
ll dp[1009];
ll mxdis=0;

void addEdge(ll u, ll v)
{
    adj[u].push_back(v);
}

void inis()
{
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    mxdis=0;
    for(ll i=0; i<=node;i++){
        dp[i]=0;
    }
}

void dfs(ll v)
{
    visited[v]=true;
    for(auto u:adj[v]){
        if(!visited[u]){
            dfs(u);
            if(dp[v]<(dp[u]+1)){
                dp[v]=dp[u]+1;
            }
        }
    }
    if(mxdis<dp[v]){
        mxdis=dp[v];
    }
}

int main()
{
    ll t;
    cin>>t;
    while(t--){
        cin>>node>>edge;
        inis();
        ll a,b;
        for(ll i=0; i<edge;i++){
            cin>>a>>b;
            a--;b--;
            addEdge(a,b);
        }
        for(ll i=0;i<node;i++){
            if(dp[i]==0){
                visited.assign(node+1,false);
                dfs(i);
            }
        }
        cout<<mxdis<<endl;
    }
    return 0;
}
