#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	int test = 1;
	while(cin >> t)
	{
		if(!t)
			break;
		vector<int> saldo;
		for(int i = 0; i < t; ++i)
		{
			int x, y;
			cin >> x >> y;
			saldo.push_back(x-y);
		}
		int beg = 0;
		int end = 0;
		int bestBeg = 0;
		int bestEnd = 0;
		int best = saldo[0];
		int cur = saldo[0];
		for(int i = 1; i < t; ++i)
		{
			if(cur < 0)
			{
				cur = saldo[i];
				beg = i;
				end = i;
			}
			else 
			{
				cur += saldo[i];
				end = i;
			}
			if(cur >= best)
			{
				bestBeg = beg;
				bestEnd = end;
				best = cur;
			}
		}
		if(best > 0)
			printf("Teste %d\n%d %d\n\n", test, bestBeg + 1, bestEnd + 1);
		else
			printf("Teste %d\nnenhum\n\n", test);
		test++;
	}
	return 0;
}