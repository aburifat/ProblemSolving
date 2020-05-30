#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=1000000009;

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
    cin>>n;
    ll num;
    while(n--){
        cin>>num;
        cout<<num<<" = ";
        ll f=lower_bound(fib.begin(),fib.end(),num)-fib.begin();
        if(fib[f]!=num)f--;
        for(ll i=f;i>=0;i--){
            if(fib[i]<=num){
                cout<<"1";
                num-=fib[i];
            }else{
                cout<<"0";
            }
        }
        cout<<" (fib)\n";
    }
    return 0;
}
