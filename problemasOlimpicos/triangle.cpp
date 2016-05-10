#include <cstdio>

int triangleNumberGenerator(int n)
{
	int num = 0;
	for( int i = 0; i <= n; i++)
	{
		num += i;
	}
	return(num);
}

int checkDivisors(int n)
{
	int div = 1;
	for(int x = n/2 + 1; x > 1; x--)
	{
		if(n%x == 0)
			div++;
	}
	return(div);
}
int main()
{
	
	int i = 2;
	while(i > - 1)
	{
		if(triangleNumberGenerator(i)%2 == 0)
		{
			if(checkDivisors(triangleNumberGenerator(i)) > 500)
			{
				printf("%d\n", triangleNumberGenerator(i));
				i = -2;
				break;
			}
			printf("%d  %d\n", checkDivisors(triangleNumberGenerator(i)), triangleNumberGenerator(i));
		}
		i++;
	}
	return 0;

}