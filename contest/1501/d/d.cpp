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
#define N 500005
#define clr(arr) memset(arr, 0, sizeof arr)
#define bset std::bitset<N>
#define pi std::pair<int, int>
inline ll read ()
{
    ll x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
 //   if (ch == '-') flag = 1, ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}
int gcd (int x, int y)
{
    while (x % y)
    {
        x %= y;
        std::swap(x, y);
    }
    return y;
}
int n, m, a[N], b[N], d, c[N << 1];
ll k, lcm, l, r;
int exgcd (int a, int b, ll &x, ll &y)
{
    if (!b) {x = 1; y = 0; return a;}
    int d = exgcd(b, a % b, x, y);
    std::swap(x, y);
    y -= a / b * x;
    return d;
}
ll k1, k2;
ll calc (int x, int y, ll k)
{
    if ((y - x) % d) return 0;
    ll sum = (k1 * (y - x) / d * n + x) % lcm;
    if (sum <= 0) sum += lcm;
    return k >= sum ? (k - sum) / lcm + 1 : 0;
}
std::vector<pi> t;
int sz;
bool check (ll x)
{
    ll ret = 0;
    fo (i, 0, sz)
        ret += calc(t[i].S, t[i].F, x);
    return x - ret >= k;
}
int main ()
{
    n = read(); m = read(); k = read();
    exgcd(n, m, k1, k2);
    d = gcd(n, m);
    lcm = 1ll * n * m / d;
    fo (i, 1, n) c[a[i] = read()] = i;
    fo (i, 1, m) b[i] = read();
    fo (i, 1, m) if (c[b[i]]) t.pb(mp(i,c[b[i]]));
    sz = t.size() - 1;
    l = 1; r = 1e18;
    while (l < r)
    {
        ll mid = l + r >> 1;
        if (check(mid)) r = mid; else l = mid + 1;
    }
    printf("%lld", l);
    return 0;
}
