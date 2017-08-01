/*input
3 2
4 6 3
2 4 1
3 5 4
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique(all(v)), v.end())
#define IOS ios::sync_with_stdio(0);
#define sz(v) (v).size()
#define mt make_tuple
#define fr(a, b, c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a, b) fr(a,0,b)
#define cl(a, b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pr(a) printf("%d\n", a);
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int Inf = 0x3F3F3F3F;
const int negInf = 0xC0C0C0C0;
const ll mod = 1e9 + 7;
const ll maxn = 5*1e6 + 1;

vector<int> p;
vector<char> primes(true, 5*1e6 + 1);
vector<int> f(maxn, 1e4);
void findPrimes()
{
	primes[0] = primes[1] = false;
	for(ll i = 2; i * i * 1ll <= (ll)maxn; ++i)
	{
		if(primes[i])
		{
			p.pb(i);
			for(ll k = i*i; k <= maxn; k += i)
			{
				primes[k] = false;
			}
		}
	}
}

ll fact(ll n)
{
	ll resp = 0;
	while(n != 1)
	{
		for(int i = 0; i < p.size(); ++i)
		{
			while(n%p[i] ==0)
			{
				resp += (n/p[i]*f[p[i]] )%mod;
				resp %= mod;
				n /= p[i];
			}
		}
	}
	return resp;
}


int main()
{
	findPrimes();
	ll t, l, r;
	cin >> t >> l >> r;
	cout << "miau" << endl;
	f[2] = 1;
	for(int i = 3; i <= r; ++i)
	{
		f[i] = fact(i);
	}	
	vector<ll> pot(r+1, 0);
	pot[1] = 1;
	for(int i = 2; i < r+1; ++i)
	{
		pot[i] = (pot[i]*2)%mod;
	}
	ll resp = 0;
	for(int i = l; i <= r; ++i)
	{
		resp += (pot[i]*f[i])%mod;
	}
	cout << resp << endl;
	return 0;
}
