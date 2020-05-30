#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>prefix(string s) {
    ll n=s.size();
    vector<ll>pi(n);
    for(ll i=1; i<n; i++) {
        ll j=pi[i-1];
        while(j>0&&s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j])
            j++;
        pi[i]=j;
    }
    return pi;
}

int main() {
    ll t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        vector<ll>pi=prefix(s);
        ll n=s.size();
        ll k=n-pi[n-1];
        k=n%k==0?k:n;
        cout<<k<<endl<<endl;
    }

    return 0;
}
