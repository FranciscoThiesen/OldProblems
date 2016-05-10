#include <cstdio>




int main()
{
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	int info[600];
	int sum = 0;
	for( int i = 0; i < 600; i++)
	{
		if( x <= i  && i <= x + 200)
			info[i] = 0;
		if( y <= i  && i <= y + 200)
			info[i] = 0;
		if( z <= i && i <= z + 200)
			info[i] = 0;
		else
			info[i] = 1;
	}
	for( int j = 0; j <= 600; j++)
	{
		if(info[j] == 0)
			sum++;

	}
	
	printf("%d\n",(((600 - (sum - 1))* 100)));
	return 0;

}