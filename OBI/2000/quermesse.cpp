#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int test = 1;
	while(cin >> n)
	{
		if(!n)
			break;
		int win;
		for(int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			if(x == i + 1)
				win = x;
		}
		printf("Teste %d\n%d\n\n", test, win);
		test++;
	}
	return 0;
}