#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>pref_f(string s)
{
    ll n=s.size();
    vector<ll>pi(n);
    for(ll i=1; i<n; i++)
    {
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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    ll ck=0;
    while(cin>>n){
        if(ck){
           cout<<endl;
        }else{
            ck++;
        }
        string patt;
        cin>>patt;
        getchar();
        ll plen=patt.size();
        patt+="#";
        vector<ll>pi=pref_f(patt);
        char ch;
        ll txtpi=0;
        vector<ll>ans;
        ll i=0;
        while(1){
            ch=getchar();
            if(ch==10)break;
            ll j=txtpi;
            while(j>0&&ch!=patt[j])
                j=pi[j-1];
            if(ch==patt[j])
                j++;
            txtpi=j;
            if(txtpi==plen)ans.push_back(i-plen+1);
            i++;
        }
        ll len=ans.size();
        if(len){
            //cout<<len<<endl;
            for(ll i=0; i<len;i++){
                cout<<ans[i]<<endl;
            }
        }
    }
}
