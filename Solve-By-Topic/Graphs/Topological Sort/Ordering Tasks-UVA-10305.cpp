#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll node,edge;
vector<vector<ll> >adj;
vector<bool>visited;
stack<ll>st;

void addEdge(ll u, ll v) {
    adj[u].push_back(v);
}

void topoSort(ll s) {
    visited[s]=true;
    for(auto u:adj[s]) {
        if(!visited[u]) {
            topoSort(u);
        }
    }
    st.push(s);
}

int main() {
    while(cin>>node) {
        if(node==0)
            break;
        cin>>edge;
        adj.assign(node+1,vector<ll>());
        visited.assign(node+1,false);
        while(!st.empty()) {
            st.pop();
        }
        ll a,b;
        for(ll i=0; i<edge; i++) {
            cin>>a>>b;
            addEdge(a,b);
        }
        for(ll i=1; i<=node; i++) {
            if(!visited[i]) {
                topoSort(i);
            }
        }
        ll ct=0;
        while(!st.empty()) {
            if(ct)cout<<" ";
            cout<<st.top();
            st.pop();
            ct++;
        }
        cout<<"\n"<<endl;
    }
    return 0;
}

/**
input::

5 4
1 2
2 3
1 3
1 5
0 0



output::

1 4 2 5 3

**/

