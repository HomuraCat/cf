#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
#include<queue>
#include<vector>
#include<set>
#include<cstdlib>
#include<iostream>
#include<map>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define edge(i, u) for (int i = head[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define pb push_back
#define F first
#define S second
#define ll long long
#define inf 1000000007
#define mp std::make_pair
#define eps 1e-4
#define mod 1000000007
#define lowbit(x) (x & -x)
#define N 150005
#define clr(arr) memset(arr, 0, sizeof arr)
#define bset std::bitset<N>
#define pi std::pair<int, int>
inline ll read ()
{
    ll x = 0; bool flag = 0; char ch = getchar();
    while (!isdigit(ch) && ch != '-') ch = getchar();
    if (ch == '-') flag = 1, ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    if (flag) x = -x; return x;
}
inline ll po (ll x, int y)
{
    ll ret = 1;
    while (y)
    {
        if (y & 1) ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
ll a[5][N];
struct node {
    int id;
    ll v;
    friend bool operator < (node x, node y) {return x.v < y.v;}
}f[N], g[N];
struct pp {
    int x, y;
    friend bool operator < (pp x, pp y) {return x.x < y.x || x.x == y.x && x.y < y.y;}
};
std::map<pp, int> p;
void calc (int n2, int n1)
{
    fo (i, 1, n2)
    {
        bool flag = 0;
        fo (j, 1, n1)
            if (p[(pp){f[j].id, g[i].id}] == 0)
            {
                g[i].v += f[j].v;
                flag = 1;
                break;
            }
        if (!flag) g[i].v = inf;
    }
    return;
}
int main ()
{
    int n[5], m;
    fo (i, 1, 4) n[i] = read();
    fo (i, 1, 4)
        fo (j, 1, n[i])
            a[i][j] = read();

    fo (i, 1, n[1]) f[i] = (node){i, a[1][i]};
    fo (i, 1, n[2]) g[i] = (node){i, a[2][i]};
    std::sort(f + 1, f + n[1] + 1);
    m = read(); p.clear();
    while (m--)
    {
        int x = read(), y = read();
        p[(pp){x, y}] = 1;
    }
    calc(n[2], n[1]);

    memcpy(f, g, sizeof f);
    fo (i, 1, n[3]) g[i] = (node){i, a[3][i]};
    std::sort(f + 1, f + n[2] + 1);
    m = read(); p.clear();
    while (m--)
    {
        int x = read(), y = read();
        p[(pp){x, y}] = 1;
    }
    calc(n[3], n[2]);

    memcpy(f, g, sizeof f);
    fo (i, 1, n[4]) g[i] = (node){i, a[4][i]};
    std::sort(f + 1, f + n[3] + 1);
    m = read(); p.clear();
    while (m--)
    {
        int x = read(), y = read();
        p[(pp){x, y}] = 1;
    }
    calc(n[4], n[3]);

    ll ans = inf;
    fo (i, 1, n[4]) ans = std::min(ans, g[i].v);
    printf("%lld", ans == inf ? -1 : ans);

    return 0;
}
