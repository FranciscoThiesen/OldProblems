#include <cstdio>

int main()
{
	int x1, y1, x2, y2, x, y = 0;
	scanf("%d %d %d %d %d %d",&x1, &y1, &x2, &y2, &x, &y);
	if(x1 * y1 + x2 * y2 > x * y)
	{
		printf("S\n");
		return 0;

	}
	printf("N\n");
	return 0;
}