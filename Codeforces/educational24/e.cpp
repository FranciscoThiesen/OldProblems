/*input
3 1
1 2 3
*/
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()


const int maxF = 31;
const int maxN = 1e6 + 1;

int contaFatores[maxN][maxF] = {{0}};
int multiplicidade[maxF] = {0};

vector<int> fact;

void findFactors(int k)
{
	for(int e = 2; e <= maxN; ++e)
	{
		if(!(k%e))
		{

			fact.pb(e);
			while(!(k%e))
			{
				multiplicidade[sz(fact)-1]++;
				k /= e;
			}
		}
	}
	if(k != 1)
	{
		fact.pb(k);
		multiplicidade[sz(fact)-1]++;
	}
}

int main()
{
	int n, k, x;
	scanf("%d %d", &n, &k);
	findFactors(k);
	if(k == 1)
	{
		long long rsp = 0;
		for(int i = 0; i < n; ++i)
			rsp += n-i;
		printf("%lld\n", rsp);
		//printf("%lld\n", 1ll * ((1+n)*n) / 2);
		return 0;
	}

	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &x);
		for(int f = 0; f < sz(fact); ++f)
		{
			while(!(x%fact[f]))
			{
				contaFatores[i][f]++;
				x /= fact[f]; 
			}
		}
		for(int f = 0; f < sz(fact); ++f)
			contaFatores[i][f] += contaFatores[i-1][f];
	}

	unsigned long long ans = 0;
	bool ok;
	for(int start = 0; start <= n; ++start)
	{
		int lo = start+1, hi = n, aux = -1, mid;
		while(lo <= hi)
		{
			ok = true;
			mid = (lo + hi) >> 1;
			for(int f = 0; f < sz(fact); ++f)
				ok &= (contaFatores[mid][f] - contaFatores[start][f] >= multiplicidade[f]);
			if(ok)
			{
				aux = mid;
				hi = mid-1;
			}
			else lo = mid+1;
		}
		if(aux != -1)
			ans += (n-aux+1);
	}
	printf("%llu\n", ans);
	return 0;
}
