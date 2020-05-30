#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=LONG_MAX;

vector<vector<pair<ll,ll> > >adj;

void dijkstra(ll s, vector<ll> & d, vector<ll> & p) {
    ll n = adj.size();
    d.assign(n, MX);
    p.assign(n, -1);

    d[s] = 0;
    using pr = pair<ll, ll>;
    priority_queue<pr, vector<pr>, greater<pr> > q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,e,t;
    cin>>n>>e>>t;
    adj.resize(n+1);
    ll m;
    cin>>m;
    ll u,v,w;
    while(m--){
        cin>>u>>v>>w;
        adj[v].push_back({u,w});
    }
    vector<ll>d,p;
    dijkstra(e,d,p);
    ll ans=0;
    for(ll i=0;i<=n;i++){
        if((d[i]<=t)&&(d[i]!=-1))ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
