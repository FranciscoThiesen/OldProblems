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

vector<vector<int> > AdjList(200);
vector<int> ts;
int main()
{
	int n = 1, m = 1;
	while(n + m != 0)
	{
		scanf("%d %d", &n, &m);
		if(n+m == 0)
			break;
		unordered_map<string, int> materias;
		int pos = 0;
		for(int i = 0; i < n; ++i)
		{
			string fst;
			int dep;
			cin >> fst >> dep;
			if(materias.find(fst) == materias.end())
				materias.insert(mp(fst, pos));pos++;
			for(int j = 0; j < dep; ++j)
			{
				string mat;
				cin >> mat;
				if(materias.find(mat) == materias.end())
				{
					materias.insert(mp(mat, pos));
					pos++;
				}
				AdjList[materias[mat]].pb(materias[fst]);
			}
		}
	}
}