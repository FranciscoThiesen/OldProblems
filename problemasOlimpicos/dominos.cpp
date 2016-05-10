#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
	float n, m = 0;
	scanf("%f %f", &n, &m);
	printf("%.0f\n", floor((n*m)/2));
	return 0;
}