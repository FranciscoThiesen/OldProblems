#include <cstdio>
#include <vector>

int checkComposite(int n)
{
	if(n <= 2)
		return 1;
	if(n%2 == 0)
		return 0;
	int divisors = 0;
	for(int i = n - 1; i > 2;i--)
	{
		if(n%i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int x;
	scanf("%d", &x);
	if(x%2 == 0 && checkComposite(x/2) == 0)
	{
		printf("%d %d\n", x/2, x/2);
		return 0;
	}
	for(int i = 0; i < x; i++)
		for(int j = x; j > 0; j--)
		{
			if(j + i == x)
				if(checkComposite(j) == 0 && checkComposite(i) == 0)
				{
					printf("%d %d\n", i, j);
					return 0;
				}
		}
	return 0;

}