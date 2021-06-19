#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
#include<queue>
#include<vector>
#include<set>
#include<cstdlib>
#include<iostream>
#include<cmath>
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
#define N 200005
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
#define int ll
int dp[N];
struct tree{
	int fa, v, dep;
	friend bool operator < (tree x, tree y) { return x.dep < y.dep; }
}t[N];
inline void dfs (int u)
{
	if (t[u].dep) return;
	if (u == 1) return;
	dfs(t[u].fa);
	t[u].dep = t[t[u].fa].dep + 1;
}
std::vector<int> dd[N];
main ()
{
	int T = read();
	while (T--)
	{
		int n = read();
		fo (i, 2, n) t[i].fa = read();
		fo (i, 2, n) t[i].v = read();
		fo (i, 2, n) t[i].dep = 0, dp[i] = 0;
		fo (i, 2, n) if (!t[i].dep) dfs(i);
		int up = 0;
		fo (i, 1, n) up = std::max(up, t[i].dep);
		fo (i, 1, up) dd[i].clear();
		fo (i, 1, n) dd[t[i].dep].pb(i);
		fo (d, 1, up)
		{
			int p[5]; std::memset(p, 0xf3, sizeof p);
			for (auto it = dd[d].begin(); it != dd[d].end(); ++it)
			{
				int i = (*it);
				p[1] = std::max(p[1], t[i].v);
				p[2] = std::max(p[2], -t[i].v);
				p[3] = std::max(p[3], dp[t[i].fa] + t[i].v);
				p[4] = std::max(p[4], dp[t[i].fa] - t[i].v);
			}
			for (auto it = dd[d].begin(); it != dd[d].end(); ++it)
			{
				int i = (*it);
				dp[i] = std::max(dp[i], dp[t[i].fa] - t[i].v + p[1]);
				dp[i] = std::max(dp[i], dp[t[i].fa] + t[i].v + p[2]);
				dp[i] = std::max(dp[i], -t[i].v + p[3]);
				dp[i] = std::max(dp[i], t[i].v + p[4]);
			}
		}
		int ans = 0;
		fo (i, 1, n) if (t[i].dep == up) ans = std::max(ans, dp[i]);
		printf("%lld\n", ans);
	}
	return 0;
}
