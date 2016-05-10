#include <cstdio>

using namespace std;
int main()
{
	int x; 
	scanf("%d", &x);
	int groups = 1;
	int prevmagn;
	scanf("%d", &prevmagn);
	for(int i = 1; i < x; i++)
	{
		int magn;
		scanf("%d", &magn);
		if(magn != prevmagn)
		{
			groups++;
			prevmagn = magn;
		}
	}
	printf("%d\n", groups);
	return 0;
}