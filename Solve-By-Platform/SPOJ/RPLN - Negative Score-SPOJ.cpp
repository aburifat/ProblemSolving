/*******Bismillahir-Rahmanir-Rahim**********/
/*
Name         : Abu Rifat Muhammed Al Hasib
Institution  : University of Barisal, Bangladesh
Github       : abu-rifat
Codeforces   : AbuRifatMuhammed
AtCoder      : aburifat
codechef     : aburifat
SPOJ         : abu_rifat
UvaOJ        : aburifat
DevSkill     : abu_rifat
lightoj      : Abu Rifat Muhammed Al Hasib
facebook     : https://www.facebook.com/a.r.m.al.hasib/
linkedin     : https://www.linkedin.com/in/abu-rifat-534258142/
Email        : rifat.cse4.bu@gmail.com, armalhasib@gmail.com
*/

/*
Problem Name    : RPLN - Negative Score
Online Judge    : SPOJ
Solving Method  : RMQ with Sparse Table
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100009

ll arr[MX];
ll P[MX][22];
ll LG[MX];

void reset(ll n)
{
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<22;j++){
            P[i][j]=0;
        }
    }
}

void prep(ll n)
{
    for(ll i=2; i<=n; i++)LG[i]=LG[i/2]+1;
    for(ll i=0; i<n; i++)P[i][0]=arr[i];
    for(ll j=1;j<22;j++){
        for(ll i=0;i<=n-(1<<j);i++){
            P[i][j]=min(P[i][j-1],P[i+(1<<(j-1))][j-1]);
        }
    }
}

ll Query(ll L, ll R)
{
    if(L>R)swap(L,R);
    ll j=LG[R-L+1];
    ll minn=min(P[L][j],P[R-(1<<j)+1][j]);
    return minn;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        cout<<"Scenario #"<<T<<":"<<endl;
        ll n,q;
        cin>>n>>q;
        reset(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        prep(n);
        for(ll i=0;i<q;i++){
            ll L,R;
            cin>>L>>R;
            L--;R--;
            ll ans=Query(L,R);
            cout<<ans<<endl;
        }
    }
    return 0;
}

/***********Alhamdulillah***********/
