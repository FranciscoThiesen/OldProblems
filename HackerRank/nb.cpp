#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool isLeap(int y)
{
	cout << y << " " << y%4 << " " << y%100 << endl;
	if(y <= 1917)
		if(!(y%4))
			return true;
	else if(y > 1918)
		if(y%400 == 0 || (y%4 == 0 && y%100 != 0))
			return true;
	return false;
}

void solve(int y)
{
	if(y == 1918)
	{
		printf("26.09.1918\n");
	}
	else if(isLeap(y))
	{
		printf("12.09.%d\n", y);
	}
	else
	{
		printf("13.09.%d\n", y);
	}
}

int main()
{
	int x;
	cin >> x;
	solve(x);
	return 0;
}