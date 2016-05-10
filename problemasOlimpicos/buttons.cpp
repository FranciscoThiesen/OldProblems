#include <cstdio>

int main()
{
	int x;
	scanf("%d\n", &x);
	if(x == 2)
	{
		printf("3");
		return 0;
	}
	else
		printf("%d\n", (x*(x+1)) - (x+2));
	return 0;
}