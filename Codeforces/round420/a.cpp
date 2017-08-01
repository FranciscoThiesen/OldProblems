/*input
3
1 5 2
1 1 1
1 2 3
*/
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define fr(i,a,b)for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)

const int maxn = 50;

int mat[maxn][maxn] = {0};

int main()
{
	int t;
	scanf("%d", &t);
	rp(i, t)
		rp(j, t)
			scanf("%d", &mat[i][j]);

	bool ok = true;
	rp(i, t)
	{
		rp(j, t)
		{
			bool tmp = false;
			if(mat[i][j] == 1) continue;
			
			else
			{
				unordered_set<int> lin;
				unordered_set<int> col;
				rp(k, t)
				{
					if(k != i)
						col.insert(mat[k][j]);
					if(k != j)
						lin.insert(mat[i][k]);
				}
				for(auto p : col)
				{
					int need = mat[i][j] - p;
					if(lin.find(need) != lin.end()){
						tmp = true;
						break;
					}
				}
				if(!tmp)
				{
					ok = false;
					goto END;
				}
			}
		}
	}

END:
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}