#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int day = 0;
	for(int socks = n; socks > -1; socks--)
	{	
		if(socks == 0)
		{	
			printf("%d\n", day - 1);
			return 0;
		}
		printf("%d %d\n", socks, day);
		if(day%m == 0)
			socks++;
		day++;
	}


}