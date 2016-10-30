#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c, d;
	while(scanf("%d %d %d %d", &a, &b, &c, &d) == 4)
	{
		if(!(a+b+c+d))
		{
			return 0;
		}
		int h1 = a*60 + b;
		int h2 = c*60 + d;
		if(h2 > h1)
			printf("%d\n", h2-h1);
		else
			printf("%d\n", (1440-h1) + h2);
	}
	return 0;
}