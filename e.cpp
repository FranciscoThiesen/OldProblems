#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <utility>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x)) 
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0; const int NULO = -1;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0, double tol = EPS) { return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;}

int mat[21][21];
int vis[21][21];

vector<pair<int, int> > dir;

vector<pair<int, int> > pos1;

int ptsMax = -1;
int n, m;

void dfs(int a, int b, int pts, pair<int, int> dirPrin)
{
	if(mat[a][b] == 1)
	{
		for (int i = 0; i < 4; ++i)
		{
			if(a + dir[i].fi >= 0 && a + dir[i].fi < n && b + dir[i].se >= 0 && b + dir[i].se < m)
			{
				if (mat[a + dir[i].fi][b + dir[i].se] == 2 && vis[a + dir[i].fi][b + dir[i].se] == 0)
				{
					dfs(a + dir[i].fi, b + dir[i].se, pts, dir[i]);	
				}
			}
		}
	}
	else if(mat[a][b] == 2)
	{
		if(a + dirPrin.fi >= 0 && a + dirPrin.fi < n && b + dirPrin.se >= 0 && b + dirPrin.se < m)
		{
			if(mat[a + dirPrin.fi][b + dirPrin.se] == 0)
			{
          		vis[a][b] = 1;

				PRINT("%d %d\n", a, b);
				int ptsAtual = pts + 1;
				ptsMax = max(ptsMax, ptsAtual);
				PRINT("%d\n", ptsMax);

                mat[a + dirPrin.fi][b + dirPrin.se] = 1;

				dfs(a + dirPrin.fi, b + dirPrin.se, ptsAtual, dirPrin);
			}
			else
			{
				for (int i = 0; i < n; ++i)
				{
					for (int j = 0; j < m; ++j)
					{
						vis[i][j] = 0;
					}
				}
			}
		}
	}
}

int main(void)
{

	dir.pb(mp(-1,-1));
	dir.pb(mp(-1,1));
	dir.pb(mp(1,-1));
	dir.pb(mp(1,1));

	cin >> n >> m;

	while(n + m != 0)
	{
		ptsMax = -1;
		pos1.clear();

		bool lin = true;
		for (int i = n - 1; i >= 0; --i)
		{
			bool put;
			for (int j = 0; j < m; ++j)
			{
				if(lin && j == 0)
				{
					put = true;
				}
				else if(!lin && j == 0)
					put = false;

				if(put)
				{
					cin >> mat[i][j];

					if(mat[i][j] == 1)
					{
						pos1.pb(mp(i, j));
					}

					put = false;
				}
				else
				{
					mat[i][j] = 0;

					put = true;
				}
			}
			lin = !lin;
		}

		TRACE(
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					cout << mat[i][j] << " ";
				}
				cout << endl;
			}
			);

		for (int i = 0; i < pos1.size(); ++i)
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					vis[i][j] = 0;
				}
			}

			dfs(pos1[i].fi, pos1[i].se, 0, mp(0, 0));
		}

		cout << ptsMax << endl;

		cin >> n >> m;
	}




	return 0;
}
