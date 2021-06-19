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
int n, m, a[N]; 
std::map<pi, int> p;
char s[N];
inline void update (int x, int y)
{
    if (x && y)
    {
        int d = std::__gcd(x, y);
        x /= d; y /= d;
    }
    else
    {
	if (x) x = 1; else y = 1;
    }
    printf("%d ", ++p[mp(x, y)]);
}
int main ()
{
    int T = read();
    while (T--)
    {
        p.clear();
        n = read();
        scanf("%s", s + 1);
        fo (i, 1, n)
        {
            a[i] = a[i - 1] + (s[i] == 'D');
            update(a[i], i - a[i]);
        }
        puts("");
    }
    return 0;
}
