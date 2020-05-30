#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if(a==0) {
        x=0;
        y=1;
        return b;
    }
    ll x1,y1;
    ll d=gcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}

bool Any(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g=gcd(abs(a),abs(b),x0,y0);
    if(c%g) {
        return false;
    }
    x0*=c/g;
    y0*=c/g;
    if(a<0)
        x0=-x0;
    if(b<0)
        y0=-y0;
    return true;
}

void Shift(ll & x, ll & y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll All(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    ll x, y, g;
    if (!Any(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    Shift(x, y, a, b, (minx - x) / b);
    if (x < minx)
        Shift(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    ll lx1 = x;

    Shift(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        Shift(x, y, a, b, -sign_b);
    ll rx1 = x;

    Shift(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        Shift(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    ll lx2 = x;

    Shift(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        Shift(x, y, a, b, sign_a);
    ll rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}


int main() {
    ll t;
    cin>>t;
    ll a,b,c,p;
    for(ll T=1;T<=t;T++) {
        cin>>a>>b>>c>>p;
        ll g=__gcd(__gcd(a,b),c);
        a/=g,b/=g,c/=g;
        ll Ans=0;
        if(p%g==0) {
            p/=g;
            ll z=0;
            while(1) {
                ll q=p-(c*z);
                if(q<0)
                    break;
                Ans+=All(a,b,q,0,p,0,p);
                z++;
            }
        }
        cout<<"Case "<<T<<": "<<Ans<<"\n";
    }
    return 0;
}


