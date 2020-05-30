#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=35;

ll L[MX],U[MX],EX[MX];

void inis()
{
    L[1]=U[1]=1;
    L[2]=U[2]=2;
    EX[1]=2;
    EX[2]=4;
    for(ll i=3;i<=30;i++)
    {
        L[i]=U[i-1]+L[i-1];
        U[i]=L[i-1]+L[i-2];
        EX[i]=EX[i-1]*2;
    }
}

int main()
{
    ll n;
    inis();
    while(cin>>n){
        if(n==0)break;
        cout<<(EX[n]-L[n]-U[n])<<endl;
    }
    return 0;
}
