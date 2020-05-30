#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node, edge;
vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>timeIn,low,par;
ll timer;
ll bridge[1009][1009],edges[1009][1009];


void addEdge(ll u, ll v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs1(ll v, ll p = -1) {
    visited[v] = true;
    timeIn[v] = low[v] = timer++;
    for(auto to:adj[v]) {
        if(to==p)
            continue;
        if(visited[to]) {
            low[v]=min(low[v],timeIn[to]);
        } else {
            dfs1(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>timeIn[v]) {
                bridge[v][to]=1;
                bridge[to][v]=1;
                printf("%lld %lld\n",v,to);
                printf("%lld %lld\n",to,v);
            }
        }
    }
}

void dfs2(ll v) {
    for(auto u:adj[v]) {
        if((edges[v][u]==0)&&(par[v]!=u)&&(bridge[v][u]==0)) {
            edges[v][u]=1;
            edges[u][v]=1;
            par[u]=v;
            printf("%lld %lld\n",v,u);
            dfs2(u);
        }
    }
    visited[v]=true;
}

void inis()
{
    for(ll i=0;i<=node;i++){
        for(ll j=0;j<=node;j++){
            edges[i][j]=0;
            bridge[i][j]=0;
        }
    }
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    timeIn.assign(node+1,-1);
    low.assign(node+1,-1);
    par.assign(node+1,-1);
}


int main() {
    ll t=1;
    while(cin>>node) {
        scanf("%lld",&edge);
        if(node==0&&edge==0)
            break;
        inis();
        ll a,b;
        for(ll i=0; i<edge; i++) {
            scanf("%lld%lld",&a,&b);
            addEdge(a,b);
        }
        printf("%lld\n\n",t++);
        timer=0;
        for(ll i=1; i<=node; i++) {
            if(!visited[i]) {
                dfs1(i);
            }
        }
        visited.assign(node+1,false);
        for(ll i=1; i<=node; i++) {
            if(!visited[i]) {
                dfs2(i);
            }
        }
        printf("#\n");
    }
    return 0;
}


/**

Input::

7 10
1 2
1 3
2 4
3 4
4 5
4 6
5 7
6 7
2 5
3 6
7 9
1 2
1 3
1 4
2 4
3 4
4 5
5 6
5 7
7 6
0 0


output::


**/
