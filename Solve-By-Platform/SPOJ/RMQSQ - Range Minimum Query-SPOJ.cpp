
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
Problem Name    : RMQSQ - Range Minimum Query
Online Judge    : SPOJ
Solving Method  : RMQ with Sparse Table
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100009

ll arr[MX]; // Given array
ll P[MX][22]; //Sparse table
ll LG[MX]; //log array

void inis(ll n) //inis the log array
{
    LG[0]=0;
    for(ll i=2; i<=n; i++){
        LG[i]=LG[i/2]+1;
    }
}

void prep(ll n)
{
    for(ll i=0; i<n; i++)
    {
        P[i][0]=arr[i];
    }
    for(ll j=1;j<=22;j++){
        for(ll i=0;(i+(1<<j))<=n;i++){
            P[i][j]=min(P[i][j-1],P[i+(1<<(j-1))][j-1]);
        }
    }
}

ll Query(ll L, ll R)
{
    if(L>R)swap(L,R);
    ll j=LG[R-L+1];
    ll minimum=min(P[L][j], P[R-(1<<j)+1][j]);
    return minimum;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    inis(n);
    prep(n);
    ll q;
    cin>>q;
    for(int i=0; i<q;i++){
        ll L,R;
        cin>>L>>R;
        //L--;R--; //input is 0 based indexed
        ll ans=Query(L,R);
        cout<<ans<<endl;
    }
    return 0;
}

/***********Alhamdulillah***********/
