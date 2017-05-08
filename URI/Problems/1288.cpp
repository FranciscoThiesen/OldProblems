#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		cin >> n;
		vector<pair<int, int> > balas;
		for(int i = 0; i < n; ++i)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			balas.pb(mp(a,b));
		}
		int money;
		cin >> money;
		int res;
		cin >> res;
		int DP[101][51] = {{0}};
		for(int y = 1; y <= balas.size(); ++y)
		{
			for(int x = 1; x <= 100; ++x)
			{
				if(balas[y-1].second <= x)
					DP[x][y] = max(DP[x][y-1], DP[x-balas[y-1].second][y-1] + balas[y-1].first);
				else
					DP[x][y] = DP[x][y-1];
			}
		}
		if(DP[money][balas.size()] >= res)
			cout << "Missao completada com sucesso" << endl;
		else
			cout << "Falha na missao" << endl;
	}
	return 0;
}