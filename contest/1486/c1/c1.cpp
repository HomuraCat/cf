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
#define N 1005
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
int ask (int l, int r)
{
    fflush(stdout);
    int x;
    printf("? %d %d\n", l, r);
    scanf("%d", &x);
    return x;
}
int lst;
void check (int l, int r)
{
    if (l + 1 == r)
    {
        printf("! %d\n", lst == l ? r : l);
        return;
    }
    int mid = l + r >> 1;
    int now;
    if (lst <= mid)
    {
        now = ask(l, mid);
        if (now == lst)
        {
            check(l, mid);
        }
        else
        {
            lst = ask(mid + 1, r);
            check(mid + 1, r);
        }
    }
    else
    {
        if (r <= mid + 1)
        {
            lst = ask(l, mid);
            check(l, mid);
            return;
        }
        if (now == lst)
        {
            check(mid + 1, r);
        }
        else
        {
            lst = ask(l, mid);
            check(l, mid);
        }
    }
}
int main ()
{
    int n = read();
    lst = ask(1, n);
    check(1, n);
    return 0;
}
