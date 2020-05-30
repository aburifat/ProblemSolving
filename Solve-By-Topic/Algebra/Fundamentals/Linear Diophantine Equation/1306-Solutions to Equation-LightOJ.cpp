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
    ll a,b,c,minx,maxx,miny,maxy;
    for(ll T=1; T<=t; T++) {
        ll ans=0;
        cin>>a>>b>>c>>minx>>maxx>>miny>>maxy;
        c=-c;
        if(a&&b){
            ans=All(a,b,c,minx,maxx,miny,maxy);
        }
        else if(a||b) {
            ll x,y;
            ll g=gcd(a,b,x,y);
            if(!c%g){
                if((a&&(x>=minx)&&(x<=maxx))||(b&&(y>=miny)&&(y<=maxy)))ans=1;
            }
        }
        cout<<"Case "<<T<<": "<<ans<<"\n";
    }
    return 0;
}

