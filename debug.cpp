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
int DP[202][202];

int main()
{
	//std::ios::sync_with_stdio(false);
	int N, S, T;
	while(scanf("%d %d %d", &N, &S, &T) == 3)
	{
		T-=1;
		for(int j = 0; j < 202; ++j)
			for(int i = 0; i < 202; ++i)
				DP[i][j] = NEGINF;
		vector<int> vals;
		for(int i = 0; i < N; ++i) // Numero de casas no tabuleiro
		{
			int val;
			cin >> val;
			vals.pb(val);
		}
		for(int x = 0; x < N; ++x) // numeros de casas no tabuleiro
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
		for(int y = 0; y <= T; ++y)
		{
			for(int x = 0; x < S; ++x)
			{
				if(x < N)
					ans = max(ans, DP[x][y]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}