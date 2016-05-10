#include <stdio.h>
#include <math.h>

int main()
{
	double n, m, a = 0;
	scanf("%lf %lf %lf", &n, &m, &a);
	printf("%.0f\n", ceil(n/a) * ceil(m/a));
	return 0;
}