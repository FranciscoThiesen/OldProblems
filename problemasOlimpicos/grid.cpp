#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int intersections = n*m;
	int x = n;
	int y = m;
	int plays = 0;
	while(true)
	{
		plays++;
		intersections -= (x + y - 1); 
		x--;
		y--;
		if(intersections<= 0)
		{
			if(plays%2 == 0)
			{
				printf("Malkiva\n");
				return 0;
			}
			else
			{
				printf("Akshat\n");
				return 0;
			}
		}

	}
}