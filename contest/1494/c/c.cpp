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
#define N 1000005
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
int n, m, a[N], b[N], s[N]; 
int vis[N], id;
int main ()
{
    int T = read();
    while (T--)
    {
        ++id;
        n = read(); m = read();
        fo (i, 1, n) a[i] = read(); fo (i, 1, m) b[i] = read();
        fo (i, 1, m) 
        {
            int p = std::lower_bound(a + 1, a + n + 1, b[i]) - a;
            if (a[p] == b[i]) vis[i] = id;
        }
        fo (i, 1, m) s[i] = s[i - 1] + (vis[i] == id);
        int p[2] = {0};
        fo (i, 1, n) if (a[i] > 0) {p[0] = i; break;}
        fo (i, 1, m) if (b[i] > 0) {p[1] = i; break;}
        if (!p[0]) p[0] = n + 1; if (!p[1]) p[1] = m + 1;
        int ansr = 0, ansl = 0;
        fo (i, p[1], m) 
        {
            int pos = std::upper_bound(a + 1, a + n + 1, b[i]) - a;
            int l = b[i] - (pos - p[0]) + 1;
            pos = std::lower_bound(b + 1, b + m + 1, l) - b;
            ansr = std::max(i - pos + 1 + s[m] - s[i], ansr);
        }
        fd (i, p[1] - 1, 1)
        {
            int pos = std::lower_bound(a + 1, a + n + 1, b[i]) - a;
            int l = b[i] - (p[0] - pos) + 1;
            pos = std::lower_bound(b + 1, b + m + 1, l) - b;
            int ss = (pos <= 0) ? 0 : s[pos - 1];
            ansl = std::max(ansl, i - pos + 1 + ss);
        }
        printf("%d\n", std::max(s[m], ansl + ansr));
    }
    return 0;
}
