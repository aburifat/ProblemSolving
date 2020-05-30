#include<bits/stdc++.h>
using namespace std;

int node,edge;
vector<vector<int> >adj,revAdj;
vector<bool>visited;
vector<int>order,components;
set<int>can;

void inis() {
    adj.assign(node+1,vector<int>());
    revAdj.assign(node+1,vector<int>());
    visited.assign(node+1,false);
    order.clear();
    components.clear();
    can.clear();
}

void addEdge(int u, int v) {
    adj[u].push_back(v);
    revAdj[v].push_back(u);
}

void orderDfs(int v) {
    visited[v]=true;
    for(auto u:adj[v]) {
        if(!visited[u])
            orderDfs(u);
    }
    order.push_back(v);
}

void sccDfs(int v) {
    visited[v]=true;
    components.push_back(v);
    for(auto u:revAdj[v]) {
        if(!visited[u])
            sccDfs(u);
    }
}

void useComponents() {
    int len=components.size();
    if(len>1) {
        for(auto u:components) {
            can.insert(u);
        }
    }
}

int main() {

    scanf("%d%d",&node, &edge);
    inis();
    int a, b;
    for(int i=0; i<edge; i++) {
        scanf("%d %d",&a, &b);
        a--;b--;
        addEdge(a,b);
    }
    for(int i=0; i<node; i++) {
        if(!visited[i]) {
            orderDfs(i);
        }
    }
    visited.assign(node+1,false);
    int ct=0,s;
    for(int i=0; i<node; i++) {
        s=order[node-1-i];
        if(!visited[s]) {
            sccDfs(s);
            useComponents();
            components.clear();
        }
    }
    int len=can.size();
    printf("%d\n",len);
    if(len>0) {
        int ck=0;
        for(auto u:can) {
            if(ck)
                printf(" ");
            else
                ck++;
            printf("%d",u+1);
        }
        printf("\n");
    }

    return 0;
}


/**

input::

4 5
1 2
3 2
4 3
2 1
3 4

**/
