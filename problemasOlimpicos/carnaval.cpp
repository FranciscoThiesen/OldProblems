#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
	float sum = 0;
	float smaller = 10.0, higher = 5.0;
	for(int i = 0; i < 5; i++)
	{	
		float a;
		scanf("%f", &a);
		sum += a;
		if( a > higher)
			higher = a;
		if( a < smaller)
			smaller = a;
	}
	sum = sum - smaller;
	sum = sum - higher;	
	printf("%.1f\n", sum);
	return 0;
}