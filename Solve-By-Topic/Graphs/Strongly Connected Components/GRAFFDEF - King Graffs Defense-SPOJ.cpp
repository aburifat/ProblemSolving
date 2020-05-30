#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node,edge;
vector<vector<ll> >adj;
vector<bool>visited;
vector<ll>timeIn,low,par;
map<pair<ll,ll>,bool>bridge;
set<ll>components;
ll timer;

void addEdge(ll u, ll v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void inis()
{
    adj.assign(node+1,vector<ll>());
    visited.assign(node+1,false);
    timeIn.assign(node+1,-1);
    low.assign(node+1,-1);
    par.assign(node+1,-1);
    timer=0;
}

void dfs(ll v, ll p=-1)
{
    visited[v]=true;
    timeIn[v]=low[v]=timer++;
    for(auto to:adj[v])
    {
        if(to==p)continue;
        if(visited[to]){
            low[v]=min(low[v],timeIn[to]);
        }else{
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>timeIn[v]){
                bridge[{v,to}]=true;
                bridge[{to,v}]=true;
            }
        }
    }
}

void dfs2(ll v)
{
    visited[v]=true;
    for(auto to:adj[v]){
        if(to==par[v])continue;
        if(!visited[to])
        {
            par[to]=v;
            if(bridge[{v,to}]!=true){
                dfs2(to);
            }
        }
    }
    components.insert(v);
}


int main()
{
    cin>>node>>edge;
    inis();
    ll a, b;
    for(ll i=0; i<edge;i++){
        cin>>a>>b;
        addEdge(a,b);
    }
    for(ll i=1;i<=node;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    visited.assign(node+1,false);
    vector<ll>ans;
    ll ct;
    for(ll i=1;i<=node;i++){
        if(!visited[i]){
            components.clear();
            dfs2(i);
            ll ct=components.size();
            ans.push_back(ct);
        }
    }
    ll len=ans.size();
    ll qsum[len+5];
    qsum[0]=ans[0];
    for(ll i=1;i<len;i++){
        qsum[i]=qsum[i-1]+ans[i];
    }
    ll res=0;
    for(ll i=0;i<(len-1);i++){
        res+=(ans[i]*(qsum[len-1]-qsum[i]));
    }
    ll resf=node;
    if(resf%2==0){
        resf/=2;
        resf*=(node-1);
    }else{
        resf*=((node-1)/2);
    }
    double pp=(double)res/(double)resf;
    printf("%.5f\n",pp);
    return 0;
}

/**
input::

12 13
1 2
1 3
2 4
3 4
4 5
5 6
5 7
6 7
6 9
9 10
10 11
10 12
11 12


**/
