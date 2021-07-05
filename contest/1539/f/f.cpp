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
#define ls (u << 1)
#define rs (u << 1 | 1)
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
int head[N], tot;
int n, m, a[N], b[N], c[N]; 
int abs (int x) {return x < 0 ? -x : x;}
struct tree {
    int sum, lx, rx;
}t[N << 2];
void update (int u)
{
    t[u].sum = t[ls].sum + t[rs].sum;
    t[u].lx = std::max(t[ls].lx, t[ls].sum + t[rs].lx);
    t[u].rx = std::max(t[rs].rx, t[rs].sum + t[ls].rx);
}
void build (int u, int l, int r)
{
    t[u].lx = t[u].rx = t[u].sum = 0;
    if (l == r)
    {
        t[u].sum = -1;
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    update(u);
}
void modify (int u, int l, int r, int x, int v)
{
    if (l == r)
    {
        t[u].sum = v;
        t[u].lx = t[u].rx = std::max(0, v);
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        modify(ls, l, mid, x, v);
    else
        modify(rs, mid + 1, r, x, v);
    update(u);
}
tree find (int u, int l, int r, int x, int y)
{
    if (x > y) return (tree){0, 0, 0}; 
    if (x <= l && r <= y)
        return t[u];
    tree ret, lret, rret;
    ret.lx = ret.rx = ret.sum = 0;
    rret = ret;
    int mid = l + r >> 1;
    if (x <= mid)
        ret = find(ls, l, mid, x, y);
    if (mid < y)
        rret = find(rs, mid + 1, r, x, y);
    ret.lx = std::max(ret.lx, ret.sum + rret.lx);
    ret.rx = std::max(rret.rx, rret.sum + ret.rx);
    ret.sum += rret.sum;
    return ret;
}
std::priority_queue<pi> q;
int last, sta[N], top, ans[N];
int main ()
{
    n = read();
    fo (i, 1, n) a[i] = read();

    build(1, 1, n);
    fo (i, 1, n) q.push(mp(a[i], i));
    q.push(mp(0, n + 1));
    last = q.top().F;
    while (q.size())
    {
        pi now = q.top();
        q.pop();
        if (now.F != last)
        {
            fo (i, 1, top)
                modify(1, 1, n, sta[i], 1);
            fo (i, 1, top)
                ans[sta[i]] = std::max(ans[sta[i]], (find(1, 1, n, sta[i] + 1, n).lx + find(1, 1, n, 1, sta[i] - 1).rx + 1) / 2);
            top = 0;
            last = now.F;
        }
        sta[++top] = now.S;
        ans[now.S] = (find(1, 1, n, now.S + 1, n).lx + find(1, 1, n, 1, now.S - 1).rx + 1) / 2;
    }
    
    build(1, 1, n);
    top = 0;
    fo (i, 1, n) q.push(mp(-a[i], i));
    q.push(mp(-n-1, n + 1));
    last = q.top().F;
    while (q.size())
    {
        pi now = q.top();
        q.pop();
        if (now.F != last)
        {
            fo (i, 1, top)
                modify(1, 1, n, sta[i], 1);
            fo (i, 1, top)
                ans[sta[i]] = std::max(ans[sta[i]], (find(1, 1, n, sta[i] + 1, n).lx + find(1, 1, n, 1, sta[i] - 1).rx) / 2);
            top = 0;
            last = now.F;
        }
        sta[++top] = now.S;
        ans[now.S] = std::max(ans[now.S], (find(1, 1, n, now.S + 1, n).lx + find(1, 1, n, 1, now.S - 1).rx) / 2);
    }
    fo (i, 1, n) printf("%d ", ans[i]);
    return 0;
}
