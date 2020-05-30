#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>par,dist;

void addEdge(ll u, ll v)
{
    adj[u].push_back(v);
}

void bfs(ll s)
{
    dist[s]=0;
    //par[s]=-1;
    visited[s]=true;
    queue<ll>q;
    q.push(s);
    while(!q.empty())
    {
        ll s=q.front();
        q.pop();
        ll d=dist[s];
        for(auto u=adj[s].begin();u!=adj[s].end();u++)
        {
            if(!visited[*u]){
                visited[*u]=true;
                dist[*u]=d+1;
                par[*u]=s;
                q.push(*u);
            }
        }
    }
}

void printpath(ll u)
{
    if(u==-1)return;
    else{
        printpath(par[u]);
        cout<<u<<" ";
    }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        adj.assign(n+1,vector<ll>());
        visited.assign(n+1,false);
        dist.assign(n+1,LONG_MAX);
        par.assign(n+1,-1);
        ll m,u;
        for(ll i=1;i<n;i++){
            cin>>m;
            set<ll>st;
            while(m--){
                cin>>u;
                st.insert(u);
            }
            for (auto it=st.begin();it!=st.end();++it){
                addEdge(i,*it);
            }
        }
        bfs(1);
        if(visited[n]){
            cout<<dist[n]<<endl;
            n=par[n];
            printpath(par[n]);
            cout<<n<<endl;
        }else{
            cout<<"-1"<<endl;
        }
        if(T)cout<<endl;
    }
    return 0;
}
