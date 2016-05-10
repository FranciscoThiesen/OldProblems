#include <cstdio>

bool checkPrime(int x)
{
	int divisors = 1;
	for( int i = x - 1; i > 1; i--)
	{
		if(x%2 == 0)
		{
			return false;
		}
	}
	return true;

}

int main()
{
	int n;
	scanf("%d", &n);
	if(n%2 == 0)
	{
		printf("%d %d", n/2, n/2);
		printf("eh par %d %d", n/2, n/2);
		return 0;
	}
	else
	{
		if(n/2 + n/2 < n)
		{
			int a = n/2 + 1;
			int b = n/2;
			while( a != 0)
			{

				if(checkPrime(a) == false && checkPrime(b) == false)
				{
					printf("%d %d", a, b);
					return 0;
				}
				a--;
				b++;
			}
		}
		else
		{
			int a = n/2;
			int b = n/2 - 1;
			while( a != 0)
			{

				if(checkPrime(a) == false && checkPrime(b) == false)
				{
					printf("%d %d", a, b);
					return 0;
				}
				a--;
				b++;

			}	
		}
	}	
	
	//printf("%s\n", checkPrime(2) ? "true" : "false");
	//printf("%b %b %b", checkPrime(1), checkPrime(2), checkPrime(7));

}