#include <cstdio>

int main()
{
	int x;
	scanf("%d", &x);
	int d = 0;
	if(x%4 == 0 || x%7 == 0)
	{
		printf("YES\n");
		return 0;
	}
	if(x%47 == 0 || x%74 == 0)
	{
		printf("YES\n");
		return 0;
	}
	if(x%474 == 0 || x%477 == 0)
	{
		printf("YES\n");
		return 0;
	}
	if(x%447 == 0 || x%744 == 0)
	{
		printf("YES\n");
		return 0;
	}
	if(x%747 == 0 || x%777 == 0)
	{
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;	
}