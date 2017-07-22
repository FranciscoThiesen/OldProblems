#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define ll long long


#define TRACE(x...) x
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

long long bc(ll n, ll k)
{
    vector<ll> C(k+1);
    fill(C.begin(), C.end(), 0); 
    C[0] = 1;  // nC0 is 1
 
    for (long long i = 1; i <= n; i++)
    {
        // Compute next row of pascal triangle using
        // the previous row
        for (long long j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];
    }
    return C[k];
}

vector<vector<int> > todasPerm;

void gera_todas_perm(set<int>& nums, vector<int>& perm_atual, int menorElemento, int maxSize)
{
	for(auto& p : nums)
	{
		if(p > menorElemento)
		{
			vector<int> perm_tmp = perm_atual;
			perm_tmp.pb(p);
			if(perm_tmp.size() <= maxSize)
			{	
				if(perm_tmp.size() < maxSize)
					gera_todas_perm(nums, perm_tmp, p, maxSize);
				todasPerm.pb(perm_tmp);
			}
		}
	}
}

ll f(ll n, ll p)
{
	ll result = bc(n, p);
	set<int> numeros;
	for(int i = 1; i < p; i++)
	{
		numeros.insert(i);	
	}
	
	vector<int> perm_atual;
	gera_todas_perm(numeros, perm_atual, 0, p);

	TRACE(
		for(auto& p : todasPerm)
		{
			for(auto& q : p)
			{
				cout << q << " ";
			}
			cout << endl;
		}
	)
	int sizetp = todasPerm.size();

	for(int i=0; i<sizetp; i++)
	{
		ll helper = 1;
		int j = todasPerm[i].size() - 1;
		int a = n;
		int b = p - todasPerm[i][j];
		
		for(;j>0; j--)
		{
			helper *=  bc(a, b);
			a -= b;
			b = todasPerm[i][j] - todasPerm[i][j-1];
		}
		result += helper;
		WATCH(helper);
		WATCH(result);
	}
	
	return result;
}


int main()
{
	int t;
	scanf("%d", &t);


	for(int a = 0; a < t; a++)
	{
		ll n;
		scanf("%lld", &n);
		ll resp = 0;

		for(int i = 3; i <= 3; i++)
		{
			resp += f(n, i);
			WATCH(resp);

			TRACE(
				cout << endl;
				cout << endl;
			)
			todasPerm.clear();

		}

		printf("%lld\n", resp);
	}


	return 0;
}
