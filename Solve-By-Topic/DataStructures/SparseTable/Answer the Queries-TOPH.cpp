/*******Bismillahir-Rahmanir-Rahim**********/
/*
Name         : Abu Rifat Muhammed Al Hasib
Institution  : University of Barisal, Bangladesh
Github       : abu-rifat
Codeforces   : AbuRifatMuhammed
AtCoder      : aburifat
codechef     : aburifat
SPOJ         : abu_rifat
Toph         : aburifat
UvaOJ        : aburifat
DevSkill     : abu_rifat
lightoj      : Abu Rifat Muhammed Al Hasib
facebook     : https://www.facebook.com/a.r.m.al.hasib/
linkedin     : https://www.linkedin.com/in/abu-rifat-534258142/
Email        : rifat.cse4.bu@gmail.com, armalhasib@gmail.com
*/

/*
Problem Name    : Ans the Queries
Online Judge    : Toph
Solving Method  : Range Max Query-Sparse Table, Value Mapping, Binary Search
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 10009

ll P[MX][22];
ll arr[MX];
ll LG[MX];
map<ll,ll>M;
vector<ll>V[MX];

void reset(ll n)
{
    M.clear();
    for(ll i=0; i<=(n+1); i++){
        V[i].clear();
        LG[i]=0;
        arr[i]=LONG_LONG_MIN;
        for(ll j=0;j<22;j++){
            P[i][j]=LONG_LONG_MIN;
        }
    }
}

void prep(ll n)
{
    LG[0]=0;
    for(ll i=2;i<=n;i++)
    {
        LG[i]=LG[i/2]+1;
    }
    for(ll i=0; i<n; i++)
    {
        P[i][0]=arr[i];
    }
    for(ll j=1; j<22;j++)
    {
        for(ll i=0; (i+(1<<j))<=n; i++)
        {
            P[i][j]=max(P[i][j-1],P[i+(1<<(j-1))][j-1]);
        }
    }
}

ll Query(ll L, ll R)
{
    ll j=LG[R-L+1];
    ll maxx=max(P[L][j],P[R-(1<<j)+1][j]);
    return maxx;
}

int main()
{
    ll t;
    cin>>t;
    for(ll T=1; T<=t; T++)
    {
        ll n,q;
        cin>>n>>q;
        reset(n);
        ll idx=1;
        for(ll i=0; i<n; i++)
        {
            cin>>arr[i];
            if(!M[arr[i]]){
                M[arr[i]]=idx;
                idx++;
            }
            V[M[arr[i]]].push_back(i);
        }
        prep(n);
        cout<<"Case "<<T<<":"<<endl;
        for(ll i=0; i<q; i++)
        {
            ll L, R;
            cin>>L>>R;
            ll mx=Query(L,R);
            idx=M[mx];
            ll left=lower_bound(V[idx].begin(),V[idx].end(),L)-V[idx].begin();
            ll right=lower_bound(V[idx].begin(),V[idx].end(),(R+1))-V[idx].begin();
            right--;
            ll ans=(right-left+1);
            cout<<ans<<endl;
        }
    }
    return 0;
}
/***********Alhamdulillah***********/
