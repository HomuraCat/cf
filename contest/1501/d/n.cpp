#include<cstdio>
#include<algorithm>
#include<assert.h>
#include<numeric>
#include<iostream>
#include<vector>
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define fori(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define ll long long int
#define mod 1000000007
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define printVector(v) fori(i,v.size()) {cout << v[i] << " ";} cout << "\n";
#define item ll
using namespace std;
void parr (ll *a, int x, int y)
{
    for (int i = x; i <= y; ++i)
    {
        printf("%4lld ", a[i]);
        if ((i - x & 7) == 7) puts("");
    }
}
void solve()
{
	ll n,m,k;
	cin >> n >> m >> k;
	vector<int> a(n),b(m);
	fori(i,n) cin >> a[i];
	fori(i,m) cin >> b[i];
	vector<vector<int>> colors(2*max(n,m)+1);
	vector<ll> cnt(n,0);
	fori(i,n)
	{
		colors[a[i]].pb(i);
	}
	fori(i,m)
	{
		colors[b[i]].pb(i);
	}
	int totC = 2*max(n,m) + 1;
	fori(i,totC)
	{
		if(colors[i].size() > 1)
		{
		    int x = colors[i].front()-colors[i].back();
		    x += abs((x/n)*n);
		    if(x < 0) x += n;
		    x %= n;
			cnt[x]++;
		}
	}
	vector<ll> newVec;
	ll lc = n*m/1;//gcd(n,m);
	int cur = 0;
	fori(i,lc/m)
	{
		newVec.pb(m-cnt[cur]);
		cur += m;
		cur %= n;
	}
	assert(cur==0);
	int sz = newVec.size();
	vector<ll> parSum(sz);
	partial_sum(all(newVec),parSum.begin());
	//printVector(parSum)
    ll tot = parSum.back();
	ll days = (k/tot)*tot;
	if(days==k) days -= tot;
	k -= days;
	days = (days/tot)*lc;
	cur = 0;
	for(ll i = 0; i < sz;i++)
	{
		if(parSum[i] >= k)
		{
			if(i!=0)
			{
				k-=parSum[i-1];
				days += m * (i);
			}
				for(int j = 0; j < m; j++)
				{
					days++;
					if(b[j] != a[(j+cur)%n])
					{
						k--;
						if(k==0)
						{
							cout << days << "\n";
							return;
						}
					}
				}

			break;
		}
		cur += m;
		cur%=n;
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ttt=1;
	//cin >> ttt;
	while(ttt--) solve();
}

