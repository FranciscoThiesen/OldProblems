#include <vector>
#include <algorithm>
#include <cstdio>

int main()
{
	int x, y;
	scanf("%d %d",&x, &y);
	int a1, b1, a2, b2;
	scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
	if(a1 + b1 < x)
		if(a2 < y && b2 < y)
		{
			printf("S3\n");
			return 0;
		}	
	if(a1 + b2 < x)
		if(b2 < y && a2 < y)
		{	
			printf("S2\n%d", a2);
			return 0;
		}	
	if(a2 + b1 < x)
		if(b2 < y && a1 < y)
		{
			printf("S1\n");
			return 0;
		}

	printf("N\n");
	return 1;
}