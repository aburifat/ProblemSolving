#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node;
vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>timeIn, low;
vector<pair<ll,ll> >ans;
ll timer;

void addEdge(ll u, ll v) {
    adj[u].push_back(v);
}

void IS_BRIDGE(ll u, ll v) {
    if(u>v)
        swap(u,v);
    ans.push_back({u,v});
}

void dfs(ll v, ll p=-1) {
    visited[v]=true;
    timeIn[v]=low[v]=timer++;
    for(ll to:adj[v]) {
        if(to==p)
            continue;
        if(visited[to]) {
            low[v]=min(low[v],timeIn[to]);
        } else {
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>timeIn[v])
                IS_BRIDGE(v,to);
        }
    }
}

void find_bridges() {
    timer=0;
    for(ll i=0; i<node; i++) {
        if(!visited[i])
            dfs(i);
    }
}

int main() {
    while(cin>>node) {
        ans.clear();
        adj.assign(node+1,vector<ll>());
        visited.assign(node+1,false);
        timeIn.assign(node+1,-1);
        low.assign(node+1,-1);
        ll a,b,m;
        for(ll i=0; i<node; i++) {
            cin>>a;
            getchar();
            getchar();
            cin>>m;
            getchar();

            for(ll j=0; j<m; j++) {
                cin>>b;
                addEdge(a,b);
            }
        }
        find_bridges();
        sort(ans.begin(),ans.end());
        ll len=ans.size();
        cout<<len<<" critical links"<<endl;
        for(ll i=0; i<len; i++) {
            cout<<ans[i].first<<" - "<<ans[i].second<<endl;
        }
        cout<<endl;
    }
    return 0;
}


/**

input::

8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)

0

output::



**/
