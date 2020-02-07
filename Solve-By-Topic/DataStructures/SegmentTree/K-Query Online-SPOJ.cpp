/*******Bismillahir-Rahmanir-Rahim**********/
/* 
Name         : Abu Rifat Muhammed Al Hasib 
Institution  : University of Barisal, Bangladesh
Github       : abu-rifat
Codeforces   : AbuRifatMuhammed
AtCoder      : aburifat
codechef     : aburifat
SPOJ         : abu_rifat
UvaOJ        : aburifat
DevSkill     : abu_rifat
lightoj      : Abu Rifat Muhammed Al Hasib
facebook     : https://www.facebook.com/a.r.m.al.hasib/
linkedin     : https://www.linkedin.com/in/abu-rifat-534258142/
Email        : rifat.cse4.bu@gmail.com, armalhasib@gmail.com
*/

/* 
Problem Name    : K-Query Online
Online Judge    : SPOJ
Solving Method  : Segment Tree

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pub push_back
#define all(v) v.begin(), v.end()

ll inputArray[100010];
vector<ll> segmentTree[3 * 30000 + 10];

void buildTree(ll n, ll l, ll r)
{
    if (l == r)
    {
        segmentTree[n].pub(inputArray[l]);
        return;
    }
    ll left = n * 2;
    ll right = n * 2 + 1;
    ll mid = l + (r - l) / 2;
    buildTree(left, l, mid);
    buildTree(right, mid + 1, r);
    merge(all(segmentTree[left]), all(segmentTree[right]), back_inserter(segmentTree[n]));
}

ll query(ll n, ll l, ll r, ll i, ll j, ll k)
{
    if (j < l || i > r)
    {
        return 0;
    }
    if (i <= l && r <= j)
    {
        ll aa = upper_bound(all(segmentTree[n]), k) - segmentTree[n].begin();
        aa = segmentTree[n].size() - aa;
        return aa;
    }
    ll left = n * 2;
    ll right = n * 2 + 1;
    ll mid = l + (r - l) / 2;
    ll p = query(left, l, mid, i, j, k);
    ll q = query(right, mid + 1, r, i, j, k);
    ll ans = p + q;
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> inputArray[i];
    }
    buildTree(1, 1, n);
    ll q;
    cin >> q;
    ll ans = 0;
    while (q--)
    {
        ll a, b, c, i, j, k;
        cin >> a >> b >> c;
        i = max((a ^ ans), (ll)1);
        j = min((b ^ ans), n);
        k = c ^ ans;
        if (i > j)
        {
            ans = 0;
        }
        else
        {
            ans = query(1, 1, n, i, j, k);
        }
        cout << ans << endl;
    }
    return 0;
}

/***********Alhamdulillah***********/