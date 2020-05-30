#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node, edge;

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
    for(auto u:adj[s]){
        if(!visited[u]){
            visited[u]=true;
            color[u]=!color[s];
            if(!isBip(u))return false;
        }
        else if(color[u]==color[s])
            return false;
    }
    return true;
}


int main()
{
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        cin>>node>>edge;
        adj.assign(node+1,vector<ll>());
        visited.assign(node+1,false);
        color.assign(node+1,0);
        ll a,b;
        for(ll i=0;i<edge;i++){
            cin>>a>>b;
            addEdge(a,b);
        }
        bool ck=true;
        for(ll i=1;i<node;i++){
            if(!visited[i]){
                visited[i]=true;
                color[i]=0;
                if(!isBip(i)){
                    ck=false;
                    break;
                }
            }
        }
        cout<<"Scenario #"<<T<<":\n";
        if(ck) cout<<"No suspicious bugs found!\n"<<endl;
        else cout<<"Suspicious bugs found!\n"<<endl;
    }
    return 0;
}
