#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=5000000000000000000;

vector<ll>fib;

void inis()
{
    fib.push_back(1);
    fib.push_back(2);
    for(int i=2;fib[fib.size()-1]<MX;i++){
        fib.push_back(fib[i-1]+fib[i-2]);
    }
}

int main()
{
    inis();
    ll n;
    ll vallagna=0;
    while(cin>>n){
        if(vallagna)cout<<"\n";
        vallagna++;
        cout<<n<<"\n";
        ll f=lower_bound(fib.begin(),fib.end(),n)-fib.begin();
        if(fib[f]!=n)f--;
        ll ck=0;
        vector<ll>ans;
        for(int i=f;i>=0;i--){
            if(fib[i]<=n){
                if(ck)cout<<" ";
                else ck++;
                cout<<(i+1);
                n-=fib[i];
                ans.push_back(fib[i]);
            }
        }
        cout<<"\n";
        ck=0;
        for(ll i=0;i<ans.size();i++){
            if(ck)cout<<" ";
            else ck++;
            cout<<ans[i];
        }
        cout<<"\n";
    }
    return 0;
}

