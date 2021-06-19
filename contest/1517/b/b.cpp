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
struct node {
    int v, x, y;
    friend bool operator < (node x, node y) {return x.v < y.v || x.v == y.v && x.x < y.x || x.v == y.v && x.x == y.x && x.y < y.y;}
};
int head[N], tot;
int n, m, a[105][105];
std::multiset<node> q;
int main ()
{
    int T = read();
    while (T--)
    {
        n = read(); m = read();
        q.clear();
        fo (i, 1, n)
            fo (j, 1, m)
            {
                a[i][j] = read();
                q.insert((node){a[i][j], i, j});
            }
        fo (j, 1, m)
        {
            node now = *q.begin(); q.erase(q.begin());
            if (now.y != j)
            {
                q.erase((node){a[now.x][j], now.x, j});
                q.insert((node){a[now.x][j], now.x, now.y});
                std::swap(a[now.x][j], a[now.x][now.y]);
            }
        }
        fo (i, 1, n)
        {
            fo (j, 1, m)
                printf("%d ", a[i][j]);
            puts("");
        }
    }
    return 0;
}
