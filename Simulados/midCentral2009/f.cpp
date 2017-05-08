#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
#define pb push_back

int ppRock(char a, char b)
{
	if(a == 'P')
	{
		if(b == 'P')
			return 0;
		if(b == 'R')
			return 1;
		else
			return 2;
	}
	else if(a == 'R')
	{
		if(b == 'R')
			return 0;
		if(b == 'S')
			return 1;
		else
			return 2;
	}
	else if(a == 'S')
	{
		if(b == 'S')
			return 0;
		if(b == 'P')
			return 1;
		else
			return 2;
	}

}

int main()
{
	string a, b;
	while(true)
	{
		cin >> a >> b;
		if(a[0] == 'E' && b[0] == 'E')
			break;
		int p1 = 0;
		int p2 = 0;
		for(int i = 0; i < a.size(); ++i)
		{
			if(ppRock(a[i], b[i]) == 2)
				p2++;
			else if(ppRock(a[i], b[i]) == 1)
				p1++;
		}
		cout << "P1: " << p1 << endl << "P2: " << p2 << endl;

	}
	return 0;
}