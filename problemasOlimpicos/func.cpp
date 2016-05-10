#include <cstdio>
#include <cmath>

int main()
{
	long long int x;
	scanf("%lld", &x);
	long long int total = -1;
	long long int famb = 2;
	if( x%2 == 0)
		total = x/2;
	else
		total = ceil((total - x)/famb);
	printf("%lld\n", total);
	return 0;
}