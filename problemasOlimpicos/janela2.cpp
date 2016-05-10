#include <cstdio>
//funcionando
int main()
{
	
	int x, y, z = 0;
	int sum = 0;
	scanf("%d %d %d", &x, &y, &z);
	int base[6] = { x, x + 200, y, y + 200, z, z + 200};
	if( z - x < 200)
	{
		int specialCase = (z + 200) - x;
		printf("%d\n", ((600 - specialCase) * 100));
		return 0;
	}
	if( y - x <= 200)
		sum += base[3] - base[0];
	if( y - x > 200)
		sum += 200;
	
	if( z - y <= 200)
		sum += base[5] - y;
	if( z - y > 200)
		sum += 200;
	if( x == y && y == z)
		sum -= 200;
	
	if( x + y + z == 600)
		sum = 600;

	printf("%d\n", ((600 - sum) * 100));
	return 0;
}