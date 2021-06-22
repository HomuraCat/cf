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
int n, m; 
std::pair<ll, ll> a[N];
ll cnt, sum;
int main ()
{
    n = read();
    fo (i, 1, n)
    {
        ll x = read(), y = read();
        a[i] = mp(y, x);
    }
    std::sort(a + 1, a + n + 1);
    int l = 1, r = n;
    while (l <= r)
    {
        while (l <= r && cnt >= a[l].F)
        {
            cnt += a[l].S;
            sum += a[l].S;
            ++l;
        }
        if (l > r) break;
        ll now = std::min(a[r].S, a[l].F - cnt);
        cnt += now; 
        a[r].S -= now;
        if (a[r].S == 0) --r;
        sum += now * 2;
    }
    printf("%lld", sum);
    return 0;
}
