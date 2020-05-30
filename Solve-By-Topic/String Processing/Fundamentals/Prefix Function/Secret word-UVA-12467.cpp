#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,ll>pref_f(string s)
{
    ll n=s.size();
    vector<ll>pi(n);
    ll prevpi=0;
    ll idx=0;
    ll val=0;
    for(ll i=(n-1);i>=0;i--)
    {
        ll j=prevpi;
        while(j>0&&s[i]!=s[j])
            j=pi[j+1];
        if(s[i]==s[j])
            j++;
        pi[i]=j;
        prevpi=j;
        if(j>val){
            val=j;
            idx=i;
        }
    }
    return {idx,val};
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n=s.size();
        pair<ll,ll>pr=pref_f(s);
        ll idx=pr.first;
        ll val=pr.second;
        //cout<<idx<<" "<<val<<endl;
        for(ll i=idx;i<(idx+val);i++){
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
