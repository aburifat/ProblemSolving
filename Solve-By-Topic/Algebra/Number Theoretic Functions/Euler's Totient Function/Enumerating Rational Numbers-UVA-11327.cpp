#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX = 200000;

vector<ll> phi,sumPhi;

void phi_1_to_n(ll n) {
    phi.resize(n+1);
    sumPhi.resize(n+1);
    phi[0]=0;
    phi[1]=1;
    sumPhi[0]=0;
    sumPhi[1]=1;
    for(ll i=2; i<=n; i++)
        phi[i]=i;
    for(ll i=2; i<=n; i++) {
        if(phi[i]==i) {
            for(ll j=i; j<=n; j+=i)
                phi[j]-=(phi[j]/i);
        }
        sumPhi[i]=sumPhi[i-1]+phi[i];
    }
}

ll kthCoPrime(ll n, ll k) {
    bitset<200010>bs;
    bs.set();
    ll ct=0;
    if(k==1)
        return 1;
    k--;
    bs[0]=0;
    bs[1]=1;
    for(ll i=2; i<=n; i++) {
        if(bs[i]) {
            if(n%i==0) {
                bs[i]=0;
                for(ll j=2*i; j<=n; j+=i) {
                    bs[j]=0;
                }
            } else {
                ct++;
                if(ct==k){
                    return i;
                }
            }
        }
    }
}


int main() {
    phi_1_to_n(MX);
    ll k;
    while(cin>>k) {
        if(k==0)
            break;
        if(k==1) {
            cout<<"0/1"<<endl;
            continue;
        }
        k--;
        ll lowidx=lower_bound(sumPhi.begin(),sumPhi.end(),k)-sumPhi.begin();
        ll num=lowidx;
        ll rem=k-sumPhi[lowidx-1];
        ll ans=kthCoPrime(num,rem);
        cout<<ans<<"/"<<num<<endl;
    }
    return 0;
}
