#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int k, n, m;
	scanf("%d %d %d", &k, &n, &m);
	int total = 0;
	for(int i = 1; i <= m; i++)
		total += i*k;
	if(n > total)
		printf("%d\n", 0);
	else
		printf("%d\n", total - n);
	return 0;
}