#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n,m,a,b;
	scanf("%d %d %d %d", &n, &m, &a, &b);
	int total = 0;
	while(n > 0)
	{
		if(n >= m)
		{
			if(b/m < a)
			{
				total += b;
				n -= m;
			}
			else
			{
				total += a;
				n--;
			}

		}
		if(n < m)
		{
			if(a < b)
			{
				total += a;
				n--;
			}
			else
			{
				total += b;
				n -= m;
			}
		}
	}
	cout << total << endl;
	return 0;
}