#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DX[]= {0,0,1,-1};
const ll DY[]= {1,-1,0,0};

ll n,m;
ll dis[1009][1009];
char cell[1009][1009];



void bfs(ll si, ll sj) {
    dis[si][sj]=0;
    deque<pair<ll,ll> >q;
    pair<ll,ll>s;
    q.push_front({si,sj});
    while(!q.empty()) {
        s=q.front();
        q.pop_front();
        ll i=s.first;
        ll j=s.second;
        //pair<ll,ll> v;
        for(ll kk=0; kk<4; kk++) {
            ll x=i+DX[kk];
            ll y=j+DY[kk];
            if(x>=0&&y>=0&&x<n&&y<m) {
                //v = {x,y};
                ll w=(cell[i][j]==cell[x][y])?0:1;
                if(dis[i][j]+w<dis[x][y]) {
                    dis[x][y]=dis[i][j]+w;
                    if(w==1)
                        q.push_back({x,y});
                    else
                        q.push_front({x,y});
                }
            }
        }
    }
}


int main() {
    int t;
    char ch;
    scanf("%d",&t);
    while(t--) {
        scanf("%lld %lld",&n,&m);
        scanf("%c",&ch);
        for(ll i=0; i<n; i++) {
            for(ll j=0; j<m; j++) {
                scanf("%c",&cell[i][j]);
                dis[i][j]=LONG_MAX;
            }
            scanf("%c",&ch);
        }
        bfs(0,0);
        cout<<dis[n-1][m-1]<<endl;
    }
    return 0;
}

/**
Input::

4
2 2
aa
aa
2 3
abc
def
6 6
akaccc
aaacfc
amdfcc
aokhdd
zyxwdp
zyxwdd
5 5
abbbc
abacc
aaacc
aefci
cdgdd

*/

