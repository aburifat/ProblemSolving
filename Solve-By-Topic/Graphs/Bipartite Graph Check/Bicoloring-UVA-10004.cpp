#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>color;

void addEdge(ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isBip(ll s)
{
    for(auto u : adj[s]){
        if(visited[u]==false){
            visited[u]=true;
            color[u]=!color[s];
            if(!isBip(u))
                return false;
        }
        else if(color[u]==color[s])
            return false;
    }
    return true;
}


int main()
{
    ll node, edge, u, v;
    while(cin>>node){
        if(node==0)break;

        adj.assign(node+1,vector<ll>());
        visited.assign(node+1,false);
        color.assign(node+1,0);

        cin>>edge;
        for(ll i=0;i<edge;i++)
        {
            cin>>u>>v;
            addEdge(u,v);
        }
        visited[0]=true;
        color[0]=0;
        if(isBip(0))cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;
    }
    return 0;
}


