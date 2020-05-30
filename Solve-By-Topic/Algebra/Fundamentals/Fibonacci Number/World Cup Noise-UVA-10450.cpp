#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=55;

vector<ll>fib;

void inis()
{
    fib.push_back(1);
    fib.push_back(2);
    for(int i=2;i<=MX;i++){
        fib.push_back(fib[i-1]+fib[i-2]);
    }
}

int main()
{
    inis();
    ll n,T;
    ll t=1;
    cin>>T;
    while(T--){
        cin>>n;
        cout<<"Scenario  #"<<t++<<":\n";
        cout<<fib[n]<<"\n\n";
    }
    return 0;
}


