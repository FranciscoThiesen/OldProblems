#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define ins insert
#define pb push_back
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i, n) fr(i,0,n)
#define mp make_pair
#define INF 0x3F3F3F3F

int n, m;
char mat[1010][1010];
int dis[1010][1010];

int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

bool valid(int i, int j)
{
	return (i >= 0 && i < n && j >= 0 && j < m);
}

bool floodFill(int i, int j)
{
	queue<pair<int, int>> q;
	q.push(mp(i, j));

	while(!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		int i = p.fi, j = p.se;
		for(int k = 0; k < 4; k++)
		{
			int nextI = i + dir[k][0];
			int nextJ = j + dir[k][1];
			if(valid(nextI, nextJ) && mat[nextI][nextJ] != '#' && dis[nextI][nextJ] == INF)
			{
				dis[nextI][nextJ] = dis[i][j] + 1;
				q.push(mp(nextI, nextJ));
			}
		}
	}
}

int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{
		int iniI, iniJ;
		cin >> n >> m;
		memset(dis, INF, sizeof(dis));
		rp(i, n)
		{
			rp(j, m)
			{
				char c;
				cin >> c;
				if(c == 'E')
				{
					iniI = i;
					iniJ = j;
				}
				mat[i][j] = c;
			}
		}

		dis[iniI][iniJ] = 0;
		floodFill(iniI, iniJ);
		int minFogo = INF;
		int pes = INF;
		rp(i, n)
		{
			rp(j, m)
			{
				if(mat[i][j] == 'F')
					minFogo = min(minFogo, dis[i][j]);
				else if(mat[i][j] == 'S')
					pes = dis[i][j];
			}
		}
		if(pes < minFogo)
			cout << 'Y' << endl;
		else
			cout << 'N' << endl;
	}

	return 0;
}
