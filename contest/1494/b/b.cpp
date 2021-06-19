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
int n, m, a[55], b[55]; 
int main ()
{
    int T = read();
    while (T--)
    {
        n = read(); fo (i, 1, 4) b[i] = a[i] = read();
        for (int i = 1; i <= 3; i += 2)
        {
            if (a[i] > n - 2)
            {
                if (a[i] == n)
                {
                    a[2] -= 1; a[4] -= 1;
                }
                else
                {
                    if (a[2] > a[4]) a[2]--; else a[4]--;
                }
            }
        }
        if (a[2] < 0 || a[4] < 0 || a[2] > n - 2 || a[4] > n - 2) 
        {} else {printf("YES\n"); continue;}
        fo (i, 1, 4) a[i] = b[i];
        for (int i = 2; i <= 4; i += 2)
        {
            if (a[i] > n - 2)
            {
                if (a[i] == n)
                {
                    a[1] -= 1; a[3] -= 1;
                }
                else
                {
                    if (a[1] > a[3]) a[1]--; else a[3]--;
                }
            }
        }
        if (a[1] < 0 || a[3] < 0 || a[1] > n - 2 || a[3] > n - 2) 
        {} else {printf("YES\n");continue;}
        printf("NO\n");
    }
    return 0;
}
