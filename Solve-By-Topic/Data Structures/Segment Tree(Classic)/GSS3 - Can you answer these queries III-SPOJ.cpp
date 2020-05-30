#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MX=50000;

ll n, arr[MX+10];

struct data {
    ll sum;     ///range sum
    ll pref;    ///max prefix sum of the range
    ll suff;    ///max suffix sum of the range
    ll ans;     ///max subsegment sum of the range
};

data sTree[3*MX+10];

data combine(data l, data r) {
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

data make_data(ll val) {
    data res;
    res.sum = val;
    res.pref = res.suff = res.ans = max((ll)(-10005), val);
    return res;
}

void build(ll v, ll l, ll r) {
    if (l==r) {
        sTree[v] = make_data(arr[l]);
    } else {
        ll left=v*2;
        ll right=left+1;
        ll mid=l+(r-l)/2;
        build(left, l, mid);
        build(right, mid+1, r);
        sTree[v] = combine(sTree[left], sTree[right]);
    }
}

void update(ll v, ll l, ll r, ll pos, ll val) {
    if (l==r) {
        sTree[v] = make_data(val);
    } else {
        ll left=v*2;
        ll right=left+1;
        ll mid=l+(r-l)/2;
        if (pos <= mid)
            update(left, l, mid, pos, val);
        else
            update(right, mid+1, r, pos, val);
        sTree[v] = combine(sTree[left], sTree[right]);
    }
}

data query(ll v, ll l, ll r, ll ql, ll qr) {
    if (ql>qr)
        return make_data(-10005);
    if (ql==l&&qr==r)
        return sTree[v];
        ll left=v*2;
        ll right=left+1;
        ll mid=l+(r-l)/2;
        data p=query(left, l, mid, ql, min(qr, mid));
        data q=query(right, mid+1, r, max(ql, mid+1), qr);
    return combine(p,q);
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    build(1,1,n);
    ll q;
    cin>>q;
    ll tp;
    ll ql, qr, pos, val;
    for(ll i=1;i<=q;i++){
        cin>>tp;
        if(tp==1){
            cin>>ql>>qr;
            if(ql>qr)swap(ql,qr);
            data ans=query(1,1,n,ql,qr);
            cout<<ans.ans<<endl;
        }else if(tp==0){
            cin>>pos>>val;
            update(1,1,n,pos,val);
        }
    }
    return 0;
}
