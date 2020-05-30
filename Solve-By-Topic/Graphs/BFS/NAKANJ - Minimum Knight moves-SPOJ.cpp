#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int KX[]={-1,1,-2,2,-2,2,-1,1};
const int KY[]={2,2,1,1,-1,-1,-2,-2};



ll bfs(string s, string d)
{
    int sx=s[0]-'a';
    int sy=s[1]-'1';
    int dx=d[0]-'a';
    int dy=d[1]-'1';
    if((sx==dx)&&(sy==dy))return 0;
    map<pair<int,int>, ll>moves,visited;
    moves[{sx,sy}]=0;
    queue<pair<int,int> >q;
    q.push({sx,sy});
    pair<int,int>pr;
    int ux,uy;
    while(!q.empty()){
        pr=q.front();
        sx=pr.first;
        sy=pr.second;
        visited[pr]=1;
        q.pop();
        for(int i=0; i<8; i++){
            ux=sx+KX[i];
            uy=sy+KY[i];
            if((ux>=0)&&(ux<8)&&(uy>=0)&&(uy<8)&&(!visited[{ux,uy}])){
                moves[{ux,uy}]=moves[pr]+1;
                if((dx==ux)&&(dy==uy))return moves[{ux,uy}];
                q.push({ux,uy});
            }
        }
    }
}

int main()
{
    ll t;
    cin>>t;
    while(t--){
        string s,d;
        cin>>s>>d;
        ll ans=bfs(s,d);
        cout<<ans<<endl;
    }
    return 0;
}
