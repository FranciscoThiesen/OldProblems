#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>

int main()
{
	int m, n = 0;
	scanf("%d %d", &m, &n);
	int a[m];
	int b[n];
	for( int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	for( int j = 0; j < n; j++)
		scanf("%d", &b[j]);
	
	for( int k = 0; k < n; k++)
	{
		bool v = false;
		for(int y = 0; y < m; y++)
		{
			if(b[k] == a[y])
			{
				v = true;
				break;
			}
		}
		if(v == false)
		{
			if( k == 1)
				return 0;
			for( int z = 0; z <= k - 1; z++)
			{
				for(int p = 0; p <= k - 1; p++)
				{
					if(b[k] == b[z] + b[p])
					{
						v = true;
						break;
					}
				}
				if(v == true)
					break;
			}
			if(v == false)
			{
				printf("%d\n", b[k]);
				return 1;
				break;
			}
		}

	}
	printf("sim\n");
	return 0; 
}