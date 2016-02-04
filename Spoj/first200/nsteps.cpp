#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if(y%2 == 0)
		{
			if(x == y+2 || x == y)
				cout << x + y << endl;
			else
				cout << "No Number" << endl;
		}
		else
		{
			if(x == y+2 || x == y)
			{
				cout << x + y - 1 << endl;
			}
			else
				cout << "No Number" << endl;
		}
	}
	return 0;
}