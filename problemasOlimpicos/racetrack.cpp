#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	unsigned long long int x,y,z;
	cin >> x;
	cin >> y;
	cin >> z;
	unsigned long long int cases = 0;
	long long p = 1;
	if( y == z)
	{
		cout << "1/1" << endl;
		return 0;
	}
	while(p < x)
	{
		if(p < y && p < z)
		{
			cases++;
			p++;
		}
		if(p%y == 0 && p%z == 0)
		{
			cases++;
			p++;
		}
		if(p%y == p%z)
		{
			cases++;
			p++;
		}
		else
			p++;

	}
	for(unsigned long long i = cases; i > 0; i--)
	{
		if(x%i == 0 && cases%i == 0)
		{
			x = x/i;
			cases = cases/i;
		}
	}
	cout << cases << "/" << x << endl;
	return 0;
}