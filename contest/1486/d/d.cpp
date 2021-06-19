#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
#include<queue>
#include<vector>
#include<set>
#include<cstdlib>
#include<iostream>
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
int a[N], b[N], n, k, x;
bool check (int m)
{
    int sum = 0;
    fo (i, 1, n) b[i] = a[i] < m;
    fo (i, 1, k) sum += b[i];
    if (sum < x) return 1;
    fo (i, k + 1, n)
    {
        sum += b[i]; sum -= b[i - k];
        if (sum < x) return 1;
    }
    if (k == n) return 0;
    sum = 0;
    fo (i, 1, k + 1) sum += b[i];
    if (sum < (k + 2 >> 1)) return 1;
    fo (i, k + 2, n)
    {
        sum += b[i]; sum -= b[i - k - 1];
        if (sum < (k + 2 >> 1)) return 1;
    }
    return 0;
}
int main ()
{
    n = read(), k = read();
    fo (i, 1, n) a[i] = read();
    int l = 1, r = n;
    x = (k + 1) >> 1;
    while (l < r)
    {
        int m = l + r + 1 >> 1;
        if (check(m)) l = m; else r = m - 1;
    }
    printf("%d", l);
    return 0;
}
