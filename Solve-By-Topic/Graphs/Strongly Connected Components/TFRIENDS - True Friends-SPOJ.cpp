#include<bits/stdc++.h>
using namespace std;

int node;
vector<vector<int> >adj,revAdj;
vector<bool>visited;
vector<int>order;

void inis()
{
    adj.assign(node+1,vector<int>());
    revAdj.assign(node+1,vector<int>());
    visited.assign(node+1,false);
    order.clear();
}

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    revAdj[v].push_back(u);
}

void orderDfs(int v)
{
    visited[v]=true;
    for(auto u:adj[v]){
        if(!visited[u])
            orderDfs(u);
    }
    order.push_back(v);
}

void sccDfs(int v)
{
    visited[v]=true;
    for(auto u:revAdj[v]){
        if(!visited[u])
            sccDfs(u);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&node);
        inis();
        for(int i=0; i<node;i++){
            getchar();
            for(int j=0; j<node; j++){
                if(getchar()=='Y'){
                    addEdge(i,j);
                }
            }
        }
        for(int i=0; i<node;i++){
            if(!visited[i]){
                orderDfs(i);
            }
        }
        visited.assign(node+1,false);
        int ct=0,s;
        for(int i=0; i<node; i++){
            s=order[node-1-i];
            if(!visited[s]){
                sccDfs(s);
                ct++;
            }
        }
        printf("%d\n",ct);
    }
    return 0;
}
