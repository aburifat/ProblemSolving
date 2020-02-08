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
Problem Name    : LCA - Lowest Common Ancestor
Online Judge    : SPOJ
Solving Method  : LCA and RMQ with Segment Tree

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pub push_back
#define F first
#define S second
#define all(v) v.first(), v.second()

vector<vector<ll>> graph;
vector<ll> euler_tour;
vector<ll> first_encounter;
vector<ll> new_to_old;
vector<ll> segmentTree;

void clearAll()
{
    for (ll i = 0; i < graph.size(); i++)
    {
        graph[i].clear();
    }
    euler_tour.clear();
    first_encounter.clear();
    new_to_old.clear();
    segmentTree.clear();
    new_to_old.pub(0);
    euler_tour.pub(0);
}

void dfs_euler_tour(ll node, ll parent)
{
    ll new_index = new_to_old.size();
    new_to_old.pub(node);
    first_encounter[node] = euler_tour.size();
    euler_tour.pub(new_index);
    for (ll next_node : graph[node])
    {
        if (next_node == parent)
            continue;
        dfs_euler_tour(next_node, node);
        euler_tour.pub(new_index);
    }
}

ll buildTree(ll n, ll l, ll r)
{
    if (l == r)
    {
        segmentTree[n] = euler_tour[l];
        return segmentTree[n];
    }
    ll left = n * 2;
    ll right = n * 2 + 1;
    ll mid = (l + r) / 2;
    ll p = buildTree(left, l, mid);
    ll q = buildTree(right, mid + 1, r);
    segmentTree[n] = min(p, q);

    return segmentTree[n];
}

ll query(ll n, ll l, ll r, ll ql, ll qr)
{
    if (r < ql || qr < l)
    {
        return LONG_MAX;
    }
    if (ql <= l && r <= qr)
    {
        return segmentTree[n];
    }
    ll left = n * 2;
    ll right = n * 2 + 1;
    ll mid = (l + r) / 2;
    ll p = query(left, l, mid, ql, qr);
    ll q = query(right, mid + 1, r, ql, qr);
    ll ans = min(p, q);
    return ans;
}

int main()
{
    ll T;
    cin >> T;
    for (ll t = 1; t <= T; t++)
    {
        clearAll();
        ll n;
        cin >> n;
        graph.resize(n + 10);
        for (ll i = 1; i <= n; i++)
        {
            ll num_child;
            cin >> num_child;
            for (ll j = 1; j <= num_child; j++)
            {
                ll child;
                cin >> child;
                graph[i].pub(child);
                graph[child].pub(i);
            }
        }
        first_encounter.resize(n + 10);
        dfs_euler_tour(1, 0);
        ll len_Euler = euler_tour.size();
        len_Euler--;
        segmentTree.resize(3 * len_Euler + 10);
        ll bt = buildTree(1, 1, len_Euler);
        ll q;
        cin >> q;
        vector<ll> ans_q;
        for (ll i = 1; i <= q; i++)
        {
            ll x, y;
            cin >> x >> y;
            x = first_encounter[x];
            y = first_encounter[y];
            if (x > y)
                swap(x, y);
            ll LCA_new_index = query(1, 1, len_Euler, x, y);
            ll LCA_old_index = new_to_old[LCA_new_index];
            ans_q.pub(LCA_old_index);
        }
        cout << "Case " << t << ":" << endl;
        for (ll i = 0; i < q; i++)
        {
            cout << ans_q[i] << endl;
        }
    }
    return 0;
}

/***********Alhamdulillah***********/