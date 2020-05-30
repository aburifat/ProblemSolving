#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int node,edge;
vector<vector<ll> >adj;
vector<bool>visited;

void addEdge(ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(ll s) {
    visited[s]=true ;
    for (auto u:adj[s]) {
        if (!visited[u])
            dfs(u);
    }
}

ll find_comps(){
    ll ans=0;
    for(ll i=0;i<node;++i)
        visited[i]=false;
    for(ll i=0;i<node;++i)
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    return ans;
}


int main()
{
    cin>>node>>edge;
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    ll a,b;
    for(ll i=0; i<edge; i++){
        cin>>a>>b;
        addEdge(a,b);
    }
    ll ans=find_comps();
    cout<<ans<<endl;
    return 0;
}

