#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <string>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define NEGINF -1000000000
int DP[500][500];

int main()
{
	std::ios::sync_with_stdio(false);
	int N, S, T;
	while(scanf("%d %d %d", &N, &S, &T) == 3)
	{
		T-=1;
		for(int j = 0; j < 500; ++j)
			for(int i = 0; i < 500; ++i)
				DP[i][j] = NEGINF;
		vector<int> vals;
		for(int i = 0; i < N; ++i)
		{
			int val;
			cin >> val;
			vals.pb(val);
		}
		for(int x = 0; x < N; ++x)
		{
			if(N-x <= S)
				DP[x][0] = vals[x];
		}
		for(int y = 1; y < T; ++y)
		{
			for(int x = 0; x < N; ++x)
			{
				for(int inc = 1; inc <= S; ++inc)
				{
					if(x+inc < N)
					{
						if(DP[x+inc][y-1] != NEGINF)
						{
							DP[x][y] = max(DP[x][y], DP[x+inc][y-1] + vals[x]);
						}
					}
				}
			}
		}
		int ans = NEGINF;
		for(int y = 0; y < T; ++y)
		{
			for(int x = 0; x < S; ++x)
			{
				ans = max(ans, DP[x][y]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}