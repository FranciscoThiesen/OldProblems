#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
// ta um lixo, refazer essa bagaca
int main()
{
	int m, n = 1;
	while(m != 0 && n != 0)
	{
		scanf("%d %d", &m, &n);
		int num[m];
		int avg[int(ceil(m/n))];
		for(int i = 0; i < m; i++)
		{
			scanf("%d", &num[i]);
		}
		for(int j = 0, k = 0; j < m; j++)
		{
			while(k < int(ceil(m/n)))
			{
				int counter = 0;
				int sum = 0;
				if(counter < int(ceil(m/n)))
				{
					sum += num[j];
					counter++;
				}	
				if(counter == n)
				{
					avg[k] = sum;
					counter = 0;
					k++;
				}
				if(m - n < n && k == int(ceil(m/n)) - 1)
					j = m - n; 
			}	
		}
		for( int p = 0; p < int(ceil(m/n)); p++)
		{
			printf("%d %d", avg[p], avg[p + 1]);	
		}
	}

	



	return 0;



}