#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int rooms = 0;
	for(int i = 0; i < n; i++)
	{
		int a, b = 0;
		scanf("%d %d", &a, &b);
		if(b-a >= 2)
			rooms++;
	}
	printf("%d\n", rooms);
	return 0;
}