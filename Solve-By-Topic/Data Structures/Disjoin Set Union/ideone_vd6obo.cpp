/*
    Sk arman Hossain
    University of Barisal
    Problem name : spoj_CLFLARR_Colorful_Array
    Solution : DSU
 */
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define N 200010
ll rep[N+10];
ll ar[N+10];
ll Find(ll node)
{
    return (rep[node]==node)?node:rep[node]=Find(rep[node]);
}
void joint (ll u,ll v)
{
    ll ru=Find(u);
    ll rv=Find(v);
    if(ru!=rv)
    {
        rep[rv]=max(ru,rv)+1;
        rep[ru]=max(ru,rv)+1;
    }
    else
    {
        rep[ru]=ru+1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    /freopen("1input.txt","r",stdin);
//    /freopen("1output.txt","w",stdout);

    ll tcase=1;
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector< pair < pair<ll,ll>,ll > > V;
        ll n,q;
        cin>>n>>q;
        for(ll i=0; i<=n+10; i++)
        {
            rep[i]=i;
            ar[i]=0;
        }
        for(ll i=0; i<q; i++)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            V.push_back({{a,b},c});
        }
        reverse(V.begin(),V.end());
        for(ll i=0; i<q; i++)
        {
            ll l=V[i].first.first;
            ll r=V[i].first.second;
            ll val=V[i].second;
            ll re=Find(l);
            while(re<=r)
            {
                //cout<<re<<" t "<<i<<"\n";
                if(ar[re]==0)
                {
                    ar[re]=val;
                }
                ll tm=Find(re);
                joint(re,tm);
                re=Find(re);
                //cout<<tm<<" tt "<<re<<"\n";
            }
        }
        for(ll i=1; i<=n; i++)
        {
            cout<<ar[i]<<"\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
    return 0;
}
/*
4 3
1 3 2
2 4 6
2 3 7
*/