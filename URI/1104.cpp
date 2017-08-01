#include <bits/stdc++.h>

using namespace std;

int main()
{
	unordered_set<int> a;
	unordered_set<int> b;
	int n, m;
	while(scanf("%d %d", &n, &m) == 2)
	{
		if(!(n+m))
			break;
		for(int i = 0; i < n; ++i)
		{
			int x;
			scanf(" %d ", &x);
			a.insert(x);
		}
		for(int i = 0; i < m; ++i)
		{
			int y;
			scanf(" %d ", &y);
			b.insert(y);
		}
		int ans = 0;
		int ans2 = 0;
		for(auto& p : a)
		{
			if(b.find(p) == b.end())
				ans++;
		}
		for(auto& p : b)
		{
			if(a.find(p) == a.end())
				ans2++;
		}

	        printf("%d\n", min(ans, ans2));
	}
	return 0;
}