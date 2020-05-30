
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
Algorithm    : Fibonacci Number with Binary Exponentiation
complexity   : O(logn), where calculating n-th Fibonacci Number.
Problem      : Yet another Number Sequence-UVA-10689
OJ           : UVA
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> fib (ll n,ll mod) {
    if (n == 0)
        return {0,1};

    auto p = fib(n >> 1,mod);
    ll c = (p.first%mod * (2 * p.second - p.first+mod)%mod)%mod;
    ll d = ((p.first * p.first)%mod + (p.second * p.second)%mod)%mod;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

ll M[]={1,10,100,1000,10000};

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll a, b, n, m;
        cin>>a>>b>>n>>m;
        ll mod=M[m];
        if(n<2){
            if(n==0){
                cout<<(a%mod)<<"\n";
            }else{
                cout<<(b%mod)<<"\n";
            }
        }else{
            n--;
            pair<ll,ll> ans=fib(n,mod);
            ll out=((ans.first*a)%mod+(ans.second*b)%mod)%mod;
            cout<<out<<"\n";
        }
    }
    return 0;
}



/***********Alhamdulillah***********/
