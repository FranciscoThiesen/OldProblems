#include <cstdio>

int main()
{
	int j, k, l, m, x;
	scanf("%d %d %d %d %d", &j, &k, &l, &m, &x);
	int dmgDragons = 0;
	for(int i = x; i >= 1; i--)
	{
		if(i%j == 0)
			dmgDragons++;
		else
		{
			if(i%k == 0)
				dmgDragons++;
			else
			{
				if(i%l == 0)
					dmgDragons++;
				else
				{
					if(i%m == 0)
						dmgDragons++;
				}
			}
		}
	}
	printf("%d\n", dmgDragons);
	return 0;
}