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
Solving Method  : LCA with Sparse Table

*/

#include <bits/stdc++.h>
using namespace std;

#define MX 1009

vector<int> G[MX];
bool Visited[MX];
int STable[MX][22], Level[MX];

void inis(int n)
{
    for (int i = 0; i <= n; i++)
    {
        G[i].clear();
        Level[i] = -1;
        Visited[i] = false;
        for (int j = 0; j < 22; j++)
        {
            STable[i][j] = -1;
        }
    }
}

void dfs(int u)
{
    Visited[u] = true;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (!Visited[v])
        {
            STable[v][0] = u;
            Level[v] = Level[u] + 1;
            dfs(v);
        }
    }
}

void prep(int n)
{
    for (int j = 1; (1 << j) < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (STable[i][j - 1] != -1)
            {
                STable[i][j] = STable[STable[i][j - 1]][j - 1];
            }
        }
    }
}

int Query(int ql, int qr)
{
    int lg;
    if (Level[ql] < Level[qr])
        swap(ql, qr);
    for (lg = 0; (1 << lg) <= Level[ql]; lg++)
        ;
    lg--;
    if (Level[ql] != Level[qr])
    {
        for (int i = lg; i >= 0; i--)
        {
            if (Level[ql] - (1 << i) >= Level[qr])
            {
                ql = STable[ql][i];
            }
        }
    }
    if (ql == qr)
        return ql;
    for (int i = lg; i >= 0; i--)
    {
        if ((STable[ql][i] != -1) && (STable[ql][i] != STable[qr][i]))
        {
            ql = STable[ql][i];
            qr = STable[qr][i];
        }
    }
    return STable[ql][0];
}

int main()
{
    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        int n;
        cin >> n;
        inis(n);
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++)
            {
                int tmp;
                cin >> tmp;
                tmp--;
                G[i].push_back(tmp);
                G[tmp].push_back(i);
            }
        }
        Level[0] = 0;
        dfs(0);
        prep(n);
        int q;
        cin >> q;
        cout << "Case " << T << ":" << endl;
        while (q--)
        {
            int ql, qr;
            cin >> ql >> qr;
            ql--;
            qr--;
            int ans = Query(ql, qr);
            ans++;
            cout << ans << endl;
        }
    }
    return 0;
}

/***********Alhamdulillah***********/