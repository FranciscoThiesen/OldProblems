#include <stdio.h>
#include <stdlib.h>
 
long long c[100];
 
void coef(long long n)
{
	long long i, j;
 
	if (n < 0 || n > 63) abort(); // gracefully deal with range issue
 
	for (c[i=0] = 1; i < n; c[0] = -c[0], i++)
		for (c[1 + (j=i)] = 1; j > 0; j--)
			c[j] = c[j-1] - c[j];
}
 
long long is_prime(long long n)
{
	long long i;
 
	coef(n);
	c[0] += 1, c[i=n] -= 1;
	while (i-- && !(c[i] % n));
 
	return i < 0;
}
 
void show(int n)
{
	do printf("%+lldx^%d", c[n], n); while (n--);
}
 
int main(void)
{
	int n;
 	ll n;
 	while(scanf("%lld", &n) != EOF)
 	{

 	}
 
	printf("\nprimes (never mind the 1):");
	for (n = 1; n <= 63; n++)
		if (is_prime(n))
			printf(" %d", n);
 
	putchar('\n');
	return 0;
}