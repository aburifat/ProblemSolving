#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
const ll MX=1000010;

bitset<1000010>visited;
ll str[MX];
bool problem;
vector<ll>adj[MX], curr;

void bfs(ll parent,ll strength) {
    if(strength==0) {
        if(visited[parent]==true) {
            problem=true;
            return;
        } else {
            visited[parent]=true;
            return;
        }
    }
    str[parent]=0;
    queue<ll>q;
    visited[parent]=true;
    q.push(parent);
    while(!q.empty()) {
        parent=q.front();
        curr.pb(parent);
        q.pop();
        ll siz=adj[parent].size();
        for(ll i=0; i<siz; i++) {
            ll child=adj[parent][i];
            if(str[parent]<strength&&str[child]==-1) {
                if(visited[child]==true) {
                    problem=true;
                    return;
                }
                str[child]=str[parent]+1;
                visited[child]=true;
                q.push(child);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--) {
        ll node, edge, man;
        cin>>node>>edge>>man;
        for(ll i=0; i<=node; i++) {
            visited[i]=false;
            adj[i].clear();
            str[i]=-1;
        }
        for(ll i=0; i<edge; i++) {
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        problem=false;
        for(ll i=0; i<man; i++) {
            ll k,s;
            cin>>k>>s;
            if(!problem) {
                curr.clear();
                bfs(k,s);
                ll siz=curr.size();
                for(ll j=0; j<siz; j++) {
                    str[curr[j]]=-1;
                }
            }
        }
        if(!problem) {
            for(ll i=1; i<node; i++) {
                if(visited[i]==false) {
                    problem=true;
                    break;
                }
            }
        }

        if(problem){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
        }
    }

    return 0;
}
