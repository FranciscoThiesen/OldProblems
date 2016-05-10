#include <cstdio>

int main()
{
	int x;
	int total = 0;
	scanf("%d", &x);
	int home[x];
	int away[x];
	for(int i = 0; i < x; ++i)
		scanf("%d %d", &home[i], &away[i]);

	for(int j = 0; j < x; ++j)
		for(int k = 0; k < x;++k)
			if(home[j] == away[k])
				total++;
	
	printf("%d\n",total);
	return 0;

}