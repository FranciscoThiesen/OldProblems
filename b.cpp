//Francisco Thiesen Solution
/*
	Number of testcases: At most 100
	Maximum n per testcase : 100
	Worst Complexity per testcase : O(n^3) = O(10^6)
	Maximum complexity summing all testCases : O(10^8)
*/
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef unsigned long long ull;
int dist[101][101];

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const int NULO = -1; const double EPS = 1e-10;

void init(int n)
{
	memset(dist, INF, sizeof dist);
	for(int i = 0; i < n; ++i)
	{
		dist[i][i] = 0;
	}
}

ull findMaxSum(vector<long long>& vec)
{
	ull incl = vec[0];
	ull excl = 0;
	ull excl_new;
	int n = vec.size();
	for(int i = 1; i < n; ++i)
	{
		excl_new = (incl > excl) ? incl : excl;
		incl = excl + vec[i];
		excl = excl_new;
	}
	return ((incl > excl)? incl : excl);
}

int main()
{
	ifstream in;
	in.open("in.txt");
	ofstream out;
	out.open("out.txt");
	int t;
	in >> t;
	for(int test = 0; test < t; ++test)
	{
		int n, m, k, x, y, z;
		in >> n >> m >> k;
		init(n);
		// reading edges
		for(int i = 0; i < m; ++i)
		{
			in >> x >> y >> z;
			dist[x-1][y-1] = min(dist[x-1][y-1], z);
			dist[y-1][x-1] = min(dist[y-1][x-1], z);
		}
		//Floyd-Warshall step
		for(int z = 0; z < n; ++z)
		{
			for(int x = 0; x < n; ++x)
			{
				for(int y = 0; y < n; ++y)
				{
					if(dist[x][z] != INF && dist[z][y] != INF)
						dist[x][y] = min(dist[x][y], dist[x][z] + dist[z][y]);
				}
			}
		}

		//reading moves
		vector<pair<int, int> > moves(k);
		for(int i = 0; i < k; ++i)
		{
			in >> x >> y;
			moves[i] = mp(x-1,y-1);
		}
		//building vector of gain by grouping deliver i and i-1
		//It is not possible to choose two adjacent items
		vector<long long> gain(k);
		gain[0] = 0;
		bool possible = true;
		for(int i = 1; i < k; ++i)
		{
			long long p1 = dist[moves[i-1].fi][moves[i].fi] + dist[moves[i].fi][moves[i-1].se] + dist[moves[i-1].se][moves[i].se];
			long long p2 = dist[moves[i-1].fi][moves[i-1].se] + dist[moves[i-1].se][moves[i].fi] + dist[moves[i].fi][moves[i].se];
			if(p1 >= INF && p2 >= INF)
			{
				possible = false;
				break;
			}
			gain[i] = max(p2 - p1,(long long) 0);
			out << gain[i] << " ";
		}
		if(possible)
		{	
			int start = 0;
			ull worstDist = 0;
			for(int i = 0; i < k; ++i)
			{
				worstDist += dist[start][moves[i].fi] + dist[moves[i].fi][moves[i].se];
				start = moves[i].se;
			}
			out << "Case #" << test+1 << ": " << worstDist - findMaxSum(gain) << endl;
		}
		else
			out << "Case #" << test+1<< ": " << -1 << endl;
	}
	in.close();
	out.close();
	return 0;
}