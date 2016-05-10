#include <cstdio>

int main()
{
	int x;
	scanf("%d", &x);
	int givers[x];
	int receivers[x];
	for(int i = 0; i < x; i++)
		scanf("%d", &givers[i]);
	int o = 0;
	for(int j = 1; j < x + 1; j++)
		for(int k = 0; k < x; k++)
		{
			if(givers[k] == j)
			{
				receivers[o] = k + 1;
				o++;
			}
		}

	for(int z = 0; z < x; z++)
	{
		if(z == x - 1)
			printf("%d\n", receivers[z]);
		else
			printf("%d ", receivers[z]);
	}
	return 0;
}