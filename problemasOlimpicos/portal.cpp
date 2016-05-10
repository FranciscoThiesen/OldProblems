#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int x,y;
	scanf("%d %d", &x, &y);
	for(int i = 1; i <= x ;i++)
	{
		int a;
		std::cin >> a;
		if(a+i == y  && a >= 1)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}