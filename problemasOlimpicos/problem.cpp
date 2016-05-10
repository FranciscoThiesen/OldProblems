#include <cstdio>
#include <vector>

int main()
{
	int n;
	scanf("%d", &n);
	int problems = 0;
	for(int i = 0; i < n; i++)
	{
		int x, y, z = 0;
		scanf("%d %d %d", &x, &y, &z);
		if(x + y + z >= 2)
			problems++;
	}
	printf("%d\n", problems);


}