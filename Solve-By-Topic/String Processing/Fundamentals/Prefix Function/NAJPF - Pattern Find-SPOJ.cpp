#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>pref_f(string s)
{
    ll n=s.size();
    vector<ll>pi(n);
    for(ll i=1;i<n;i++)
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
    ll t;
    cin>>t;
    while(t--){
        ll st=0;
        string patt,text;
        cin>>text>>patt;
        ll lt=text.size();
        ll lp=patt.size();
        if(lp>lt){
            cout<<"Not Found"<<endl;
        }else{
            patt+="#";
            vector<ll>pi=pref_f(patt);
            vector<ll>ans;
            ll textpi=0;
            for(ll i=0;i<lt;i++){
                ll j=textpi;
                while(j>0&&text[i]!=patt[j])
                    j=pi[j-1];
                if(text[i]==patt[j])
                    j++;
                textpi=j;
                if(textpi==lp)
                    ans.push_back(i-lp+2);
            }
            ll len=ans.size();
            if(len){
                cout<<len<<endl;
                for (ll i=0;i<len;i++){
                    cout <<ans[i];
                    if(i==(len-1))cout<<endl;
                    else cout<<" ";
                }
            }else{
                cout<<"Not Found"<<endl;
            }
        }
        if(t)cout<<endl;
    }
    return 0;
}
