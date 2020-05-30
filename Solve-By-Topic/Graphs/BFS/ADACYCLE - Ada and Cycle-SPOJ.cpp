#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>dist;

void addEdge(ll u, ll v)
{
    adj[u].push_back(v);
}

void bfs(ll s)
{
    dist[s]=0;
    queue<ll>q;
    q.push(s);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        ll d=dist[u];
        for(auto v=adj[u].begin();v!=adj[u].end();v++)
        {
            if(!visited[*v]){
                visited[*v]=true;
                dist[*v]=d+1;
                if(*v==s)return;
                q.push(*v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    adj.assign(n+1,vector<ll>());
    ll u;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>u;
            if(u==1){
                addEdge(i,j);
            }
        }
    }
    for(ll i=1;i<=n;i++){
        visited.assign(n+1,false);
        dist.assign(n+1,LONG_MAX);
        bfs(i);
        if(visited[i]){
            cout<<dist[i]<<endl;
        }else{
            cout<<"NO WAY"<<endl;
        }
    }
    return 0;
}
