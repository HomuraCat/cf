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
int n, cnt;
bool vis[N];
bool ask (int x)
{
    fflush(stdout);
    printf("? 1 %d\n", n - 1);
    printf("%d\n", x);
    fo (i, 1, n)
        if (i != x)
            printf("%d ", i);
    puts("");
    return read();
}
int main ()
{
    int T = read();
    while (T--)
    {
        n = read();
        fo (i, 1, n)
        {
            vis[i] = ask(i);
            if (!vis[i]) ++cnt;
        }
        printf("! %d", cnt);
        fo (i, 1, n)
        {
            if (!vis[i]) printf(" %d", i);
            vis[i] = 0;
        }
        puts("");
    }
    return 0;
}
