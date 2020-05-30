#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define all(v) v.begin(),v.end()
#define pb push_back

const ll MX=30000;

ll n, arr[MX+10];
vector<ll>sTree[3*MX+10];

void build(ll v, ll l, ll r)
{
    if(l==r)sTree[v].pb(arr[l]);
    else{
        ll left=v*2;
        ll right=left+1;
        ll mid=l+(r-l)/2;
        build(left,l,mid);
        build(right,mid+1,r);
        merge(all(sTree[left]),all(sTree[right]),back_inserter(sTree[v]));
    }
}

ll query(ll v, ll l, ll r, ll ql, ll qr, ll k)
{
    if(ql>qr)return 0;
    if(ql==l&&qr==r){
        ll idx=upper_bound(all(sTree[v]),k)-sTree[v].begin();
        ll cnt=sTree[v].size()-idx;
        return cnt;
    }
    ll left=v*2;
    ll right=left+1;
    ll mid=l+(r-l)/2;
    ll p=query(left,l,mid,ql,min(qr,mid),k);
    ll q=query(right,mid+1,r,max(ql,mid+1),qr,k);
    ll ans=p+q;
    return ans;
}

int main()
{
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    build(1,1,n);
    ll q;
    cin>>q;
    ll ql, qr, k;
    for(ll i=1;i<=q;i++){
        cin>>ql>>qr>>k;
        ll ans=query(1,1,n,ql,qr,k);
        cout<<ans<<endl;
    }
    return 0;
}
