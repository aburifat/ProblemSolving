#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bitset<10000009>bs;
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

vector<ll>num1,num2;
bitset<10000009>ck;
vector<ll>ans;
void cal(ll ub)
{
    ck.set();
    ll n=1e7;
    ll sq=sqrt(ub)+1;
    ll sqq=sqrt(sq)+1;
    for(ll i=1;i<=sq;i++){
        num1.push_back(i*i);
    }
    for(ll i=1;i<=sqq;i++){
        ll num=num1[i-1];
        num2.push_back(num*num);

    }
    ll len1=num1.size();
    ll len2=num2.size();
    for(ll i=0;i<len1;i++){
        for(ll j=0;j<len2;j++){
            ll num=num1[i]+num2[j];
            if(num>n)break;
            if(bs[num]&&ck[num]){
                ck[num]=0;
                ans.push_back(num);
            }
        }
    }
    sort(ans.begin(),ans.end());
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n=1e7;
    sieve(n);
    cal(n);
    ll t;
    cin>>t;
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

