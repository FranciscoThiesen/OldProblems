#include <bits/stdc++.h>

using namespace std;

int main()
{
	int b, n;
	while(scanf("%d %d", &b, &n) == 2)
	{
		if(b + n == 0)
			break;
		vector<int> banco(b, 0);
		for(int i = 0; i < b; ++i)
		{
			int x;
			scanf(" %d ", &x);
			banco[i] = x;
		}
		for(int q = 0; q < n; ++q)
		{
			int i, j, k;
			scanf(" %d %d %d", &i, &j, &k);
			banco[i-1] -= k;
			banco[j-1] += k;
		}
		bool ok = true;
		for(auto& p : banco)
		{
		 	if(p < 0)
			{
				ok = false;
				break;
			}
		}
		if(ok)
			printf("S\n");
		else
			printf("N\n");
	}
	return 0;		

}