#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

int main()
{
	int a;
	while(scanf("%d", &a) != EOF)
	{
		vector<pair<int, int> > sapatos;
		long long ans = 0;
		for(int i = 0; i < 61; ++i)
			sapatos.push_back(make_pair(0,0));
		for(int j = 0; j < a; ++j)
		{
			int n;
			char c;
			cin >> n >> c;
			if(c == 'E')
				sapatos[n].first += 1;
			else
				sapatos[n].second += 1;
		}
		for(auto& p : sapatos)
			ans += min(p.first, p.second);
		cout << ans << endl;
	}
	return 0;
}