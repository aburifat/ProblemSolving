#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node, edge;
vector<vector<ll> >adj,revAdj;
vector<bool>visited;
vector<ll>order;
vector<string>component;
map<string,ll>user;
map<ll,string>revUser;
ll userCt;
ll ckDup[30][30];

void inis()
{
    for(ll i=0;i<=node;i++){
        for(ll j=0; j<=node;j++){
            ckDup[i][j]=0;
        }
    }
    adj.assign(node+1,vector<ll>());
    revAdj.assign(node+1,vector<ll>());
    visited.assign(node+1, false);
    order.clear();
    component.clear();
    user.clear();
    revUser.clear();
    userCt=1;
}

void addEdge(ll u, ll v)
{
    if(ckDup[u][v]==0){
        adj[u].push_back(v);
        revAdj[v].push_back(u);
        ckDup[u][v]=1;
    }
}

ll val(string s)
{
    if(user[s]!=0)return user[s];
    else{
        user[s]=userCt++;
        revUser[user[s]]=s;
        return user[s];
    }
}

void dfs1(ll s)
{
    visited[s]=true;
    for(auto u:adj[s]){
        if(!visited[u])
            dfs1(u);
    }
    order.push_back(s);
}

void dfs2(ll s)
{
    visited[s]=true;
    component.push_back(revUser[s+1]);
    for(auto u:revAdj[s]){
        if(!visited[u])
            dfs2(u);
    }
}

void useComponent()
{
    ll t=0;
    for(auto u:component){
        if(t)cout<<", ";
        else t++;
        cout<<u;
    }
    cout<<endl;
}

int main()
{
    ll t=1;
    while(cin>>node){
        cin>>edge;
        if(node==0&&edge==0)break;
        if(t>1)cout<<"\n";
        inis();
        string a,b;
        ll u, v;
        for(ll i=0; i<edge; i++){
            cin>>a>>b;
            u=val(a);
            v=val(b);
            u--;v--;
            addEdge(u,v);
        }

        cout<<"Calling circles for data set "<<t<<":\n";
        t++;

        for(ll i=0; i<node;++i){
        if(!visited[i])
            dfs1(i);
    }
    visited.assign(node+1,false);
    for(ll i=0; i<node;++i){
        ll s=order[node-1-i];
        if(!visited[s]){
            dfs2(s);
            useComponent();
            component.clear();
        }
    }
    }
    return 0;
}



/**

14 34
John Aaron
Aaron Benedict
Betsy John
Betsy Ringo
Ringo Dolly
Benedict Paul
John Betsy
John Aaron
Benedict George
Dolly Ringo
Paul Martha
George Ben
Alexander George
Betsy Ringo
Alexander Stephen
Martha Stephen
Benedict Alexander
Stephen Paul
Betsy Ringo
Quincy Martha
Ben Patrick
Betsy Ringo
Patrick Stephen
Paul Alexander
Patrick Ben
Stephen Quincy
Ringo Betsy
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Quincy Martha

5 6
Ben Alexander
Alexander Dolly
Dolly Ben
Dolly Benedict
Benedict Dolly
Alexander Aaron

**/
