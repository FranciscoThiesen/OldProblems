#include <cstdio>

int main()
{
	int tests;
	scanf("%d", &tests);
	for(int i = 0; i < tests; i++)
	{
		int studs, min;
		scanf("%d %d", &studs, &min);
		int late = 0;
		for(int j = 0; j < studs; j++)
		{
			int a;
			scanf("%d", &a);
			if(a > 0)
				late++;
			if(late > studs - min)
				break;
		}
		if(late > studs - min)
			printf("YES\n", late);
		else
			printf("NO\n", late);	

	}
	return 0;
}