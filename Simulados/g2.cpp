#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#define pb push_back
#define mp make_pair
#define se second
#define fi first
using namespace std;

int main()
{
	int N;
	while(scanf("%d", &N) != EOF)
	{
		vector<pair<int, int> > v;
		for(int i = 0; i < N; i++)
		{
			int a, b;
			cin >> a >> b;
			v.pb(mp(a,b));
		}

		sort(v.begin(), v.end());
		long long ans = 0;
		ans = 1;
		int first = v[0].se;
		for(int i = 1; i < v.size(); ++i)
		{
			if(first >= v[i].fi && first <= v[i].se)
			{
				continue;
			}
			else
			{
				ans++;
				first = v[i].se;
			}
		}
		cout << ans << endl;
	}
	return 0;
}