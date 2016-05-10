#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	float a, b;
	scanf("%f %f", &a, &b);
	float hours = a;
	float up = a;
	while( up > 0)
	{
		up = floor(up/b);
		hours += up;
	}
	printf("%.0f\n", hours);
	return 0;
}