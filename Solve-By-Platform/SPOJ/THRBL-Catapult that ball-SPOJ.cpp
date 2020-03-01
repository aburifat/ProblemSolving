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
Problem Name    : THRBL - Catapult that ball
Online Judge    : SPOJ
Solving Method  : Range Maximum Query-SparseTable

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100009

ll arr[MX]; // Given array
ll P[MX][22]; //Sparse table
ll LG[MX]; //log array

void prep(ll n)
{
    LG[0]=0;
    for(ll i=2; i<=n; i++){
        LG[i]=LG[i/2]+1;
    }
    for(ll i=0; i<n; i++)
    {
        P[i][0]=arr[i];
    }
    for(ll j=1;j<=22;j++){
        for(ll i=0;(i+(1<<j))<=n;i++){
            P[i][j]=max(P[i][j-1],P[i+(1<<(j-1))][j-1]);
        }
    }
}

ll Query(ll L, ll R, ll Pr)
{
    if(L>R)swap(L,R);
    if((R-L)<2)return 1;
    L++;R--;
    //if(L<0||R<0||(L>R))return 0;
    ll j=LG[R-L+1];
    ll maximum=max(P[L][j], P[R-(1<<j)+1][j]);
    if(maximum<=arr[Pr])return 1;
    else return 0;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n,q;
    cin>>n>>q;
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    prep(n);
    ll ans=0;
    for(int i=0; i<q;i++){
        ll L,R;
        cin>>L>>R;
        L--;R--;
        ans+=Query(L,R,L);
    }
    cout<<ans<<endl;
    return 0;
}

/***********Alhamdulillah***********/
