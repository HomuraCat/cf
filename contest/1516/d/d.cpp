//HomuraCat codes it!
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
#include<queue>
#include<vector>
#include<set>
#include<cstdlib>
#include<iostream>
#include<utility>
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
#define N 100005
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
inline ll qabs (ll x) { return x < 0 ? -x : x; }
inline ll qpow (ll x, int y)
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
struct edge {
    int nxt, v;
}e[N << 1];
int head[N], tot;
void addedge (int u, int v)
{
    e[++tot] = (edge) {head[u], v};
    head[u] = tot;
}
int n, m, a[N], f[N][20];
std::vector<int> p[N], pos[N];

int main ()
{
    memset(f, 0x3f, sizeof f);
    n = read(); m = read();
    fo (i, 1, n) a[i] = read();
    fo (i, 1, n)
    {
        for (int j = 2; j * j <= a[i]; ++j)
            if (a[i] % j  == 0)
            {
                a[i] /= j;
                while (a[i] % j == 0) a[i] /= j;
                p[i].pb(j);
                pos[j].pb(i);
            }
        if (a[i] > 1) 
        {
            p[i].pb(a[i]);
            pos[a[i]].pb(i);
        }
    }
    fo (i, 1, 100000) pos[i].pb(n + 1);
    fd (i, n, 1)
    {
        int sz = p[i].size() - 1;
        f[i][0] = f[i + 1][0];
        fo (j, 0, sz)
        {
            int x = p[i][j];
            int id = *std::upper_bound(pos[x].begin(), pos[x].end(), i);
            f[i][0] = std::min(f[i][0], id);
        }
    }
    fd (i, n, 1)
        fo (k, 1, 19)
        {
            if (f[i][k - 1] > n) continue;
            f[i][k] = f[f[i][k - 1]][k - 1];
        }
    while (m--)
    {
        int l = read(), r = read(), ans = 0;
        fd (k, 19, 0)
        {
            if (f[l][k] > r) continue;
            l = f[l][k];

            ans += (1 << k);
        }
        ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
