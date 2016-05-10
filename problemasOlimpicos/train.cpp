#include <cstdio>

int main()
{
	int stations;
	scanf("%d", &stations);
	int maxCapacity = 0;
	int passengers = 0;
	for(int i = 0; i < stations; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		passengers += (b - a);
		if( passengers > maxCapacity)
			maxCapacity = passengers;
	}

	printf("%d\n", maxCapacity);
	return 0;


}