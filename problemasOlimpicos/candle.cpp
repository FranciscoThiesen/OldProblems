#include <cstdio>
#include <cmath>

using namespace std;
int main()
{
	int n, m;
	scanf("%d %d", &n ,&m);
	int hours = n;
	int remaining = n;
	while(true)
	{
		if(remaining < m)
		{
			printf("%d\n", hours);
			return 0;
		}
		hours += (remaining/m);
		remaining = (remaining/m) + remaining - floor(remaining/m)*m;
	}
	return 0;
}