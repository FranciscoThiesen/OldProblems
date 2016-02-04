#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long int squares[100];

int counter = 2;

int main()
{
	squares[0] = 1;
	for(int i = 1; i < 100; i++)
	{
		squares[i] = squares[i-1] + counter*counter;
		counter++;
	}
	int a = 1;
	while(a != 0)
	{
		scanf("%d", &a);
		if(a == 0)
			return 0;
		cout << squares[a-1] << endl;
	}
	return 0;
}