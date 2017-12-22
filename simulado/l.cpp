#include <bits/stdc++.h>

using namespace std;

#define TRACE(X) 

#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define sz(a) (int)(a.size())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;

int colado(pair<int, int> a, pair<int, int> b)
{
	if(a.fi==b.fi)
		if(abs(a.se-b.se) == 1 )
			return 1;

	if(a.se==a.se)
		if(abs(a.fi-b.fi)==1)
			return 1;
	return 0;
}

vector<pair<int, int> > andar[1010];

int main()
{
	
	int T, n, m, bla;
	scanf("%d", &T);
	

	while(T--)
	{
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++)
		{
			for(int j =0; j<m; j++)
			{
				scanf("%d", &bla);
				for(int k=bla;k>0;k--)
					andar[k].pb(mp(i,j));
			}
		}

		int area = 0;

		for(int height=1000; height>0; height--)
		{
			
			int tam = (int)andar[height].size();
			int adj = 0;
			for(int i =0; i<tam; i++)
			{
				for(int j=0; j<tam; j++)
				{
					if(colado(andar[height][i], andar[height][j]))
					{
						adj++;
					}
				}
			}
			int adj2 = 0;	
			if(height!=1000)
			{
				for(int i=0; i<tam; i++)
				{
					for(int j =0; j<(int)andar[height+1].size(); j++)
					{
						if(andar[height][i].fi==andar[height+1][j].fi && andar[height][i].se==andar[height+1][j].se )
							adj2++;
					}
				}
			}
			area += 5*tam - adj/2 -adj2;
		}
	
		printf("%d\n", area);
		for(int i = 0; i < 1010; ++i) andar[i].clear();
	}

	return 0;
}

