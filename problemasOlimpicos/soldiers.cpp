#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int size;
	scanf("%d", &size);
	int movs = 0;
	int movs2 = 0;
	int soldiers[size];
	for(int i = 0; i < size; i++)
		scanf("%d", &soldiers[i]);
	int max = 0;
	int maxpos;
	int min = 100;
	int minpos;
	for(int i = 0; i < size; ++i)
	{
		if(soldiers[i] > max)
		{
			max = soldiers[i];
			maxpos = i;
		}
		if(soldiers[i] <= min)
		{
			min = soldiers[i];
			minpos = i;
		}
	}
	if( maxpos < minpos)
	{
		movs += maxpos;
		movs += size - 1 - minpos;
		printf("%d\n", movs);
		return 0;
	}
	else
	{
		movs += maxpos;
		movs += size - minpos;
		printf("%d\n", movs - 2);
		return 0;
	}

}