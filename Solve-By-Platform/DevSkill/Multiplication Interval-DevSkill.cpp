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
Problem Name    : Multiplication Interval
Online Judge    : DevSkill
Solving Method  : Range Minimum & Maximum Query-Sparse Table
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100009
#define pr pair<ll,ll>

ll arr[MX],za[MX];
pr P[MX][22],Z[MX][22];
ll LG[MX];


void reset(ll n)
{
    for(ll i=0;i<=n;i++){
        arr[i]=0;
        za[i]=0;
        LG[i]=0;
        for(ll j=0;j<22;j++){
            P[i][j]=make_pair(0,0);
            Z[i][j]=make_pair(0,0);
        }
    }
}

void inis(ll n)
{
    LG[0]=0;
    for(ll i=2; i<=n; i++)
    {
        LG[i]=LG[i/2]+1;
    }
}

void prep(ll n)
{
    for(ll i=0; i<n; i++)
    {
        P[i][0]=make_pair(arr[i],i);
    }
    for(ll j=1; j<=22; j++)
    {
        for(ll i=0; (i+(1<<j))<=n; i++)
        {
            if(P[i][j-1].first<=P[i+(1<<(j-1))][j-1].first)
            {
                P[i][j]=P[i][j-1];
            }
            else
            {
                P[i][j]=P[i+(1<<(j-1))][j-1];
            }

        }
    }
}

void prepz(ll n)
{
    for(ll i=0; i<n; i++)
    {
        Z[i][0]=make_pair(za[i],i);
    }
    for(ll j=1; j<=22; j++)
    {
        for(ll i=0; (i+(1<<j))<=n; i++)
        {
            if(Z[i][j-1].first>=Z[i+(1<<(j-1))][j-1].first)
            {
                Z[i][j]=Z[i][j-1];
            }
            else
            {
                Z[i][j]=Z[i+(1<<(j-1))][j-1];
            }

        }
    }
}

pr Query(ll L, ll R)
{
    if(L>R)
        swap(L,R);
    ll j=LG[R-L+1];
    pr minn;
    if(P[L][j].first<=P[R-(1<<j)+1][j].first)
    {
        minn=P[L][j];
    }
    else
    {
        minn=P[R-(1<<j)+1][j];
    }
    return minn;
}

pr Queryz(ll L, ll R)
{
    if(L>R)
        swap(L,R);
    ll j=LG[R-L+1];
    pr maxx;
    if(Z[L][j].first>=Z[R-(1<<j)+1][j].first)
    {
        maxx=Z[L][j];
    }
    else
    {
        maxx=Z[R-(1<<j)+1][j];
    }
    return maxx;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    for(ll T=1; T<=t; T++)
    {

        cout<<"Case "<<T<<":"<<endl;
        ll n,q;
        cin>>n>>q;
        reset(n);
        for(ll i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        ll kt=0;
        for(ll i=0; i<n; i++)
        {
            if(arr[i]==1)
            {
                za[i]=kt+1;
                kt++;
            }
            else
            {
                za[i]=0;
                kt=0;
            }
        }
        inis(n);
        prep(n);
        prepz(n);
        for(int i=0; i<q; i++)
        {
            ll L,R;
            cin>>L>>R;
            L--;
            R--;
            pr ans=Query(L,R);
            if(ans.first==0)
            {
                if(L>R)
                    swap(L,R);
                cout<<ans.first<<" "<<(L+1)<<" "<<(R+1)<<endl;
            }
            else if(ans.first>1)
            {
                cout<<ans.first<<" "<<(ans.second+1)<<" "<<(ans.second+1)<<endl;
            }
            else
            {
                pr ans2=Queryz(L,R);
                if(L>R)
                    swap(L,R);
                cout<<ans.first<<" "<<max((ans2.second-ans2.first+2),(L+1))<<" "<<(ans2.second+1)<<endl;
            }
        }
    }
    return 0;
}


/***********Alhamdulillah***********/
