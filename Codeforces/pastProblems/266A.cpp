#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	float n,m,a,b;
	scanf("%f %f %f %f", &n, &m, &a, &b);
	int total = 0;
	while(n > 0)
	{
		if(n >= m)
		{
			if(b/m < a)
			{
				total += b;
				n -= m;
                                continue;
			}
			else
			{
				total += a;
				n -= 1;
                                continue;
			}

		}

		if(n <= m)
		{
			if(n*a < b)
			{
				total+= a;
				n--;
                                continue;
			}
			else
			{
				total += b;
				n -= m;
                                continue;
			}
		}
	}
	cout << total << endl;
	return 0;
}
