#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>pref_f(string s)
{
    ll n=s.size();
    vector<ll>pi(n);
    for(ll i=1;i<n;i++){
        ll j=pi[i-1];
        while(j>0&&s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j])
            j++;
        pi[i]=j;
    }
    return pi;
}


int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n=s.size();
        ll ans=n;
        vector<ll>pi=pref_f(s);
        for(ll i=(n-1);i>=0;i--){
            ll k=(i+1)-pi[i];
            if((i+1)%k==0){
                if((k*2)==(i+1)){
                    ans=k;
                    break;
                }
            }
        }
        string p="";
        for(ll i=n;i<(8+n);i++){
            p+=s[i%ans];
        }
        p+="...";
        cout<<p<<endl;
    }
    return 0;
}

