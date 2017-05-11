#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int root;
		scanf("%d", &root);
		int n, e;
		scanf("%d %d" , &n, &e);
		set<pair<int, int> > ar;
		for(int i = 0; i < e; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			ar.insert(make_pair(min(x,y), max(x,y)));
		}
		printf("%d\n", (int)ar.size() * 2);
	}
	return 0;
}