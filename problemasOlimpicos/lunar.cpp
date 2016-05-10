#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
int avg(int a)
{
	int x, y;
	int sum = 0;
	int higher = 0;
	int lower = 0;
	scanf("%d %d", &x, &y);
	vector<int> nums(x);
	if( x <= 1 || y <= 0)
		return 0;
	for( int i = 0; i < x; i++)
	{
		scanf("%d", &nums[i]);
	}
	for(int j = 0; j < x; j++)
	{
		
		if(j <= y - 1)
		{
			sum += nums[j];
			if(j == y - 1)
			{
				higher = sum;
				lower = sum;
			}
		}
		else
		{
			sum -= nums[j- y];
			sum += nums[j];
			if(sum > higher)
				higher = sum;
			if(sum < lower)
				lower = sum;
		}
	}
	printf("Teste %d\n%d %d\n", a, lower/y, higher/y);
	return 1;
}

int main()
{
	for( int i = 1; i > -1; i++)
	{	
		if(avg(i) == 0)
			return 0;

	}
	return 0;






}