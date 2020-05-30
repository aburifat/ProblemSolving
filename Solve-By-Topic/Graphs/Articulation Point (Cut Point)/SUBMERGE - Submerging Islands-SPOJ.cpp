#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll node,edge;
vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>timeIn,low;
set<ll>cutPoints;
ll timer;

void addEdge(ll u, ll v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void inis()
{
    adj.assign(node+1, vector<ll>());
    visited.assign(node+1, false);
    timeIn.assign(node+1, -1);
    low.assign(node+1, -1);
    cutPoints.clear();
    timer=0;
}

void isCutPoint(ll v)
{
    cutPoints.insert(v);
}

void dfs(ll v, ll p=-1)
{
    visited[v]=true;
    timeIn[v]=low[v]=timer++;
    ll child=0;
    for(auto to:adj[v]){
        if(to==p)continue;
        if(visited[to]){
            low[v]=min(low[v],timeIn[to]);
        }
        else{
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>=timeIn[v]&&p!=-1){
                isCutPoint(v);
            }
            child++;
        }
    }
    if(p==-1&&child>1){
        isCutPoint(v);
    }
}

int main()
{
    while(cin>>node){
        cin>>edge;
        if(node==0&&edge==0)break;
        inis();
        ll a,b;
        for(ll i=0; i<edge;i++){
            cin>>a>>b;
            addEdge(a,b);
        }
        for(ll i=1;i<=node;i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        ll len=cutPoints.size();
        cout<<len<<endl;
    }
    return 0;
}
