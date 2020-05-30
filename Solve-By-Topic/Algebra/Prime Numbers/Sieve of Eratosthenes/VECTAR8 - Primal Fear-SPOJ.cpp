#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=1e6;

bitset<1000009>bs;
vector<ll>primes;
void sieve(ll ub)
{
    bs.set();
    ub++;
    bs[0]=bs[1]=0;
    primes.push_back(2);
    for(ll i=4;i<=ub;i+=2)bs[i]=0;
    for(ll i=3;i<=ub;i+=2){
        if(bs[i]){
            for(ll j=i*i;j<=ub;j+=i)bs[j]=0;
            primes.push_back(i);
        }
    }
}

vector<ll>ans;
bitset<1000009>ck;

void cal(ll n)
{
    if(n>=MX)return;
    if(bs[n]&&ck[n]){
        ans.push_back(n);
        ck[n]=0;
        ll tn=n;
        ll p=1;
        while(tn){
            tn/=10;
            p*=10;
        }
        for(ll i=1;i<=9;i++){
            ll tmp=(i*p)+n;
            cal(tmp);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    sieve(MX);
    ck.set();
    ck[2]=0;
    ans.push_back(2);
    for(ll i=3;i<=9;i++){
        cal(i);
    }
    sort(ans.begin(),ans.end());
    ll t;
    cin>>t;
    ll n;
    while(t--)
    {
        cin>>n;
        ll idx=upper_bound(ans.begin(),ans.end(),n)-ans.begin();
        if(ans[idx]==n){
            idx++;
        }
        cout<<idx<<"\n";
    }
    return 0;
}


