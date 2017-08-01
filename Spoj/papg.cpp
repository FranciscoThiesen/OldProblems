#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	int a,b,c = 1;
	while(a != 0 || b + c != 0)
	{
		scanf("%d%d%d", &a, &b, &c);
		if(a == 0 && b == 0)
			return 0;
		int r;
		int f = 0;
		if(c - b == b - a)
		{
			r = b-a;
			f = 1;
		}
		else
		{
			r = b/a;
			f = 0;
		}
		if(f == 0)
			cout << "GP " << c * r << endl;
		else
			cout << "AP " << c + r << endl;
	}
	return 0;
}